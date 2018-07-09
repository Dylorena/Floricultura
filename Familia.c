#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Familia.h"
#include"Plantas.h"

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
			ListarFamilia();
		break;
		case 3:
			ExcluirFamilia();
		break;
		case 0:
			return 1;
		break;
		default:
			printf("Opcao invalida!\n");
			Familias();
	}
}

int VerificaId(int codigo){
	familia F;
    
    FILE *arquivo;
    
    char file[] = "familias.txt";
    
    arquivo = fopen(file,"r");
    
    if(arquivo == NULL){
        printf("***ERRO: Arquivo nao encontrado.***\n");
    } else {
      	fscanf(arquivo,"%d\t%s",&F.idFamilia,F.nome);
        while(!feof(arquivo)){
      		if(F.idFamilia == codigo){
      			return 1;	
			  }
      		fscanf(arquivo,"%d\t%s",&F.idFamilia,F.nome);
        }
        
        fclose(arquivo);
        
        return 0;
  	}	
}
void OrdenaCodigo(familia *F,int qtd){
	int situacao = 1,i;
	float aux;
	char auxchar[50];
	
	while(situacao == 1){
		situacao = 0;
		for(i = 0;i < qtd-1 ;i++){
			if(F[i+1].idFamilia < F[i].idFamilia){
				aux = F[i].idFamilia;
				F[i].idFamilia = F[i+1].idFamilia;
				F[i+1].idFamilia = aux;
				strcpy(auxchar,F[i].nome);
				strcpy(F[i].nome,F[i+1].nome);
				strcpy(F[i+1].nome,auxchar);
				situacao = 1;
			}
		}
	}
}
void OrdenaNome(familia *F,int qtd){
	printf("Formular funcao de ordenar por alfabeto");
}
void ListarFamilia(){
	familia *F;
	int i = 0,qtdFamilias,opcao;

    FILE *arquivo;
    arquivo = fopen("familias.txt","r");
    
    if(arquivo == NULL){
        printf("***ERRO: Arquivo nao encontrado.***\n");
    }
    
    F = malloc(sizeof(familia) * (i+1));
    fscanf(arquivo,"%d\t%s",&F[i].idFamilia,F[i].nome);
    	while(!feof(arquivo)){
    		i++;
    		realloc(F,sizeof(familia) * (i+1));
    		fscanf(arquivo,"%d\t%s",&F[i].idFamilia,F[i].nome);
        }
    
    fclose(arquivo);
	qtdFamilias = i;
	
	printf("1-Ordenar listagem por codigo.\n2-Ordenar listagem por nome.\nOpcao:");
	scanf("%d",&opcao);
	
	if (opcao == 1){
		OrdenaCodigo(F,qtdFamilias);
	} else if(opcao == 2){
		OrdenaNome(F,qtdFamilias);
	} else {
		printf("***Opcao invalida!***\n\n");
	}
		
	for(i = 0;i < qtdFamilias;i++){
		printf("\n%.2d  %s\n",F[i].idFamilia,F[i].nome);
	}

	free(F);
    Familias();
}
void IncluirFamilia(){
	familia F;
	int Verifica;
	
	printf("Numero de identificacao da familia:");
	scanf("%d",&F.idFamilia);
	getchar();
	
	Verifica = VerificaId(F.idFamilia);
	
	while(Verifica == 1){
		printf("***Esse numero ja pertence a uma familia!***\nNumero de identificacao da familia:");
		scanf("%d",&F.idFamilia);
		getchar();
		
		Verifica = VerificaId(F.idFamilia);
	}
	
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
void ExcluirFamilia(){
	familia F;

		int verifica = 0,codigo,QtdPlantas;
    
 	   	printf("\n\nDigite o codigo da familia que deseja excluir:");
    	scanf("%d",&codigo);
	    getchar();

		QtdPlantas = VerificaPlantasnaFamilia(codigo);
		
		if(QtdPlantas > 0){
			printf("\n***Familia nao pode ser excluida pois existem plantas associadas a ela!*%d**\n",QtdPlantas);
			Familias();
		} else {
			FILE *arquivo,*arq;
		    char file[] = "familias.txt", file2[]="arqauxiliar.txt";

    		arquivo = fopen(file,"r");
	    	arq = fopen(file2,"w");

   			fscanf(arquivo,"%d\t%s",&F.idFamilia,F.nome);
		    while(!feof(arquivo)){
				if(F.idFamilia != codigo){
   					fprintf(arq,"%d\t%s\n",F.idFamilia,F.nome);
					verifica = 1;			
	    	    }
    	  		fscanf(arquivo,"%d\t%s",&F.idFamilia,F.nome);
	    	}
        
	    	if(verifica == 0){
    	    	printf("***Familia nao encontrada!***\n");
			} else {
				printf("***Familia excluida!***\n");
			}
    
    
		    fclose(arquivo);
    		fclose(arq);
		
			remove(file);
			rename(file2,"familias.txt"); 
  	
			Familias();
		}
}
int VerificaPlantasnaFamilia(int cod){
	Planta P;
	int i = 0;
	
    FILE *arquivo;
    arquivo = fopen("plantas.txt","r");
    
    if(arquivo == NULL){
        printf("***ERRO: Arquivo nao encontrado.***\n");
    }
	fscanf(arquivo,"%d\t%d\t%d\t%s\t%c\t%f",&P.idPlanta,&P.anoplantio,&P.idFamilia,P.NomeCientifico,&P.frutifera,&P.valor);
	    while(!feof(arquivo)){
	    	if(P.idFamilia == cod){
	    		i++;
			}
			fscanf(arquivo,"%d\t%d\t%d\t%s\t%c\t%f",&P.idPlanta,&P.anoplantio,&P.idFamilia,P.NomeCientifico,&P.frutifera,&P.valor);
        }
    
    fclose(arquivo);
        
	return i;
}
