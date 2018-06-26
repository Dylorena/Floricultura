#include<stdio.h>
//#include"Familia.c"
#include"Plantas.c"
#include"Usuarios.c"


void montarMenu();

int main(){
	
	montarMenu();

}

void montarMenu(){
	int opcaoGeral,retorno;
	do {
		printf("\n\n-------------------FLORICULTURA-------------------\n\n");
		printf("1 - Plantas\n2 - Familia\n3 - Analise de Dados\n4 - Controle de Acesso\n0 - Sair");
		printf("\nOpcao:");
		scanf("%d",&opcaoGeral);
				
		switch(opcaoGeral){
			case 1:
				//retorno = Plantas();
				if(retorno == 1){
					montarMenu;
				}
			break;
			case 2:
			    //retorno = Familias();
				if(retorno == 1){
					montarMenu;
				}
			break;
			case 3:
				//AnaliseDados();
			break;
			case 4:
				retorno = Usuarios();
				if(retorno == 1){
					montarMenu;
				}
			break;
		}
	}while(opcaoGeral != 0);
}
