typedef struct{
    char Nome[50];
    char senha[15];
    char login[20];
}usuario;

int Usuarios();
void Criptografia(char *);
void IncluirUsuario();
void ExcluirUsuario();
void ListarUsuario();
void AlterarUsuario();
