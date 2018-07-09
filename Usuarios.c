#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"Usuarios.h"

int Usuarios(){
	int opcaoUsuario;
	
	printf("\n\n-------------------Usuarios-------------------\n\n");
	
	printf("1 - Incluir usuario\n2 - Excluir usuario\n3 - Listar usuarios\n4 - Alterar senha do usuario\n0 - Voltar ao menu principal\n\n");
	printf("Opcao:");
	scanf("%d",&opcaoUsuario);
	getchar();
				
	switch(opcaoUsuario){
		case 1:
			IncluirUsuario();
		break;
		case 2:
			ExcluirUsuario();
		break;
		case 3:
			ListarUsuario();
		break;
		case 4:
			AlterarUsuario();
		break;
		case 0:
			return 1;
		break;
		default:
			printf("***Opcao invalida!***\n");
			Usuarios();
	}
   
}
int AutenticaUsuario(){
	char login[20],senha[15];
	usuario U,Pessoa;
	
	printf("\n\nBem vindo ao Sistema de controle de Floricultura\n\n");
	printf("Login:");
	scanf("%s",Pessoa.login);
	getchar();
	
	printf("\nSenha:");
	scanf("%s",Pessoa.senha);
	getchar();
	    
    FILE *arquivo;
    
    char file[] = "usuarios.txt";
    
    arquivo = fopen(file,"r");
    
    if(arquivo == NULL){
        printf("***ERRO: Arquivo nao encontrado.***\n");
    } else {
      	fscanf(arquivo,"%s\t%s\t%[^\n]s",U.login,U.senha,U.Nome);
        while(!feof(arquivo)){
      		if(strcmp(U.login,Pessoa.login)==0){
      			Criptografia(Pessoa.senha);
      			if(strcmp(U.senha,Pessoa.senha)==0){
      				return 1;
				}
      		}
      		fscanf(arquivo,"%s\t%s\t%[^\n]s",U.login,U.senha,U.Nome);
        }
        
        fclose(arquivo);
        
        return 0;
  	}

}

int VerificaLogin(char *login){
	usuario U;
    
    FILE *arquivo;
    
    char file[] = "usuarios.txt";
    
    arquivo = fopen(file,"r");
    
    if(arquivo == NULL){
        printf("***ERRO: Arquivo nao encontrado.***\n");
    } else {
      	fscanf(arquivo,"%s\t%s\t%[^\n]s",U.login,U.senha,U.Nome);
        while(!feof(arquivo)){
      		if(strcmp(U.login,login)==0){
      			return 1;	
			  }
      		fscanf(arquivo,"%s\t%s\t%[^\n]s",U.login,U.senha,U.Nome);
        }
        
        fclose(arquivo);
        
        return 0;
  	}
}

void ExcluirUsuario(){
	usuario U;
    char login[20];
    int users = 0;
    
    printf("\n\nDigite o login de usuario que deseja excluir:");
    scanf("%s",login);
    getchar();

    FILE *arquivo,*arq;
    char file[] = "usuarios.txt", file2[]="arqauxiliar.txt";

    arquivo = fopen(file,"r");
    arq = fopen(file2,"w");

   	fscanf(arquivo,"%s\t%s\t%[^\n]s",U.login,U.senha,U.Nome);
    while(!feof(arquivo)){
		if(strcmp(U.login,login)!=0){
   			fprintf(arq,"%s\t%s\t%s\n",U.login,U.senha,U.Nome);
			users = 1;			
        }
      	fscanf(arquivo,"%s\t%s\t%[^\n]s",U.login,U.senha,U.Nome);
    }
        
    if(users == 0){
        	printf("***Usuario nao encontrado!***\n");
	} else {
		printf("***Usuario excluido!***");
	}
    
    
    fclose(arquivo);
    fclose(arq);
	
	remove(file);
	rename(file2,"usuarios.txt"); 
  
	Usuarios(); 
}

void AlterarUsuario(){
    usuario U;
    char login[20];
    int users = 0;
    
    printf("\n\nDigite o login de usuario que deseja alterar:");
    scanf("%s",login);
    getchar();
    
    FILE *arquivo,*arq;
    char file[] = "usuarios.txt", file2[]="arqauxiliar.txt";
    
    arquivo = fopen(file,"r");
    arq = fopen(file2,"w");
    
    if(arquivo == NULL){
        printf("***ERRO: Arquivo nao encontrado.***\n");
    } else {
      	fscanf(arquivo,"%s\t%s\t%[^\n]s",U.login,U.senha,U.Nome);
        while(!feof(arquivo)){
      		if(strcmp(U.login,login)==0){
      			printf("\n\n***Usuario encontrado.***\n\n");
      			do{
    				printf("Digite a nova senha (Minimo de 3 digitos):");
    				scanf("%[^\n]s",U.senha);
    				getchar();
				}while(strlen(U.senha)<3);
      			
      			Criptografia(U.senha);
      			
      			fprintf(arq,"%s\t%s\t%s\n",U.login,U.senha,U.Nome);
      			
				users = 1;
      			printf("\n***Senha alterada***\n");
      			
			  }	else {
			  	fprintf(arq,"%s\t%s\t%s\n",U.login,U.senha,U.Nome);
			  }
      		fscanf(arquivo,"%s\t%s\t%[^\n]s",U.login,U.senha,U.Nome);
        }
        if(users == 0){
        	printf("***Usuario nao encontrado!***\n");
		}
    
    
	    fclose(arquivo);
	    fclose(arq);
		
		remove(file);
		Usuarios();		
  	}
}

void ListarUsuario(){
    usuario U;

    FILE *arquivo;
    arquivo = fopen("usuarios.txt","r");
    
    if(arquivo == NULL){
        printf("***ERRO: Arquivo nao encontrado.***\n");
    }
    
    fscanf(arquivo,"%s\t%s\t%[^\n]s\n",U.login,U.senha,U.Nome);
    	while(!feof(arquivo)){
            printf("Nome:%-20s\tUsuario:%s\n",U.Nome,U.login);
            fscanf(arquivo,"%s\t%s\t%[^\n]s\n",U.login,U.senha,U.Nome);
        }
    
    fclose(arquivo);

    Usuarios();
}

void IncluirUsuario(){
	usuario U;
	int Verifica;
	
	printf("Digite o nome:");
	scanf("%[^\n]s",U.Nome);
	getchar();
	
	printf("Digite o login de usuario:");
	scanf("%[^\n]s",U.login);
	getchar();
	
	do{
    	printf("Digite a senha (Minimo de 3 digitos):");
    	scanf("%[^\n]s",U.senha);
    	getchar();
	}while(strlen(U.senha)<3);
    
    Verifica = VerificaLogin(U.login);
    
    while(Verifica == 1){
    	printf("***Usuario existente, por favor digite um usuario valido***\n");
    	printf("Digite o login de usuario:");
		scanf("%[^\n]s",U.login);
		getchar();
		
		Verifica = VerificaLogin(U.login);
	} 
		printf("\n\nNome:%s  \nLogin:%s \n",U.Nome,U.login);
    
	    Criptografia(U.senha);
    
    	FILE *arquivo;
	    arquivo = fopen("usuarios.txt","a");
    
    	if(arquivo == NULL){
	        printf("ERRO: Arquivo nao encontrado.\n");
	    } else {
    	    fprintf(arquivo,"%s\t%s\t%s\n",U.login,U.senha,U.Nome);
	    }
    
    	fclose(arquivo);
    
    	printf("\n***Usuario inserido com sucesso!***\n\n");
    	Usuarios();
	
}

void Criptografia(char *texto){
	int j,x,tam;
    char M[] = {"ABCDEFGHIJKLMNOPQRSTUVXWYZ"},m[] = {"abcdefghijklmnopqrstuvxwyz"},num[] = {"0123456789"};
       
        tam = strlen(texto);
        
        for(j = 0;j < tam;j++){
            for(x = 0;x < 26;x++){
                if(texto[j] == M[x]){
                    texto[j] = texto[j] + 3;
                    break;
                } else if (texto[j] == m[x]){
                    texto[j] = texto[j] + 3;
                    break;
                }                
            }
            
            for(x = 0;x < 10;x++){
            	if(texto[j] == num[x]){
            		texto[j] = texto[j] + 3;
            		break;
				}
			}
        }
        
        int aux;
        for(j = 0;j < tam;j = j+2){
        	if(texto[j] == texto[tam-1] && (tam-1) % 2 == 0){
        		break;
			}
        	aux = texto[j];
			texto[j] = texto[j+1];
			texto[j+1] = aux;
		}
		
		for(j = 0;j < tam;j++){
        	if(texto[j] == ' '){
        		texto[j] = '+';
    			
			}else if(texto[j] == '+'){
				texto[j] = ' ';	
			}
		}
}
