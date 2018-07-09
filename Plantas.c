#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Plantas.h"
#include"Familia.h"

int Plantas(){
	int opcaoPlanta;
	
	printf("\n\n-------------------Plantas-------------------\n\n");
	
	printf("1 - Incluir planta\n2 - Excluir Planta\n3 - Alterar Planta\n4 - Pesquisar Planta\n5 - Listar Planta\n0 - Voltar ao menu principal\n\n");
	printf("Opcao:");
	scanf("%d",&opcaoPlanta);
				
	switch(opcaoPlanta){
		case 1:
			IncluirPlantas();
		break;
		case 2:
			ExcluirPlanta();
		break;
		case 3:
			//Alterar();
		break;
		case 4:
			//Pesquisar();
		break;
		case 5:
			ListarPlantas();
		break;
		case 0:
			return 1;
		break;
		default:
			printf("Opcao invalida!\n");
			Plantas();
	}	
}
void OrdenaNomeP(Planta *P,int qtd){
	printf("Chamara a funcao ordenar por ordem alfabetica");
}
void OrdenaCodigoP(Planta *P,int qtd){
	int situacao = 1,i;
	float aux;
	char auxchar[50],auxC;
	
	while(situacao == 1){
		situacao = 0;
		for(i = 0;i < qtd-1 ;i++){
			if(P[i+1].idPlanta < P[i].idPlanta){
				aux = P[i].idPlanta;
				P[i].idPlanta = P[i+1].idPlanta;
				P[i+1].idPlanta = aux;
				
				strcpy(auxchar,P[i].NomeCientifico);
				strcpy(P[i].NomeCientifico,P[i+1].NomeCientifico);
				strcpy(P[i+1].NomeCientifico,auxchar);
				
				aux = P[i].anoplantio;
				P[i].anoplantio = P[i+1].anoplantio;
				P[i+1].anoplantio = aux;
				
				aux = P[i].valor;
				P[i].valor = P[i+1].valor;
				P[i+1].valor = aux;
				
				aux = P[i].idFamilia;
				P[i].idFamilia = P[i+1].idFamilia;
				P[i+1].idFamilia = aux;
				
				auxC = P[i].frutifera;
				P[i].frutifera = P[i+1].frutifera;
				P[i+1].frutifera = auxC;
				
				situacao = 1;
			}
		}
	}
}
void ListarPlantas(){
	Planta *P;
	int i = 0,qtdplantas,opcao;
	
	printf("1-Ordenar listagem por codigo.\n2-Ordenar listagem por nome.\nOpcao:");
	scanf("%d",&opcao);
	
    FILE *arquivo;
    arquivo = fopen("plantas.txt","r");
    
    if(arquivo == NULL){
        printf("***ERRO: Arquivo nao encontrado.***\n");
    }
    P = malloc(sizeof(Planta) * (i+1));
	fscanf(arquivo,"%d\t%d\t%d\t%s\t%c\t%f",&P[i].idPlanta,&P[i].anoplantio,&P[i].idFamilia,P[i].NomeCientifico,&P[i].frutifera,&P[i].valor);
	    while(!feof(arquivo)){
	    	i++;
    		realloc(P,sizeof(Planta) * (i+1));
			fscanf(arquivo,"%d\t%d\t%d\t%s\t%c\t%f",&P[i].idPlanta,&P[i].anoplantio,&P[i].idFamilia,P[i].NomeCientifico,&P[i].frutifera,&P[i].valor);
        }
    
    fclose(arquivo);
        
	qtdplantas = i;
	
	if (opcao == 1){
		OrdenaCodigoP(P,qtdplantas);
		for(i = 0;i < qtdplantas;i++){
			printf("%d\t%d\t%d\t%s\t%c\t%.2f\n",P[i].idPlanta,P[i].anoplantio,P[i].idFamilia,P[i].NomeCientifico,P[i].frutifera,P[i].valor);	
		}
	} else if(opcao == 2){
		OrdenaNomeP(P,qtdplantas);
		for(i = 0;i < qtdplantas;i++){
			printf("%d\t%d\t%d\t%s\t%c\t%.2f",P[i].idPlanta,P[i].anoplantio,P[i].idFamilia,P[i].NomeCientifico,P[i].frutifera,P[i].valor);	
		}
	} else {
		printf("***Opcao invalida!***\n\n");
	}

	free(P);
    Plantas();
}
void IncluirPlantas(){
	Planta P;
	int verifica;
	
	printf("Numero de identificacao da Planta:");
	scanf("%d",&P.idPlanta);
	
	do{
		printf("Ano do plantio:");
		scanf("%d",&P.anoplantio);
		if(P.anoplantio < 0){
			printf("\n***Ano invalido!***\n");
		}
	}while(P.anoplantio < 0);
		
	printf("Codigo da familia:");
	scanf("%d",&P.idFamilia);
	getchar();
	
	verifica = VerificaFamiliaP(P.idFamilia);
	
	while(verifica != 1){
		printf("\n***Familia inexistente***\n");
		printf("Codigo da familia:");
		scanf("%d",&P.idFamilia);
		getchar();
		
		verifica = VerificaFamiliaP(P.idFamilia);
	}
	
	printf("Nome cientifico:");
    scanf("%[^\n]s",P.NomeCientifico);
    getchar();
    
   	printf("Planta frutifera(S - SIM/ N - Nao):");
   	scanf("%c",&P.frutifera);
   	getchar();

	
    printf("Preco de venda:");
    scanf("%f",&P.valor);
    
    verifica = VerificaDuplicidade(P.NomeCientifico,P.idPlanta);
    
    while(verifica != 0){
    	if(verifica == 1){
    		printf("\n***Cadastro duplicado!***\n");
    		getchar();
    		printf("Nome cientifico:");
    		scanf("%[^\n]s",P.NomeCientifico);
    		getchar();
    	} else {
    		printf("\n***Cadastro duplicado!***\n");
    		printf("Numero de identificacao da Planta:");
			scanf("%d",&P.idPlanta);
		} 
		verifica = VerificaDuplicidade(P.NomeCientifico,P.idPlanta);
    }
	printf("\n\n %d %d %d %s %c %f \n",P.idPlanta,P.anoplantio,P.idFamilia,P.NomeCientifico,P.frutifera,P.valor);

    
    FILE *arquivo;
    arquivo = fopen("plantas.txt","a");
    
    fprintf(arquivo,"%d\t%d\t%d\t%s\t%c\t%.2f\n",P.idPlanta,P.anoplantio,P.idFamilia,P.NomeCientifico,P.frutifera,P.valor);

    fclose(arquivo);
    
    printf("\n***Planta inserida com sucesso!***\n\n");
    Plantas();

}
void ExcluirPlanta(){
	Planta P;
	int opcao;
	
	printf("1 - Excluir por numero do codigo\n2 - Excluir por nome da planta\n");
	printf("Opcao:");
	scanf("%d",&opcao);
	
	if(opcao == 1){
		int verifica = 0,codigo;
    
 	   	printf("\n\nDigite o codigo da planta que deseja excluir:");
    	scanf("%d",&codigo);
	    getchar();

    	FILE *arquivo,*arq;
	    char file[] = "plantas.txt", file2[]="arqauxiliar.txt";

    	arquivo = fopen(file,"r");
	    arq = fopen(file2,"w");

   		fscanf(arquivo,"%d\t%d\t%d\t%s\t%c\t%f",&P.idPlanta,&P.anoplantio,&P.idFamilia,P.NomeCientifico,&P.frutifera,&P.valor);
	    while(!feof(arquivo)){
			if(P.idPlanta != codigo){
   				fprintf(arq,"%d\t%d\t%d\t%s\t%c\t%.2f\n",P.idPlanta,P.anoplantio,P.idFamilia,P.NomeCientifico,P.frutifera,P.valor);
				verifica = 1;			
    	    }
      		fscanf(arquivo,"%d\t%d\t%d\t%s\t%c\t%f",&P.idPlanta,&P.anoplantio,&P.idFamilia,P.NomeCientifico,&P.frutifera,&P.valor);
	    }
        
    	if(verifica == 0){
        	printf("***Planta nao encontrado!***\n");
		} else {
			printf("***Planta excluida!***");
		}
    
    
	    fclose(arquivo);
    	fclose(arq);
	
		remove(file);
		rename(file2,"plantas.txt"); 
  	
		Plantas();
	} else if (opcao == 2){
		char nome[50];
    	int verifica = 0;
    
 	   printf("\n\nDigite a planta que deseja excluir:");
    	scanf("%s",nome);
	    getchar();

    	FILE *arquivo,*arq;
	    char file[] = "plantas.txt", file2[]="arqauxiliar.txt";

    	arquivo = fopen(file,"r");
	    arq = fopen(file2,"w");

   		fscanf(arquivo,"%d\t%d\t%d\t%s\t%c\t%f",&P.idPlanta,&P.anoplantio,&P.idFamilia,P.NomeCientifico,&P.frutifera,&P.valor);
	    while(!feof(arquivo)){
			if(strcmp(P.NomeCientifico,nome)!=0){
   				fprintf(arq,"%d\t%d\t%d\t%s\t%c\t%.2f\n",P.idPlanta,P.anoplantio,P.idFamilia,P.NomeCientifico,P.frutifera,P.valor);
				verifica = 1;			
    	    }
      		fscanf(arquivo,"%d\t%d\t%d\t%s\t%c\t%f",&P.idPlanta,&P.anoplantio,&P.idFamilia,P.NomeCientifico,&P.frutifera,&P.valor);
	    }
        
    	if(verifica == 0){
        	printf("***Planta nao encontrado!***\n");
		} else {
			printf("***Planta excluida!***");
		}
    
    
	    fclose(arquivo);
    	fclose(arq);
	
		remove(file);
		rename(file2,"plantas.txt"); 
  	
		Plantas();
	} else {
		printf("***Opcao invalida!***\n");
	}
}

int VerificaDuplicidade(char *nome,int codigo){
	Planta P;
    
    FILE *arquivo;
    
    char file[] = "plantas.txt";
    
    arquivo = fopen(file,"r");
    
    if(arquivo == NULL){
        printf("***ERRO: Arquivo nao encontrado.***\n");
    } else {
   		fscanf(arquivo,"%d\t%d\t%d\t%s\t%c\t%f",&P.idPlanta,&P.anoplantio,&P.idFamilia,P.NomeCientifico,&P.frutifera,&P.valor);
        while(!feof(arquivo)){
      		if(strcmp(P.NomeCientifico,nome)==0){
      			return 1;	
			  } else if (P.idPlanta == codigo){
			  	return 2;
			  }
   			fscanf(arquivo,"%d\t%d\t%d\t%s\t%c\t%f",&P.idPlanta,&P.anoplantio,&P.idFamilia,P.NomeCientifico,&P.frutifera,&P.valor);
        }
        
        fclose(arquivo);
    }
	  return 0;
}

int VerificaFamiliaP(int IDFamilia){
	familia F;
    
    FILE *arquivo;
    
    char file[] = "familias.txt";
    
    arquivo = fopen(file,"r");
    
    if(arquivo == NULL){
        printf("***ERRO: Arquivo nao encontrado.***\n");
    } else {
      	fscanf(arquivo,"%d\t%s",&F.idFamilia,F.nome);
        while(!feof(arquivo)){
      		if(F.idFamilia == IDFamilia){
      			return 1;	
			}
      		fscanf(arquivo,"%d\t%s",&F.idFamilia,F.nome);
        }
        
        fclose(arquivo);
        
        return 0;
  	}
}
