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
        vector <Pixel> img;

        //gray

        //enlarge

        //reduce

        //rotate

        //sharp

        //blur

    public:

        //validar operação
        void validate_operation(string operation);

        //leitura do arquivo: img e operação
        void read_img(string file);

        //escrita do arquivo
        void write_img();
};

#endif