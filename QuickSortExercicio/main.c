//
//  main.c
//  QuickSortExercicio
//
//  Created by Rita de Cassia Vasconcelos do Nascimento on 19/06/20.
//  Copyright © 2020 Rita de Cassia Vasconcelos do Nascimento. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Funcionario {
  int cpf, idade, telefone;
  char nome, sexo;
}funcionario;

funcionario funcionarios[5];

void exibeLista(void);
void insereDados(void);
void quickSort(funcionario funcionario[5], int inicio, int fim);

int i;

int main() {
  int opcao;
  do {
  printf("Insira o código que deseja: \n\n");
  printf(" 1- Inserir dados; \n 2- Exibir dados; \n 3- Quick Sort; \n 4- Finalizar o programa; \n ");
  scanf("%d",&opcao);
  switch (opcao) {
    case 1:
      insereDados();
      break;
    case 2:
      exibeLista();
      break;
    case 3:
      printf("\n Ordenação por idade - QUICK SORT: \n");
      quickSort(funcionarios, 0, 4);
      for(i=0;i<=4;i++) {
           printf("\n");
           printf("Cpf: %d \n", funcionarios[i].cpf);
           printf("Nome: %c \n", funcionarios[i].nome);
           printf("Telefone: %d \n", funcionarios[i].telefone);
           printf("Sexo: %c \n", funcionarios[i].sexo);
           printf("Idade: %d \n", funcionarios[i].idade);
          printf("\n");
         }
      break;
    case 4:
      printf("Programa finalizado! \n");
    default:
      break;
  }
 } while (opcao != 4);
  return 0;
}

void insereDados() {
  for(i=0; i<=4; i++) {
    printf("Cpf: \n");
    scanf("%d", &funcionarios[i].cpf);
    printf("Nome: \n");
    scanf("%s", &funcionarios[i].nome);
    printf("Telefone: \n");
    scanf("%d", &funcionarios[i].telefone);
    printf("Sexo: M para masculino e F para feminino: \n");
    scanf("%s", &funcionarios[i].sexo);
    printf("Idade: \n");
    scanf("%d", &funcionarios[i].idade);
  }
}

void exibeLista() {
  for (i=0; i<=4; i++) {
    printf("\n");
    printf("Cpf: %d \n", funcionarios[i].cpf);
    printf("Nome: %c \n", funcionarios[i].nome);
    printf("Telefone: %d \n", funcionarios[i].telefone);
    printf("Sexo: %c \n", funcionarios[i].sexo);
    printf("Idade: %d \n", funcionarios[i].idade);
    printf("\n");
  }
}

void quickSort(funcionario funcionarios[5], int inicio, int fim) {
    int pivo, aux, i, j, meio;
    i=inicio;
    j=fim;

    meio=(i+j)/2;
    pivo=funcionarios[meio].idade;

  do {
    while(funcionarios[i].idade<pivo){
      i++;
    }
    while(funcionarios[j].idade>pivo){
      j--;
    }
    if(i<=j) {
      aux=funcionarios[i].idade;
      funcionarios[i].idade=funcionarios[j].idade;
      funcionarios[j].idade=aux;
      i++;
      j--;
    }
  } while(j>i);

if(inicio<j) {
  quickSort(funcionarios,inicio,j);
}
if(i<fim) {
  quickSort(funcionarios,i,fim);
}
}
