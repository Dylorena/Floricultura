typedef struct{
	int idFamilia;
	char nome[50];
}familia;

int Familias();
void IncluirFamilia();
void ListarFamilia();
void OrdenaCodigo(familia *,int);
void OrdenaNome(familia *,int);
int VerificaId(int);
void ExcluirFamilia();
int VerificaPlantasnaFamilia(int);
