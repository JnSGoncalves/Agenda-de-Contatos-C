#define Total 255

enum{OK, contatos_cheios, sem_contatos, nu_nao_encontrado, erro_escrever, erro_fechar, erro_abrir, nao_e_numero, erro_conversao};

typedef struct {
	char nome[Total];
	char sobrenome[Total];
	long numero;
	char email[Total];
} contatos;


void clearBuffer();

long ver_numero();

int add_contatos(int *pos, contatos agenda[]);
int del_contatos(int *pos, contatos agenda[]);
int listar_contatos(int *pos, contatos agenda[]);
int adicionar_arquivo_binario(int *pos, contatos agenda[]);
int carregar_arquivo_binario(int *pos, contatos agenda[]);
int numero_existe(long numero, int *pos, contatos agenda[]);
int trat_erros(int erro);
