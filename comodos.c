#include <stdio.h>
#include <locale.h>

typedef struct numero_comodo {
	char nome[40];
	float larg;
	float compri;
	float area;
}registro;

float calculaArea(float l, float c){
	return l * c;
}

main(){
	setlocale(LC_ALL, "Portuguese");
	char opcao;
	float areaT;
	int i, qtdC;
	registro re1[40];
	
	printf("Informe a quantidade de comodos a serem cadastrados: ");
	scanf("%d", &qtdC);
	
	fflush(stdin);
	
	for(i = 0; i < qtdC;i++){
		
		printf("Informe um nome para o cômodo: ");
		gets(&re1[i].nome);
	
		printf("Informe a largura do cômodo: ");
		scanf("%f", &re1[i].larg);
		
		fflush(stdin);
	
		printf("Infome o comprimento do cômodo: ");
		scanf("%f", &re1[i].compri);
		
		fflush(stdin);
		
		re1[i].area = calculaArea(re1[i].larg, re1[i].compri);
		printf("Area do cômodo: %.2f", re1[i].area);
		
		areaT = areaT + re1[1].area;
		
		printf("\nDeseja cadastrar novo cômodo (s/n): \n");
		scanf("%c", &opcao);
		
		fflush(stdin);
		
		if(opcao == 'n'){
			for(i = 0; i < qtdC; i++){
				//printf("Nome: %s\n", re1[i].nome);
				printf("Largura: %f \n", re1[i].larg);
				printf("Comprimento: %f \n", re1[i].compri);
				printf("Área: %f", re1[i].area);
				printf("\n\n");
			}
			printf("A area total da casa é igual a %.2f", areaT);
			getchar();
			exit(1);
		}
	}
		
}
