#include<stdio.h>
#include"Familia.h"

int Familias(){
	int opcaoFamilia;
	
	printf("-------------------Familia-------------------\n\n");

	printf("1 - Incluir Familia\n2 - Listar Familia\n3 - Excluir Familia\n0 - Voltar ao menu principal\n\n");
	printf("Opcao:");
	scanf("%d",&opcaoFamilia);
				
	switch(opcaoFamilia){
		case 1:
			IncluirFamilia();
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

void IncluirFamilia(){
	familia F;
	
	printf("Numero de identificacao da familia:");
	scanf("%d",&F.idFamilia);
	getchar();
	
	printf("Nome da familia:");
    scanf("%[^\n]s",F.nome);
    getchar();
    
    FILE *arquivo;
    arquivo = fopen("familias.txt","a");
    
    fprintf(arquivo,"%d\t%s\n",F.idFamilia,F.nome);
    
    fclose(arquivo);
    
    printf("\n***Familia inserida com sucesso!***\n\n");
    Familias();
}
