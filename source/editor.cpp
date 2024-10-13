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
            for (int j = 0; j < width; ++j) {
                Pixel pixel;
                input >> pixel.r >> pixel.g >> pixel.b;
                img.push_back(pixel);
            }
        }
    }
    
    input.close();
}

void Editor::write_img() {
    ofstream output("imgs/nova-img.ppm");

    if (!output) {
        cout << "ERRO: Cannot create new file!" << endl;

    } else {        
        output << format << "\n";
        output << width << " " << height << "\n";
        output << rgb_max << "\n";

        for (int i = 0; i < height*width; ++i) {
            output << img[i].r << " " << img[i].g << " " << img[i].b << " ";
        }

        cout << "Imagem salva como: 'nova-img.ppm' em 'imgs'." << endl;
        output.close();

    }        
}