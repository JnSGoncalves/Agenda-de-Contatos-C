#define Total 255

enum{OK, contatos_cheios, sem_contatos};

typedef struct {
    char nome[Total];
    char sobrenome[Total];
    long numero;
    char email[Total];
} contatos;


void clearBuffer();

int add_contatos(int *pos, contatos agenda[]);
int listar_contatos(int *pos, contatos agenda[]);

int trat_erros(int erro);

// Protótipo da função para carregar contatos de um arquivo binário
void carregar_contatos(const char *nome_arquivo, int *pos, contatos agenda[]);
