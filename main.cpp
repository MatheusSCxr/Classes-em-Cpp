#include <iostream>
using namespace std;


class Cliente {
  private:
    string nome;
    int idade;
    float avaliacao;
  public:
    Cliente()
    {
      //construtor "padrão" - sem parâmetros
      cout << "Iniciou construtor vazio" << endl;
      Start("VAZIO",2,10);
    }
    Cliente(string nome, int idade, float avaliacao)
    {
      cout << "Construtor com parâmetros" << endl;
      Start(nome,idade,avaliacao);
    }

    void Start (string nome, int idade, float avaliacao)
    {
      //chama as procedimentos "SET" para inicializar o construtor com/sem parâmetros
      setNome(nome);
      setIdade(idade);
      setAva(avaliacao);
    }

    //procedimentos SET
    void setNome (string nNome)
    {
      if (nNome.length() > 2)
        nome = nNome;
      else
        cout << "Nome inválido ou com menos de 3 caracteres" << endl;
    }
    void setIdade (int nIdade)
    {
      if (nIdade > 0)
        idade = nIdade;
      else
        cout << "Idade menor que 0" << endl;
    }
    void setAva (float nota)
    {
      if (nota > 0)
        avaliacao = nota;
      else
        cout << "Nota menor que 0" << endl;
    }

    // funções GET
    string getNome() {
      return nome;
    }
    int getIdade(){
      return idade;
    }
    float getAva(){
      return avaliacao;
    }

    //exibir
    void exibe (){
      cout << "Nome gravado: " << getNome() << "  Idade gravada: " << getIdade() << "  Avaliação gravada: " << getAva() << endl << endl;
    }
};

int main() {
  Cliente c1("Ramsés Terceiro",213897,99.9),c2;
  c1.exibe();
  c2.Start("Pedro Almeida",55,72.8);
  c2.exibe();
  Cliente *empresa;
  empresa = (Cliente*)malloc(3*sizeof(Cliente));

  string nNome;
  int idade;
  float ava;

  cout << "Insira os dados dos clientes da Empresa: " << endl;
  for (int i = 0; i < 3; i++)
    {
      cout << "Nome: " << endl;
      cin >> nNome;
      cout << "Idade: " << endl;
      cin >> idade;
      cout << "Avaliação: " << endl;
      cin >> ava;
      (*(empresa + i)).setNome(nNome);
    }
}