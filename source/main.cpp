#include "editor.h"

/**
 * Imprime uma ajuda explicando como o programa deve ser usado.
 * @param program_name Nome do arquivo executável.
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

int main (int argc, char* argv[]) {
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