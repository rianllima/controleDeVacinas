#include <cctype>
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <locale.h>

using namespace std;

typedef struct Dados {
  int codigo = 0;
  char nome[30];
  char vacina[15];
  char cpf[15];
  char lote[15];
  char data[10];
} t_vacina;

int qtd = 0;

int cadastro(t_vacina cad[]) {

  if (qtd == 100) {
    return 0;
  }
  cout << "Digite o nome: " << endl;
  fflush(stdin);
  cin.ignore();
  cin.getline(cad[qtd].nome, 30);

  cout << "Digite o CPF: " << endl;
  fflush(stdin);
  cin >> cad[qtd].cpf;

  cout << "Digite a vacina aplicada: " << endl;
  fflush(stdin);
  cin.ignore();
  cin.getline(cad[qtd].vacina, 15);

  cout << "Digite a data da aplicação: " << endl;
  fflush(stdin);
  cin >> cad[qtd].data;

  cout << "Digite o lote da vacina: " << endl;
  fflush(stdin);
  cin.ignore();
  cin.getline(cad[qtd].lote, 15);

  system("cls || clear");
  qtd++;
  return 1;
}

void lista(t_vacina list[]) {

  if (qtd == 0) {
    cout << "Não existe apliações!" << endl;
    cout << endl;

  } else {
    for (int i = 0; i < qtd; i++) {
      list[i].codigo = i;

      cout << "Código: " << list[i].codigo << endl;
      cout << "Nome: " << list[i].nome << endl;
      cout << "CPF: " << list[i].cpf << endl;
      cout << "Vacina: " << list[i].vacina << endl;
      cout << "Data: " << list[i].data << endl;
      cout << "Lote: " << list[i].lote << endl;
      cout << "------------------------" << endl;
      cout << endl;
      
    }
  }
}

void busca(t_vacina pesquisar[], char pescpf[]) {
  bool tem = false;

  cout << "Digite o CPF que deseja encontrar: " << endl;
  cin >> pescpf;

  for (int i = 0; i < qtd; i++) {

    if (strcmp(pesquisar[i].cpf, pescpf) == tem) {

      pesquisar[i].codigo = i;

      cout << "Código: " << pesquisar[i].codigo << endl;
      cout << "Nome: " << pesquisar[i].nome << endl;
      cout << "CPF: " << pesquisar[i].cpf << endl;
      cout << "Vacina: " << pesquisar[i].vacina << endl;
      cout << "Data: " << pesquisar[i].data << endl;
      cout << "Lote: " << pesquisar[i].lote << endl;
      cout << "------------------------" << endl;
      tem = true;
      break;
      cout << endl;
    }
  }
  if (!tem) {
    cout << "CPF não encontrado" << endl;
    cout << endl;
  }
}

int main() {
  setlocale(LC_ALL, "Portuguese");
  t_vacina quantidade[100];
  char buscaCpf[14];
  char op;

  do {
    cout << "1 - Cadastrar Vacina" << endl;
    cout << "2 - Listar aplicações" << endl;
    cout << "3 - Consultar por CPF" << endl;
    cout << "4 - Sair" << endl;
    cin >> op;
    

    if (isdigit(op)) {
      switch (op) {

      case '1': {
        cadastro(quantidade);
        break;
      }
      case '2': {
        lista(quantidade);
        break;
      }
      case '3': {
        busca(quantidade, buscaCpf);
        break;
      }
      case '4': {
        exit(0);
        break;
      }
      default: {
        cout << "Numero inválido!" << endl;
        break;
      }
      }
    } else {
      cout << "Caracter inválido!" << endl;
    }

  } while (op != 4);
 system("cls || clear");
  return 0;
}