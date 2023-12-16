#include <iostream>
using namespace std;

class Pilha {
public:
    int dado;
    Pilha* pont;

    Pilha() {
        this->dado = -1;
        this->pont = NULL;
    }

    bool vazia(Pilha* pilha) {
        return (pilha->pont == NULL);
    }

    Pilha* topo(Pilha* pilha) {
        if (pilha->pont != NULL) {
            return pilha->pont;
        }
        else {
            return NULL;
        }
    }

    void push(Pilha* pilha, int num) {
        Pilha* novo = new Pilha();
        novo->dado = num;
        novo->pont = pilha->pont;
        pilha->pont = novo;
    }

    void pop(Pilha* pilha) {
        if (!vazia(pilha)) {
            Pilha* topo = pilha->pont;
            pilha->pont = topo->pont;
            delete topo;
        }
    }

    void mostrar(Pilha* pilha) {
        Pilha* temp = pilha->pont;
        while (temp != NULL) {
            cout << temp->dado << " ";
            temp = temp->pont;
        }
        cout << endl;
    }

    int tamanho(Pilha* pilha) {
        int count = 0;
        Pilha* temp = pilha->pont;
        while (temp != NULL) {
            count++;
            temp = temp->pont;
        }
        return count;
    }
};

int main() {
    Pilha* pilha = new Pilha;
    pilha->mostrar(pilha);
    pilha->push(pilha, 10);
    pilha->push(pilha, 20);
    pilha->push(pilha, 500);
    pilha->push(pilha, 70);
    pilha->push(pilha, 50);
    pilha->pop(pilha);
    if (pilha->topo(pilha) != NULL) {
        cout << "topo da pilha: " << pilha->topo(pilha)->dado << endl;
    }

    pilha->mostrar(pilha);
    cout << "Tamanho da pilha: " << pilha->tamanho(pilha) << endl;
    return 0;
}