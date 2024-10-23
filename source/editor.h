/**
 * @file main.cpp
 * @author Júlia Guilhermino (juh,guilhermino03@gmail.com)
 * @brief Declaração da classe Editor.
 * @version 2.1
 * @date 2024-10-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef EDITOR_H
#define EDITOR_H

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

/*!
 * \class Editor
 * \brief Classe responsável por manipular imagens em formato PPM.
 *
 * Permite realizar operações de transformação na imagem: aumentar 2x,
 * transformar em escala de cinzar, reduzir 3x, rotacionar a esquerda, efeito de nitidez e desfoque.
 */
class Editor {
private:
    /*!
     * \struct Pixel
     * \brief Representa um pixel com componentes RGB.
     */
    struct Pixel {
        int r; /*!< Componente vermelha do pixel */
        int g; /*!< Componente verde do pixel */
        int b; /*!< Componente azul do pixel */
    };

    string format;      /*!< Formato da imagem (ex.: P3 para PPM) */
    string rgb_max;     /*!< Valor máximo para os componentes RGB */
    int height;         /*!< Altura da imagem */
    int width;          /*!< Largura da imagem */
    string m_operation; /*!< Operação a ser realizada na imagem */

    vector<vector<Pixel>> img;     /*!< Matriz que armazena a imagem original */
    vector<vector<Pixel>> new_img; /*!< Matriz que armazena a imagem modificada */

    /*!
     * \brief Converte a imagem para escala de cinza.
     *
     * Cada pixel tem seus componentes RGB alterados para a média
     * aritmética de suas cores: \f$ cinza = \frac{(r + g + b)}{3} \f$.
     */
    void gray();

    /*!
     * \brief Aumenta o tamanho da imagem em 2x.
     *
     * O novo pixel é calculado como a média dos valores RGB dos pixels vizinhos.
     */
    void enlarge();

    /*!
     * \brief Reduz o tamanho da imagem em 2x.
     */
    void reduce();

    /*!
     * \brief Rotaciona a imagem.
     *
     * Realiza uma rotação no sentido horário ou anti-horário.
     */
    void rotate();

    /*!
     * \brief Aplica nitidez à imagem (sharp).
     *
     * Realça os contornos e detalhes da imagem.
     */
    void sharp();

    /*!
     * \brief Aplica desfoque à imagem (blur).
     *
     * Suaviza os contornos e reduz os detalhes da imagem.
     */
    void blur();

public:
    /*!
     * \brief Valida a operação que será realizada na imagem.
     * \param operation A operação a ser validada (ex.: "gray", "enlarge").
     */
    void validate_operation(string operation);

    /*!
     * \brief Lê a imagem e a operação a partir de um arquivo.
     * \param file Caminho do arquivo de entrada.
     */
    void read_img(string file);

    /*!
     * \brief Escreve a imagem processada em um arquivo.
     */
    void write_img();
};

#endif
