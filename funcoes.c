#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "funcoes.h"

// 1. Criar contato
// Erro ao mudar o valor da posição
int add_contatos(int *pos, contatos agenda[]){
    if (*pos >= Total){
        return contatos_cheios;
    }

    printf("Digite os dados do contato que queira adicionar.\n\n");

    clearBuffer();

    printf("Nome: ");
    fgets(agenda[*pos].nome, Total, stdin);
    agenda[*pos].nome[strcspn(agenda[*pos].nome, "\n")] = '\0';

    printf("Sobrenome: ");
    fgets(agenda[*pos].sobrenome, Total, stdin);
    agenda[*pos].sobrenome[strcspn(agenda[*pos].sobrenome, "\n")] = '\0';

    printf("Número de Telefone (DDD+Número - 15994204917): ");
    scanf("%ld", &agenda[*pos].numero);

    clearBuffer();

    printf("Email: ");
    fgets(agenda[*pos].email, Total, stdin);
    agenda[*pos].email[strcspn(agenda[*pos].email, "\n")] = '\0';

    *pos = *pos + 1;

    printf("\nContado adicionado com sucesso!\n");

    return 0;
}


// 2. Deletar contato

// 3. Listar contato
int listar_contatos(int *pos, contatos agenda[]) {
    if (*pos == 0) {
        return sem_contatos;
    }
    printf("Lista de contatos:\n\n");
    for (int i = 0; i < *pos; i++) {
        if (strlen(agenda[i].nome) > 0){
            printf("Nome: %s\n", agenda[i].nome);
            printf("Sobrenome: %s\n", agenda[i].sobrenome);
            printf("Telefone: %ld\n", agenda[i].numero);
            printf("email: %s\n", agenda[i].email);
        }        
    }
    return OK;
}


// 4. Salvar contatos
// 5. Carregar contatos

// 5. Carregar contatos
void carregar_contatos(const char *nome_arquivo, int *pos, contatos agenda[]) {
    // Abre o arquivo para leitura em modo binário
    FILE *arquivo = fopen(nome_arquivo, "rb");

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo != NULL) {
        // Lê os dados do arquivo para a agenda
        fread(agenda, sizeof(contatos), Total, arquivo);

        // Determina a posição correta baseada no número de contatos lidos
        fseek(arquivo, 0, SEEK_END);
        *pos = ftell(arquivo) / sizeof(contatos);

        // Fecha o arquivo após a leitura
        fclose(arquivo);
        printf("Contatos carregados com sucesso do arquivo %s\n", nome_arquivo);
    } else {
        printf("Erro ao abrir o arquivo %s\n", nome_arquivo);
    }
}

int trat_erros(int erro){
    if (erro != OK){
        if (erro == contatos_cheios){
            printf("Agenda lotada!\n");
            printf("Exclua algum contato para adicionar mais!.\n");
        }else if (erro == sem_contatos){
            
        }
    }
    
}

void clearBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}