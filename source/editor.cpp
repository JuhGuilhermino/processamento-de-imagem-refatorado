/**
 * \file main.cpp
 * \author Júlia Guilhermino (juh,guilhermino03@gmail.com)
 * \brief Arquivo contendo a implementação dos métodos da classe Editor
 *        declarada em edtor.h
 * \version 2.1
 * \date 2024-10-23
 * 
 * \copyright Copyright (c) 2024
 * 
 */

#include "editor.h"

/*!
 * @brief Valida a operação fornecida.
 * 
 * Verifica se a operação fornecida é válida. Se for inválida, exibe uma mensagem de erro.
 * 
 * @param operation A operação a ser validada (ex.: "gray", "enlarge").
 */
void Editor::validate_operation(string operation) {
    if (operation != "gray" && operation != "enlarge" && 
        operation != "reduce" && operation != "rotate" && 
        operation != "sharp" && operation != "blur") {
        cout << "ERROR: invalid operation." << endl;
    } else {
        m_operation = operation;
    }
}

/*!
 * @brief Lê a imagem e seu cabeçalho a partir de um arquivo.
 * 
 * Abre o arquivo fornecido e armazena os pixels na matriz \a img.
 * 
 * @param file O caminho do arquivo contendo a imagem.
 */
void Editor::read_img(string file) {
    ifstream input(file, ios::in);

    if (!input) {
        cout << "Cannot read this file!" << endl;
    } else {
        input >> format >> width >> height >> rgb_max;

        for (int i = 0; i < height; ++i) {
            vector<Pixel> line;
            for (int j = 0; j < width; ++j) {
                Pixel pixel;
                input >> pixel.r >> pixel.g >> pixel.b;
                line.push_back(pixel);
            }
            img.push_back(line);
        }
    }
    input.close();
}

/*!
 * @brief Converte a imagem para escala de cinza.
 */
void Editor::gray() {
    for (int i = 0; i < height; ++i) {
        vector<Pixel> line;
        for (int j = 0; j < width; ++j) {
            int average = (img[i][j].r + img[i][j].g + img[i][j].b) / 3;
            Pixel pixel = {average, average, average};
            line.push_back(pixel);
        }
        new_img.push_back(line);
    }
}

/*!
 * @brief Aumenta o tamanho da imagem em 2x.
 */
void Editor::enlarge() {
    vector<vector<Pixel>> enlarge;

    for (int i = 0; i < height; ++i) {
        vector<Pixel> line;
        for (int j = 0; j < width - 1; ++j) {
            Pixel pixel = {
                (img[i][j].r + img[i][j + 1].r) / 2,
                (img[i][j].g + img[i][j + 1].g) / 2,
                (img[i][j].b + img[i][j + 1].b) / 2
            };
            line.push_back(img[i][j]);
            line.push_back(pixel);
        }
        line.push_back(img[i][width - 1]);
        enlarge.push_back(line);
    }

    width = width * 2 - 1;

    for (int i = 1; i < height; ++i) {
        vector<Pixel> line;
        for (int j = 0; j < width; ++j) {
            Pixel pixel = {
                (enlarge[i - 1][j].r + enlarge[i][j].r) / 2,
                (enlarge[i - 1][j].g + enlarge[i][j].g) / 2,
                (enlarge[i - 1][j].b + enlarge[i][j].b) / 2
            };
            line.push_back(pixel);
        }
        new_img.push_back(line);
        new_img.push_back(enlarge[i]);
    }
    height = height * 2 - 1;
}

/*!
 * @brief Reduz o tamanho da imagem em 2x.
 */
void Editor::reduce() {
    for (int i = 0; i < height - 1; i += 2) {
        vector<Pixel> line;
        for (int j = 0; j < width - 1; j += 2) {
            Pixel pixel = {
                (img[i][j].r + img[i + 1][j].r + img[i][j + 1].r + img[i + 1][j + 1].r) / 4,
                (img[i][j].g + img[i + 1][j].g + img[i][j + 1].g + img[i + 1][j + 1].g) / 4,
                (img[i][j].b + img[i + 1][j].b + img[i][j + 1].b + img[i + 1][j + 1].b) / 4
            };
            line.push_back(pixel);
        }
        new_img.push_back(line);
    }
    width = new_img[0].size();
    height = new_img.size();
}

/*!
 * @brief Rotaciona a imagem.
 */
void Editor::rotate() {
    for (int j = 0; j < width; ++j) {
        vector<Pixel> line;
        for (int i = 0; i < height; ++i) {
            line.push_back(img[i][j]);
        }
        new_img.push_back(line);
    }
    width = new_img[0].size();
    height = new_img.size();
}

/*!
 * @brief Aplica um filtro de nitidez à imagem.
 */
void Editor::sharp() {
    vector<vector<int>> sharp = {{0, -1, 0}, {-1, 5, -1}, {0, -1, 0}};
    for (int i = 1; i < height - 1; ++i) {
        vector<Pixel> line;
        for (int j = 1; j < width - 1; ++j) {
            int r = 0, g = 0, b = 0;
            for (int k = -1; k <= 1; ++k) {
                for (int l = -1; l <= 1; ++l) {
                    r += img[i + k][j + l].r * sharp[k + 1][l + 1];
                    g += img[i + k][j + l].g * sharp[k + 1][l + 1];
                    b += img[i + k][j + l].b * sharp[k + 1][l + 1];
                }
            }
            line.push_back({r, g, b});
        }
        new_img.push_back(line);
    }
}

/*!
 * @brief Aplica um filtro de desfoque à imagem.
 */
void Editor::blur() {
    for (int i = 1; i < height - 1; ++i) {
        vector<Pixel> line;
        for (int j = 1; j < width - 1; ++j) {
            int r = 0, g = 0, b = 0;
            for (int k = -1; k <= 1; ++k) {
                for (int l = -1; l <= 1; ++l) {
                    r += img[i + k][j + l].r / 9;
                    g += img[i + k][j + l].g / 9;
                    b += img[i + k][j + l].b / 9;
                }
            }
            line.push_back({r, g, b});
        }
        new_img.push_back(line);
    }
}

/*!
 * @brief Escreve a imagem processada em um novo arquivo.
 */
void Editor::write_img() {
    ofstream output("imgs/nova-img.ppm");
    if (!output) {
        cout << "ERRO: Cannot create new file!" << endl;
    } else {
        if (m_operation == "gray") gray();
        else if (m_operation == "enlarge") enlarge();
        else if (m_operation == "reduce") reduce();
        else if (m_operation == "rotate") rotate();
        else if (m_operation == "sharp") sharp();
        else blur();

        output << format << "\n" << width << " " << height << "\n" << rgb_max << "\n";
        for (const auto& row : new_img) {
            for (const auto& pixel : row) {
                output << pixel.r << " " << pixel.g << " " << pixel.b << " ";
            }
        }
        cout << "Imagem salva como: 'nova-img.ppm' em 'imgs'." << endl;
        output.close();
    }
}
