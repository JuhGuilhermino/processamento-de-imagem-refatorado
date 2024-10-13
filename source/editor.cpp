#include "editor.h"

void Editor::validate_operation(string operation){
    if (operation != "gray" and operation != "enlarge" and operation != "reduce" and operation != "rotate" and operation != "sharp" and operation != "blur"){
        cout << "ERROR: invalid operation." << endl;
    } else {
        m_operation = operation;
    }
}

void Editor::read_img(string file){
    ifstream input;
        input.open(file, ios::in);

        if (!input) {
            cout << "Cannot read this file!" << endl;
        } else {
            // Leitura do cabeçalho da imagem.
            input >> format >> width >> height >> rgb_max;
            
            cout << format << endl;
            cout << height << endl;
            cout << width << endl;
            cout << rgb_max << endl;

            // Leitura dos pixels (R, G, B)
            for (int i = 0; i < height; ++i) {
                for (int j = 0; j < width; ++j) {
                    Pixel pixel;
                    input >> pixel.r >> pixel.g >> pixel.b;
                    img.push_back(pixel);
                }
            }
        }
}

void Editor::write_img(){
    for (size_t i = 0; img.size() < 5; i++){
        cout << img[i].r << " " << img[i].g << " " << img[i].b << " ";
    }
            
}