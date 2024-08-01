# Nome do compilador
CXX = g++

# Flags do compilador
CXXFLAGS = -Wall -g

# Nome do executável
EXEC = Listaseq

# Arquivos fonte
SRC = Listaseq.cpp

# Regras de compilação
all: $(EXEC)

$(EXEC): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(SRC)

# Regra para limpar arquivos de compilação
clean:
	rm -f $(EXEC)
