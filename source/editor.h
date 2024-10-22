#ifndef EDITOR_H
#define EDITOR_H

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Editor {
    private:
        struct Pixel {
            int r, g, b; //Componentes rgb
        };

        string format;
        string rgb_max;
        int height;
        int width;
        string m_operation;
        vector <vector <Pixel>> img;
        vector <vector <Pixel>> new_img;

        /** Muda a corda imagem para escala de cinza
         *  Cinza = (r + g + b)/3 de um pixel.
         *  Os valores rgb recebem cinza.
         */
        void gray();

        /** Aumenta o tamanho da imagem 2x
         *  O novo pixel é a média dos valores rgb dos vizinhos.
         */ 
        void enlarge();

        // Reduz o tamanho da imagem 2x
        void reduce();

        //rotate
        void rotate();

        //sharp
        void sharp();

        //blur
        void blur();

    public:

        //validar operação
        void validate_operation(string operation);

        //leitura do arquivo: img e operação
        void read_img(string file);

        //escrita do arquivo
        void write_img();
};

#endif