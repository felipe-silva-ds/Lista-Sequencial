# Nome do compilador
CXX = g++

# Flags de compilação
CXXFLAGS = -Wall -std=c++11

# Nome do arquivo executável
TARGET = main.exe

# Nome do arquivo fonte
SRC = ListaSeq.cpp

# Regra padrão para compilar o executável
all: $(TARGET)

# Regra para compilar o executável
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Limpar os arquivos compilados
clean:
	rm -f $(TARGET)
