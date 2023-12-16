#include <iostream>
#include <string>
#include <fstream>

using namespace std;
class Pessoa
{

private:
  int cpf;
  string nome;

public:
  Pessoa() {}
  ~Pessoa() {}

  void setCpf(int cpf)
  {
    this->cpf = cpf;
  }

  void setNome(string nome)
  {
    this->nome = nome;
  }

  int getCpf()
  {
    return cpf;
  }

  string getNome()
  {
    return nome;
  }
  void Mostrar()
  {
    cout << "CPF:" << getCpf() << endl
         << "Nome:" << getNome() << endl;
  }
};

class Casa
{
private:
  float area_construida;
  float area_terreno;

public:
  Casa() {}
  ~Casa() {}

  void setArea_construida(float area_construida)
  {
    this->area_construida = area_construida;
  }
  float getArea_construida()
  {
    return area_construida;
  }

  void setArea_terreno(float area_terreno)
  {
    this->area_terreno = area_terreno;
  }
  float getArea_terreno()
  {
    return area_terreno;
  }

  float obterArea()
  {
    return area_construida;
  }
};

class Apartamento
{
private:
  float area_privada;
  float area_comum;
  bool play_groud;
  bool academia;

public:
  Apartamento() {}
  ~Apartamento() {}

  void setArea_privada(float area_privada)
  {
    this->area_privada = area_privada;
  }
  float getArea_privada()
  {
    return area_privada;
  }

  void setArea_comum(float area_comum)
  {
    this->area_comum = area_comum;
  }
  float getArea_comum()
  {
    return area_comum;
  }

  void setPlay_groud(bool play_groud)
  {
    this->play_groud = play_groud;
  }
  bool getPlay_groud()
  {
    return play_groud;
  }

  void setAcademia(bool academia)
  {
    this->academia = academia;
  }
  bool getAcademia()
  {
    return academia;
  }
  float obterArea()
  {
    return area_privada + area_comum;
  }
};

class Imovel
{
private:
  int codigo;
  std::string endereco;
  float area;
  float valor;
  Pessoa *proprietario; 

public:
  Imovel() : proprietario(nullptr) {} // Inicializa o ponteiro como nulo
  ~Imovel() {}

  void setCodigo(int codigo)
  {
    this->codigo = codigo;
  }
  int getCodigo()
  {
    return codigo;
  }

  void setEndereco(std::string endereco)
  {
    this->endereco = endereco;
  }
  std::string getEndereco()
  {
    return endereco;
  }

  void setArea(float area)
  {
    this->area = area;
  }
  float getArea()
  {
    return area;
  }

  void setValor(float valor)
  {
    this->valor = valor;
  }
  float getValor()
  {
    return valor;
  }

  
  float calcularComissao(float percentual)
  {
    return valor * (percentual / 100);
  }

  
  void setProprietario(Pessoa *pessoa)
  {
    proprietario = pessoa;
  }

  
  Pessoa *obterProprietario()
  {
    return proprietario;
  }

  
  void mostrarImovel()
  {
    std::cout << "Código: " << codigo << std::endl;
    std::cout << "Endereço: " << endereco << std::endl;
    std::cout << "Área: " << area << " metros quadrados" << std::endl;
    std::cout << "Valor: R$ " << valor << std::endl;
    if (proprietario)
    {
      std::cout << "Proprietário: " << proprietario->getNome() << std::endl;
    }
    else
    {
      std::cout << "Proprietário: Não definido" << std::endl;
    }
  }
  
  void gravarEmArquivo(const std::string &nomeArquivo)
  {
    std::ofstream arquivo(nomeArquivo);

    if (arquivo.is_open())
    {
      arquivo << "Código: " << codigo << std::endl;
      arquivo << "Endereço: " << endereco << std::endl;
      arquivo << "Área: " << area << " metros quadrados" << std::endl;
      arquivo << "Valor: R$ " << valor << std::endl;
      if (proprietario)
      {
        arquivo << "Proprietário: " << proprietario->getNome() << std::endl;
      }
      else
      {
        arquivo << "Proprietário: Não definido" << std::endl;
      }

      arquivo.close();
      std::cout << "Dados gravados em arquivo: " << nomeArquivo << std::endl;
    }
    else
    {
      std::cerr << "Erro ao abrir o arquivo para gravação." << std::endl;
    }
  }

  void mostrarDadosDoArquivo(const std::string &nomeArquivo)
  {
    std::ifstream arquivo(nomeArquivo);

    if (arquivo.is_open())
    {
      std::string linha;
      while (std::getline(arquivo, linha))
      {
        std::cout << linha << std::endl;
      }

      arquivo.close();
    }
    else
    {
      std::cerr << "Erro ao abrir o arquivo para leitura." << std::endl;
    }
  }
};
int main()
{
 
  Pessoa proprietario1;
  proprietario1.setCpf(123456789);
  proprietario1.setNome("João da Silva");

  Pessoa proprietario2;
  proprietario2.setCpf(987654321);
  proprietario2.setNome("Maria Souza");

  Pessoa proprietario3;
  proprietario3.setCpf(555555555);
  proprietario3.setNome("José Santos");

  
  Casa minhaCasa;
  minhaCasa.setArea_construida(150.0);
  minhaCasa.setArea_terreno(300.0);

  
  Apartamento meuApartamento;
  meuApartamento.setArea_privada(80.0);
  meuApartamento.setArea_comum(20.0);
  meuApartamento.setPlay_groud(true);
  meuApartamento.setAcademia(false);

  
  Imovel imovel1;
  imovel1.setCodigo(1);
  imovel1.setEndereco("Rua da Amizade, 123");
  imovel1.setArea(150.0);
  imovel1.setValor(250000.0);
  imovel1.setProprietario(&proprietario1); // Associa o proprietário ao imóvel

  Imovel imovel2;
  imovel2.setCodigo(2);
  imovel2.setEndereco("Avenida Principal, 456");
  imovel2.setArea(100.0);
  imovel2.setValor(180000.0);
  imovel2.setProprietario(&proprietario2); 

  Imovel imovel3;
  imovel3.setCodigo(3);
  imovel3.setEndereco("Rua Secundária, 789");
  imovel3.setArea(120.0);
  imovel3.setValor(210000.0);
  imovel3.setProprietario(&proprietario3); 

  // Mostrar informações dos imóveis
  std::cout << "Informações da Casa:" << std::endl;
  std::cout << "Área Construída: " << minhaCasa.getArea_construida() << " metros quadrados" << std::endl;
  std::cout << "Área do Terreno: " << minhaCasa.getArea_terreno() << " metros quadrados" << std::endl;

  std::cout << "\nInformações do Apartamento:" << std::endl;
  std::cout << "Área Privada: " << meuApartamento.getArea_privada() << " metros quadrados" << std::endl;
  std::cout << "Área Comum: " << meuApartamento.getArea_comum() << " metros quadrados" << std::endl;
  std::cout << "Playground: " << (meuApartamento.getPlay_groud() ? "Sim" : "Não") << std::endl;
  std::cout << "Academia: " << (meuApartamento.getAcademia() ? "Sim" : "Não") << std::endl;

  std::cout << "\nInformações do Imóvel 1:" << std::endl;
  imovel1.mostrarImovel();

  std::cout << "\nInformações do Imóvel 2:" << std::endl;
  imovel2.mostrarImovel();

  std::cout << "\nInformações do Imóvel 3:" << std::endl;
  imovel3.mostrarImovel();

 
  imovel1.gravarEmArquivo("dados_imovel1.txt");
  imovel2.gravarEmArquivo("dados_imovel2.txt");
  imovel3.gravarEmArquivo("dados_imovel3.txt");
 
  imovel1.mostrarDadosDoArquivo("dados_imovel1.txt");
  imovel2.mostrarDadosDoArquivo("dados_imovel2.txt");
  imovel3.mostrarDadosDoArquivo("dados_imovel3.txt");

  return 0;
}
