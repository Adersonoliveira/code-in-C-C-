#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Pessoa
{
private:
  int id;
  string nome;

public:
  Pessoa() {}
  ~Pessoa() {}

  void setId(int id)
  {
    this->id = id;
  }

  void setNome(string nome)
  {
    this->nome = nome;
  }

  int getId()
  {
    return id;
  }

  string getNome()
  {
    return nome;
  }
  void Mostrar()
  {
    cout << "ID:" << getId() << endl
         << "Nome:" << getNome() << endl;
  }
};

class Motorista : public Pessoa
{
private:
  string cnh;

public:
  Motorista() {}
  ~Motorista() {}

  void setCnh(string cnh)
  {
    this->cnh = cnh;
  }

  string getCnh()
  {
    return cnh;
  }

  void mostrar()
  {
    cout << " " << endl
         << "Dados Motorista: " << endl
         << " " << endl
         << "Nome:" << getNome() << endl
         << "CNH:" << getCnh() << endl
         << " " << endl;
  }
};

class Secretaria : public Pessoa
{
private:
  string departamento;

public:
  Secretaria() {}
  ~Secretaria() {}

  void setDepartamento(string departamento)
  {
    this->departamento = departamento;
  }

  string getDepartamento()
  {
    return departamento;
  }
  void mostrar()
  {
    cout << " " << endl
         << " Secretaria: " << endl
         << " " << endl
         << "Departamento: " << getDepartamento() << endl
         << "Nome: " << getNome() << endl;
  }
};
class Automovel : public Pessoa
{
private:
  string placa, modelo, marca;
  int ano;

public:
  Automovel() {}
  ~Automovel() {}

  void setPlaca(string placa)
  {
    this->placa = placa;
  }

  string getPlaca()
  {
    return placa;
  }

  void setModelo(string modelo)
  {
    this->modelo = modelo;
  }

  string getModelo()
  {
    return modelo;
  }

  void setAno(int ano)
  {
    this->ano = ano;
  }

  int getAno()
  {
    return ano;
  }

  void setMarca(string marca)
  {
    this->marca = marca;
  }

  string getMarca()
  {
    return marca;
  }

  void visualizar()
  {
    cout << " " << endl
         << "Dados do veiculo:" << endl
         << " " << endl
         << "Placa: " << getPlaca() << endl
         << "Modelo: " << getModelo() << endl
         << "Ano: " << getAno() << endl
         << "Marca: " << getMarca() << endl;
  }
};

class Viagem
{
private:
  Motorista motorista;
  Automovel automovel;
  string datavolta;
  string dataida;
  int kminicial;
  int kmfinal;

public:
  Viagem() {}
  ~Viagem() {}

  void setMotorista(Motorista motorista)
  {
    this->motorista = motorista;
  }

  Motorista getMotorista()
  {
    return motorista;
  }

  void setAutomovel(Automovel automovel)
  {
    this->automovel = automovel;
  }

  Automovel getAutomovel()
  {
    return automovel;
  }

  void setDatavolta(string datavolta)
  {
    this->datavolta = datavolta;
  }

  string getDatavolta()
  {
    return datavolta;
  }

  void setDataida(string dataida)
  {
    this->dataida = dataida;
  }

  string getDataida()
  {
    return dataida;
  }

  void setKminicial(int kminicial)
  {
    this->kminicial = kminicial;
  }

  int getKminicial()
  {
    return kminicial;
  }

  void setKmfinal(int kmfinal)
  {
    this->kmfinal = kmfinal;
  }

  int getKmfinal()
  {
    return kmfinal;
  }

  void imprimir()
  {
    ofstream arquivo("Relatoriodeviagem.txt", ios::out | ios::app);

    if (arquivo.is_open())
    {
      arquivo << "Detalhes da Viagem:" << endl;
      arquivo << "Motorista:" << endl;
      motorista.mostrar();
      arquivo << "Automóvel:" << endl;
      automovel.visualizar();
      arquivo << "Data de Ida: " << getDataida() << endl;
      arquivo << "Data de Volta: " << getDatavolta() << endl;
      arquivo << "KM Inicial: " << getKminicial() << endl;
      arquivo << "KM Final: " << getKmfinal() << endl;
      arquivo << endl;

      arquivo.close();
    }
    else
    {
      cout << "Não foi possível abrir o arquivo." << endl;
    }
  }
};

class Acessorios : public Automovel
{
private:
  bool direcao_eletrica;
  bool ar_condicionado;
  bool multimidia;

public:
  Acessorios() {}
  ~Acessorios() {}

  void setDirecaoEletrica(bool diracao_eletrica)
  {
    this->direcao_eletrica = diracao_eletrica;
  }

  bool getDirecaoEletrica()
  {
    return direcao_eletrica;
  }

  void setArCondicionado(bool ar_condicionado)
  {
    this->ar_condicionado = ar_condicionado;
  }

  bool getArCondicionado()
  {
    return ar_condicionado;
  }

  void setMultimidia(bool multimidia)
  {
    this->multimidia = multimidia;
  }

  bool getMultimidia()
  {
    return multimidia;
  }
};

class Frota : public Automovel
{
private:
  string identificacao, descricao;

public:
  Frota() {}
  ~Frota() {}

  void setIdentificacao(string identificacao)
  {
    this->identificacao = identificacao;
  }

  string getIdentificacao()
  {
    return identificacao;
  }

  void setDescricao(string descricao)
  {
    this->descricao = descricao;
  }

  string getDescricao()
  {
    return descricao;
  }
};

int main()
{

  Pessoa pes;
  pes.setNome("junior");
  pes.setId(10);

  Secretaria sec;
  sec.setNome("Maria");
  sec.setDepartamento("Gestao de Pessoas");

  Motorista mot;
  mot.setNome("Antonio");
  mot.setCnh("123456789");

  Automovel carro;
  carro.setPlaca("QHU3465");
  carro.setAno(2020);
  carro.setModelo("Sedan");
  carro.setMarca("Toyota");

  Viagem viagem;
  viagem.setDataida("22/08/2020");
  viagem.setDatavolta("28/08/2020");
  viagem.setKminicial(12000);
  viagem.setMotorista(mot);
  viagem.setAutomovel(carro);
  
  viagem.imprimir();

  return 0;
}
