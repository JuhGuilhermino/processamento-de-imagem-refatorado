#include "editor.h"

void Editor::validate_operation(string operation) {
    if (operation != "gray" and operation != "enlarge" and operation != "reduce" and operation != "rotate" and operation != "sharp" and operation != "blur") {
        cout << "ERROR: invalid operation." << endl;
    } else {
        m_operation = operation;
    }
}

void Editor::read_img(string file) {
    ifstream input;
    input.open(file, ios::in);

    if (!input) {
        cout << "Cannot read this file!" << endl;
    } else {
        // Leitura do cabeçalho da imagem.
        input >> format >> width >> height >> rgb_max;

        // Leitura dos pixels (R, G, B)
        for (int i = 0; i < height; ++i) {
            vector <Pixel> line;
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

void Editor::gray(){
    for (int i = 0; i < height; i++) {
        vector <Pixel> line; //cria a linha da nova imagem

        for (int j = 0; j < width; j++) {
            //média dos valores rgb
            int average = (img[i][j].r + img[i][j].g + img[i][j].b)/3;
            Pixel pixel;
            pixel.r = average;
            pixel.g = average;
            pixel.b = average;

            line.push_back(pixel); //salva o pixel na nova linha
        }
        new_img.push_back(line);   //salva linha na nova imagem
    }
}

void Editor::enlarge(){
    vector <vector <Pixel>> enlarge;

    //Aumentar largagura
    for (int i = 0; i < height; i++) {
        vector <Pixel> line; //cria a linha da nova imagem com as colunas

        for (int j = 0; j < width-1; j++) {
            //novo pixel = média dos valores rgb de duas colunas consecutivas
            Pixel pixel;
            pixel.r = (img[i][j].r + img[i][j+1].r)/2;
            pixel.g = (img[i][j].g + img[i][j+1].g)/2;
            pixel.b = (img[i][j].b + img[i][j+1].b)/2;

            //Add pixels na linha
            line.push_back(img[i][j]); 
            line.push_back(pixel);
            if (j == width-2) { line.push_back(img[i][j+1]);  } 
        }

        enlarge.push_back(line);   //salva linha na nova imagem
    }

    width = width+width-1;

    //Aumenta altura
    for (int i = 1; i < height; i++) {
        vector <Pixel> line; //cria a linha da nova imagem com as colunas
        if (i == 1) { new_img.push_back(enlarge[i-1]);  } 
        
        // craindo nova linha 
        for (int j = 0; j < width; j++) {
            Pixel pixel;
            pixel.r = (enlarge[i-1][j].r + enlarge[i][j].r)/2;
            pixel.g = (enlarge[i-1][j].g + enlarge[i][j].g)/2;
            pixel.b = (enlarge[i-1][j].b + enlarge[i][j].b)/2;
            line.push_back(pixel); 
        }

        new_img.push_back(line);   //salva linha na nova imagem
        new_img.push_back(enlarge[i]);   //salva linha na nova imagem
    }

    height = height+height-1;
}

void Editor::reduce(){
    for (int i = 0; i < height-1; i+=2) {
        vector <Pixel> line; //cria a linha da nova imagem

        for (int j = 0; j < width-1; j+=2) {
            //média dos valores rgb
            Pixel pixel;
            pixel.r = (img[i][j].r + img[i+1][j].r + img[i][j+1].r + img[i+1][j+1].r)/4;
            pixel.g = (img[i][j].g + img[i+1][j].g + img[i][j+1].g + img[i+1][j+1].g)/4;
            pixel.b = (img[i][j].b + img[i+1][j].b + img[i][j+1].b + img[i+1][j+1].b)/4;

            line.push_back(pixel); //salva o pixel na nova linha
        }
        new_img.push_back(line);   //salva linha na nova imagem
    }

    width = new_img[0].size();
    height = new_img.size();
}

void Editor::rotate(){}

void Editor::sharp(){}

void Editor::blur(){}

void Editor::write_img() {
    ofstream output("imgs/nova-img.ppm");

    if (!output) {
        cout << "ERRO: Cannot create new file!" << endl;

    } else {        
        //Criação da nova imagem
        if (m_operation == "gray") {
            gray();
        } else if (m_operation == "enlarge") {
            enlarge();
        } else if (m_operation == "reduce") {
            reduce();
        } else if (m_operation == "rotate") {
            rotate();
        } else if (m_operation == "sharp") {
            sharp();
        } else {
            blur();
        }
        
        //Salvando o arquivo
        output << format << "\n";
        output << width << " " << height << "\n";
        output << rgb_max << "\n";
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                output << new_img[i][j].r << " " << new_img[i][j].g << " " << new_img[i][j].b << " ";
            }
        }

        cout << "Imagem salva como: 'nova-img.ppm' em 'imgs'." << endl;
        cout << "height: " << height << endl;
        cout << "widht: " << width << endl;
        output.close();

    }        
}