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
int listar_contatos(contatos agenda[]);

int trat_erros(int erro);