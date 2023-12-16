#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  string numero,linha;
  float date;
  fstream dados;
  char opcao;
  
  dados.open("Relatorio.txt", fstream:: out | fstream:: app);

  do
  {
    cout << "Insira o numero da Ordem:" << endl;
    getline(cin,numero);

    cout << "Insira data de entrega:" << endl;
    cin >> date;

    dados << numero << '\t' << date << '\n';

    cout << "Continuar a inserir? sim ou não." << endl;
    cin >> opcao;
    cin.ignore();}
    while (opcao == 's');
    dados.close();
    
    dados.open("Relatorio.txt",fstream::in);
    while(dados.good()){
      getline(dados,linha);
      cout << linha << endl;
    }

  dados.close();
}