#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1024

typedef struct elementos {
	char nome[30];
	int telefone1;
	int telefone2;
}t_elemento;

typedef struct lista {
	t_elemento vetor[MAX];
	int n;
}t_lista;

t_lista criar() {
	t_lista lista;
	lista.n	= -1;
	return lista;
}

int deslocaDireita(t_lista * lista, int pos) {
    int i;

    for (i=lista->n + 1; i>pos; i--)
        lista->vetor[i] = lista->vetor[i-1];

    return 1;
}

int isCheia(t_lista * lista) {
    return (lista->n == MAX-1);
}

int inserir (t_lista * lista, int pos, t_elemento dado) {
    if ( isCheia(lista) || (pos > lista->n + 1) || (pos < 0) ){
        return 0;
	}
    deslocaDireita(lista, pos);
    lista->vetor[pos] = dado;
    (lista->n)++;
    return 1;
}

int getTamanho(t_lista * lista) {
    return lista->n + 1;
}

int deslocaEsquerda(t_lista * lista, int pos) {
    int i;

    for (i=pos; i<(lista->n); i++)
        lista->vetor[i] = lista->vetor[i+1];

    return 1;
}

int remover (t_lista *lista, int pos) {
    if ( (pos > lista->n) || (pos < 0) )
        return 0;

    deslocaEsquerda(lista, pos);

    (lista->n)--;
    return 1;
}

main(){
	t_lista m_lista;
	t_elemento contato;
	int i, abc, opcao, tam;
	
	//Criar a lista
	m_lista = criar();
	
	do{
		printf("1- Inserir; \n");
		printf("2- Apagar; \n");
		printf("3- Pesquisar; \n");
		printf("4- Listar; \n");
		printf("5- Sair. \n");
		scanf("%d", &opcao);
		
		switch(opcao){
			
			case 1:	
				for(i = 0; i < 1; i++){
					printf("Informe o nome do contato: ");
					scanf("%s", &contato.nome);
	
					printf("Informe o telefone 1: ");
					scanf("%d", &contato.telefone1);
		
					printf("Informe o telefone 2: ");
					scanf("%d", &contato.telefone2);
				
					//inserir (t_lista * lista, int pos, t_elemento dado)
					abc = inserir (&m_lista, i, contato);
				}	
				//Verifica se os dados foram colocados corretamente na lista
				if(abc == 1){
					printf("Armazenado com sucesso!\n");
				} else {
					printf("Problema no armazenamento.\n");
					exit(1);
				}
			break;
			case 2:
				
			break;
			
			case 3:
			break;
		
			case 4:
				tam = getTamanho(&m_lista);
				printf("\n");
				//loop para mostrar
				printf("==== Contatos =====\n");
				for(i=0; i < tam; i++){
					printf("Nome: %s\n", m_lista.vetor[i].nome);
					printf("Telefone 1: %d\n", m_lista.vetor[i].telefone1);
					printf("Telefone 2: %d\n\n", m_lista.vetor[i].telefone2);
				}
				printf("=================\n");
			break;
			case 5:
				printf("Encerrando programa...");
				exit(1);
			break;
			default:
				printf("Opcao Invalida!");
				exit(1);
			break;
		}
	}while(opcao != 5);
}
