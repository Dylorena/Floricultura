typedef struct{
	int idPlanta,anoplantio,idFamilia;
	char NomeCientifico[50];
	char frutifera;
	float valor;	
}Planta;

int Plantas();
void IncluirPlantas();
void ListarPlantas();
void OrdenaCodigoP(Planta *,int );
void OrdenaNomeP(Planta *,int);
void ExcluirPlanta();
int VerificaDuplicidade(char *,int );

/*Brofazsol	xiqixqirq	Erik
Brusqueta	rjdlv	Elderino
Goiases	rjdlq	Ronald
dylorena	|gro8<	Diana*/
