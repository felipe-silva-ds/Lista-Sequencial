#include <iostream>

using namespace std;

class ListaSeq {
    private:
        int *dados;
        int tamAtual;
        int tamMax;

    public:
    ListaSeq(int tamMax) {
        this->tamMax = tamMax;
        this->tamAtual = 0; 
        this->dados = new int[tamMax];
    }

        void printLista() {
            cout << "[ ";
            for (int i = 0; i < tamAtual; i++) {
                cout << dados[i];
                if (i < tamAtual - 1) {
                    cout << ", ";
                }
            }
            cout << " ]" << endl;
        }

        bool Vazia() {
             return tamAtual==0;
        }

        bool Cheia() {
            return tamAtual == tamMax;
        }

        int Tamanho() {
            return tamAtual;
        }

        int recuperarPos(int pos) {
            if (pos <= 0 || pos > tamAtual) {
                cerr << "Elemento invalido fora da posição da lista" << endl;
                return -1;
            }
            return dados[pos - 1];
        }

        void mudaValor(int valor, int pos) {
            if (pos <= 0 || pos > tamAtual) {
                cerr << "Modificação negada pois a posição eh invalida..." << endl;
                return;
            }
            dados[pos - 1] = valor;
        }

        void ObterValor(int valor, int pos) {
            if (pos <= 0 || pos > tamAtual + 1) {
                cerr << "Inserçao de um elemento em posição invalida ." << endl;
                return;
            }
            if (Cheia()) {
                cerr << "Inserção em lista cheia." << endl;
                return;
            }
            for (int i = tamAtual; i >= pos; i--) {
                dados[i] = dados[i - 1];
            }
            dados[pos - 1] = valor;
            tamAtual++;
        }

        void removerElemento(int pos) {
            if (pos <= 0 || pos > tamAtual) {
                cerr << "Tentativa de remoção invalida devido a posição ser invalida ." << endl;
                return;
            }
            for (int i = pos - 1; i < tamAtual - 1; i++) {
                dados[i] = dados[i + 1];
            }
            tamAtual--;
        }
};

int main() {

    ListaSeq lista = ListaSeq(20);

    lista.printLista();

   
    if (lista.Vazia()) {
        cout << "A lista está vazia." << endl;
    } else if (lista.Cheia()) {
        cout << "A lista está cheia." << endl;
    }

    cout << "Inserindo os valores 40, 15, 13, nas posições 1, 2 e 3" << endl;
    lista.ObterValor(40, 1);
    lista.ObterValor(15, 2);
    lista.ObterValor(13, 3);

    lista.printLista();

    cout << "Tam " << lista.Tamanho() << endl;

    cout << "Mudar elemento na pos(3): 12 " << endl;
    lista.mudaValor(12, 3);

    cout << "Exibir elemento da posição (2): " << lista.recuperarPos(2) << endl;

    lista.printLista();

    cout << "Remoção da posição (3)" << endl;
    lista.removerElemento(3);

    lista.printLista();

    cout << "Tentar mudar o valor em posições 0, negativa ou maior que tam da lista entrará mensagem de erro." << endl;
    lista.mudaValor(50, 0);
    lista.mudaValor(20, -24);
    lista.mudaValor(24, 5);

    cout << "Tentar Inserir um elemento em posições 0, negativa, ou maior que o tam da lista entrará mensagem de erro" << endl;
    lista.ObterValor(0, 0);
    lista.ObterValor(2, -3);
    lista.ObterValor(5, 5);

    cout << "Tentando modificar o valor em posições fora do tam entrará mensagem de erro" << endl;
    lista.mudaValor(20, 0);
    lista.mudaValor(32, -3);
    lista.mudaValor(2, 6);

    cout << "Tentando obter elemento fora das posições entrará uma mensagem de erro." << endl;
    lista.recuperarPos(0);
    lista.recuperarPos(8);
    lista.recuperarPos(-5);

    cout << "Tentar remover um elemento fora das posições entrará uma mensagem de erro" << endl;
    lista.removerElemento(0);
    lista.removerElemento(25);
    lista.removerElemento(-5);

    return 0;
}
