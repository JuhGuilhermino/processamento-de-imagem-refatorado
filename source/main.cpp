/**
 * @file main.cpp
 * @author Júlia Guilhermino (juh,guilhermino03@gmail.com)
 * @brief Arquivo com a classe principal do projeto
 * @version 2.1
 * @date 2024-10-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "editor.h"

/**
 * @brief Imprime uma mensagem explicando como o programa deve ser usado.
 * 
 * Esta função fornece instruções sobre como executar o programa, indicando as operações 
 * disponíveis e o formato esperado para os argumentos na linha de comando.
 * 
 * @param program_name Nome do arquivo executável (geralmente passado como `argv[0]`).
 */
void print_usage(string program_name) {
    cerr << "Usage: ./main [operation] <input_image_file>" << endl;
    cerr << "Where [operation] can be:" << endl;
    cerr << '\t' << "gray       For creating a grayscale version of the original image." << endl;
    cerr << '\t' << "enlarge    For enlarging the original image 2x." << endl;
    cerr << '\t' << "reduce     For reducing the original image 2x." << endl;
    cerr << '\t' << "rotate     For rotating the image 90 degrees clockwise." << endl;
    cerr << '\t' << "sharp      For sharpening the image." << endl;
    cerr << '\t' << "blur       For blurring the image." << endl;
    cerr << endl;
}

/**
 * @brief Função principal do programa.
 * 
 * Esta função valida os argumentos fornecidos na linha de comando e executa as operações 
 * desejadas em uma imagem, utilizando a classe `Editor`. Se os argumentos forem inválidos, 
 * exibe uma mensagem de uso explicativa.
 * 
 * @param argc Número de argumentos passados na linha de comando.
 * @param argv Vetor de argumentos, onde:
 *  - `argv[0]` é o nome do programa.
 *  - `argv[1]` é a operação a ser realizada (como "gray", "enlarge", etc.).
 *  - `argv[2]` é o caminho para o arquivo de imagem de entrada.
 * 
 * @return Retorna 0 ao finalizar com sucesso.
 */
int main(int argc, char* argv[]) {
    if (argc != 3) {
        print_usage(argv[0]);
    } else {
        Editor editor;
        editor.validate_operation(argv[1]);
        editor.read_img(argv[2]);
        editor.write_img();
    }
    return 0;
}
