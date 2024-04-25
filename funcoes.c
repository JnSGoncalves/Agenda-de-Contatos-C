#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "funcoes.h"

// 1. Criar contato
// Erro ao mudar o valor da posição
int add_contatos(int *pos, contatos agenda[]){
    if (*pos >= Total){
        printf("Agenda lotada!\n");
        printf("Exclua algum contato para adicionar mais!.\n");
        return 1;
    }

    printf("Digite os dados do contato que queira adicionar.\n\n");

    clearBuffer();

    printf("Nome: ");
    fgets(agenda[*pos].nome, Total, stdin);


    printf("Sobrenome: ");
    fgets(agenda[*pos].sobrenome, Total, stdin);


    printf("Número de Telefone (DDD+Número - 15994204917): ");
    scanf("%d", &agenda[*pos].numero);

    clearBuffer();

    printf("Email: ");
    fgets(agenda[*pos].email, Total, stdin);
    printf("\n");

    *pos = *pos + 1;

    printf("\nContado adicionado com sucesso!\n");

    return 0;
}

// 2. Deletar contato
// 3. Listar contato
// 4. Salvar contatos
// 5. Carregar contatos
// 0. Sair


void clearBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}