#include<stdio.h>
#include"Plantas.h"

int Plantas(){
	int opcaoPlanta;
	
	printf("\n\n-------------------Plantas-------------------\n\n");
	
	printf("1 - Incluir planta\n2 - Consultar Planta\n3 - Listar Planta\n4 - Excluir Planta\n5 - Alterar Planta\n0 - Voltar ao menu principal\n\n");
	printf("Opcao:");
	scanf("%d",&opcaoPlanta);
				
	switch(opcaoPlanta){
		case 1:
			IncluirPlantas();
		break;
		case 2:
			printf("Aqui vou chamar uma funcao Listar as plantas\n");
		break;
		case 3:
			//Excluir();
		break;
		case 4:
			//Excluir();
		break;
		case 5:
			//Alterar();
		break;
		case 0:
			//montarMenu();
		break;
		default:
			printf("Opcao invalida!\n");
			Plantas();
	}	
}
	
void IncluirPlantas(){
	Planta P;
	
	printf("Numero de identificacao da Planta:");
	scanf("%d",&P.idPlanta);
	
	do{
		printf("Ano do plantio:");
		scanf("%d",&P.anoplantio);
		if(P.anoplantio < 0){
			printf("***Ano invalido!***\n");
		}

	}while(P.anoplantio < 0);
		
	printf("Codigo da familia:");
	scanf("%d",&P.idFamilia);
	getchar();
	
	printf("Nome cientifico:");
    scanf("%[^\n]s",P.NomeCientifico);
    getchar();
    
    do{
    	printf("Planta frutifera(S - SIM/ N - Nao):");
    	scanf("%c",&P.frutifera);
    	//getchar();
    	
    	if(P.frutifera != 'N' || P.frutifera != 'S'){
    		printf("***Entrada invalida***\n");
		}
	}while(P.frutifera != 'N' || P.frutifera != 'S');
    
    printf("Preco de venda:");
    scanf("%f",&P.valor);
    
    
    printf("\n\n %d %d %d %s %c %f \n",P.idPlanta,P.anoplantio,P.idFamilia,P.NomeCientifico,P.frutifera,P.valor);

    
    FILE *arquivo;
    arquivo = fopen("plantas.txt","a");
    
    fprintf(arquivo,"%d\t%d\t%d\t%s\t%c\t%.2f\n",P.idPlanta,P.anoplantio,P.idFamilia,P.NomeCientifico,P.frutifera,P.valor);

    fclose(arquivo);
    
    printf("\n***Planta inserida com sucesso!***\n\n");
    Plantas();

}
