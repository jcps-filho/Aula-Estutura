#include <stdio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	int i, z;
	float anterior, acumulador;
	
	for(i = 0;i < 8;i++){
		for(z = 0;z < 8;z++){
			if(i == 0 && z == 0){
				anterior = 1;
				acumulador = 1;
			} else {
				anterior = anterior * 2;
				acumulador = acumulador + anterior;
			}
		}
	}
	
	printf("O valor de grãos acumulados no tabuleiro é de: %.f", acumulador);
	
	return 0;
}
