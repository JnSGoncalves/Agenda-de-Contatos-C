#define Total 255

enum{OK, contatos_cheios, sem_contatos, nu_nao_encontrado, erro_escrever, erro_fechar, erro_abrir, nao_e_numero, erro_conversao, email_invalido};

typedef struct {
	char nome[Total];
	char sobrenome[Total];
	long long numero;
	char email[Total];
} contatos;


void clearBuffer();

int validar_email(char *email);
long long ver_numero();

int add_contatos(int *pos, contatos agenda[]);
int del_contatos(int *pos, contatos agenda[]);
int listar_contatos(int *pos, contatos agenda[]);
int adicionar_arquivo_binario(int *pos, contatos agenda[], const char* filename);
int carregar_arquivo_binario(int *pos, contatos agenda[], const char* filename);

int trat_erros(int erro);
