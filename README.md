# Editor de Imagens em C++ 🖼️

Este projeto é um editor simples de imagens em formato PPM que realiza operações como conversão para escala de cinza, ampliação, redução, rotação, nitidez e desfoque.
Ele foi proposto na disciplina de Introdução à Técnicas de Programação do curso Bacharelado em Ciência da Computação da UFRN no semestre 2023.1. E foi desenvolvido em parceria entre [Júlia Guilhermino](https://github.com/JuhGuilhermino) e [Ludmilla Rodrigues](https://github.com/Millalud). Posteriormente ele foi refatorado na disciplina de Boas Práticas de Programação no semestre 2024.2 por [Júlia Guilhermino](https://github.com/JuhGuilhermino).

## 📋 Índice

- [Introdução](#introdução)
- [Funcionalidades](#funcionalidades)
- [Pré-requisitos](#pré-requisitos)
- [Como Compilar e Executar](#como-compilar-e-executar)
- [Exemplos de Uso](#exemplos-de-uso)

---

## 📖 Introdução

Este projeto é um editor de imagens desenvolvido em C++ com o objetivo de demonstrar operações básicas de manipulação de imagens, como:
- Conversão para escala de cinza
- Ampliação e redução
- Rotação
- Filtro de nitidez
- Desfoque

As operações são aplicadas em arquivos de imagem no formato **PPM (Portable Pixmap)**.

---

## ✨ Funcionalidades

- **gray**: Converte a imagem para tons de cinza.
- **enlarge**: Aumenta o tamanho da imagem em 2x.
- **reduce**: Reduz o tamanho da imagem em 2x.
- **rotate**: Rotaciona a imagem em 90 graus no sentido horário.
- **sharp**: Aplica um filtro de nitidez à imagem.
- **blur**: Aplica um filtro de desfoque à imagem.

---

## 🛠️ Pré-requisitos

Para compilar e executar este projeto, você precisará de:
- [Makefile](https://www.gnu.org/software/make/manual/make.html) (para automação da build)
- Uma imagem PPM de entrada no formato PPM (Ex.: `imagem.ppm`)

---

## 🚀 Como Compilar e Executar

Abra o terminal na pasta do projeto e execute o seguinte comando:

```bash 
make 
```
Em seguida execute o seguinte comando:

```bash 
./main <operação> <nome da imagem> 
```

É possível realizar um teste utilizando a imagem `imgs/galinhos.ppm`.