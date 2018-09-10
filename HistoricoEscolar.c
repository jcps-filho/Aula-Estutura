#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define MAX 60

typedef struct disciplinas {
	char disciplina[50];
	float nota;
} t_elemento;

// Estrutura da lista encadeada
typedef struct no {
    t_elemento dado;  // elemento contendo os dados
    struct no  * prox; // ponteiro para o proximo elemento
} t_no; // tipo da estrutura

// define t_lista como sendo um outro nome para "t_no *"
typedef t_no* t_lista;  

typedef struct elementos {
    int matricula;
} t_matricula;

// Estrutura da lista sequencial
typedef struct lista {
    t_matricula vetor[MAX];//vet que armazena elem. da pilha
    int n; // posicao (indice) do ultimo elemento da lista
    t_no *disciplinas;
} listaSequencial; // tipo lista

//Cria lista sequencial
listaSequencial criar() {
    listaSequencial lista;

    lista.n = -1;

    return lista;
}

//Criar lista encadeada
t_no * criaNo() {
    t_no * no = (t_no*) malloc(sizeof(t_no));

    if (no)
        no->prox = NULL;

    return no;
}

int isCheia(listaSequencial * lista) {
    return (lista->n == MAX-1);
}

int deslocaDireita(listaSequencial * lista, int pos) {
    int i;

    for (i=lista->n + 1; i>pos; i--)
        lista->vetor[i] = lista->vetor[i-1];

    return 1;
}

//Inserir da lista sequencial
int inserir (listaSequencial * lista, int pos, t_matricula dado) {
    if ( isCheia(lista) || (pos > lista->n + 1) || (pos < 0) )
        return 0;

    deslocaDireita(lista, pos);
    lista->vetor[pos] = dado;
    (lista->n)++;
    return 1;
}

t_no * getNo(t_lista lista, int pos) {
    // Retorna 0 se posicao invalida. Do contrario, retorna o elemento
    int n = 0;

    if (pos<0)
        return 0; // erro: posicao invalida

    while (lista != NULL) {
        if (n==pos)
            return lista;
        lista = lista->prox;
        n++;
    }
    return 0; // erro: posicao invalida
}

//Inserir da lista encadeada
int inserir1 (t_lista *lista, int pos, t_elemento dado) {
    t_no * p, * novo;

    // inserção na primeira posicao ou em lista vazia
    if (pos == 0) {
        novo = criaNo();
        if (novo == NULL)
            return 0; // erro: memoria insuficiente
        novo->dado = dado;
        novo->prox = *lista;
        *lista = novo;
        return 1;
    }
    // insercao apos a primeira posicao em lista nao vazia
    p = getNo(*lista, pos-1);
    if (p == NULL)
         return 0; // erro: posicao invalida 
    novo = criaNo();
    if (novo == NULL)
        return 0; // erro: memoria insuficiente
    novo->dado = dado;
    novo->prox = p->prox;
    p->prox = novo;

    return 1;
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	listaSequencial m_lista = criar();
	t_lista d_lista = criaNo();
	t_matricula aluno;
	t_elemento historico;
	int i, recebeRetorno, opcao;
	
	do {
		printf("\nALUNO: JOSÉ CARLOS PEREIRA SILVA FILHO \n DISCIPLINA: ESTRUTURA DE DADOS I \n PROFESSOR: WALACE BONFIM \n");
		printf("================ HISTÓRICO ESCOLAR ================\n");
		printf("1- Inserir matrículas, disciplinas e notas; \n");
		printf("2- Exibir históricos; \n");
		printf("0- Sair. \n\n");
		
		printf("Digite sua opção: ");
		scanf("%d", &opcao);
		
		switch(opcao) {
			
			case 1:
				for(i = 0; i < 1; i++){
					printf("\n===================================================\n");
					printf("\nInforme a matrícula: ");
					scanf("%d", &aluno.matricula);
					
					setbuf(stdin,NULL);
					
					//inserir matriculas na lista sequencial(t_lista * lista, int pos, t_elemento dado)
					recebeRetorno = inserir(&m_lista, i, aluno);
					
					for(i = 0; i < 1; i++) {
						printf("\nInforme o nome da disciplina: ");
						scanf("%[^\n]s", historico.disciplina);
						
						setbuf(stdin,NULL);
						
						printf("\nInforme a nota da disciplina: ");
						scanf("%f", &historico.nota);
						
						//inserir disciplina e nota na lista encadeada(t_lista *lista, int pos, t_elemento dado)
						recebeRetorno = inserir1(&d_lista, i, historico);
					}	
				}	
				//Verifica se os dados foram colocados corretamente na lista
				if(recebeRetorno == 1){
					printf("\nArmazenado com sucesso!\n");
				} else {
					printf("Problema no armazenamento.\n");
					exit(1);
				}
			break;
				
			case 2:
				
				
			break;
			
			case 0:
				printf("Encerrando...");
			break;
			
			default:
				printf("Opção inválida!");
				exit(1);
			break;
		}
	}while(opcao != 0);
	
	
	return 0;
}
