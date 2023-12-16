#include <iostream>
#include <stack>
using namespace std;

void mostrar(stack<int> pilha)
{
    while (!pilha.empty())
    {
        cout << pilha.top() << endl;
        pilha.pop();
    }
}
void mostrar(stack<float> pilha)
{
    while (!pilha.empty())
    {
        cout << pilha.top() << endl;
        pilha.pop();
    }
}


int main()
{
    stack<int> pi;   // pilha de inteiros
    stack<float> pf; // pilha de floats

    pi.push(3);
    pi.push(5);
    pi.push(4);
    pf.push(4.7);
    pf.push(5.2);
    pf.push(4.9);
    mostrar(pi);
    mostrar(pf);
    pi.swap(pf);
    mostrar(pi);
    mostrar(pf);

    return 0;
}