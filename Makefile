# Compilador C++
CXX = g++

# Opções de compilação
CXXFLAGS = -Wall -std=c++17

# Nome do executável
TARGET = main

# Fontes do projeto
SOURCES = source/main.cpp source/editor.cpp

# Objetos gerados a partir dos fontes
OBJECTS = $(SOURCES:.cpp=.o)

# Regra de compilação
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regra para compilar cada arquivo fonte em um objeto
main.o: source/main.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

editor.o: source/editor.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpar os objetos e o executável
clean:
	rm -f $(OBJECTS) $(TARGET)

# Regra padrão
all: $(TARGET)

.PHONY: clean all