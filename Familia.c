#include<stdio.h>
#include"Familia.h"

int Familias(){
	int opcaoFamilia;
	
	printf("-------------------Plantas-------------------\n\n");

	printf("1 - Incluir Familia\n2 - Listar Familia\n3 - Excluir Familia\n0 - Voltar ao menu principal\n\n");
	printf("Opcao:");
	scanf("%d",&opcaoFamilia);
				
	switch(opcaoFamilia){
		case 1:
			//Incluir();
		break;
		case 2:
			printf("Aqui vou chamar uma funcao Listar\n");
		break;
		case 3:
			//Excluir();
		break;
		case 0:
			return 1;
		break;
		default:
			printf("Opcao invalida!\n");
			Familias();
	}
}
