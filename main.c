#include <stdio.h>
#include "funcoes.h"

int main() {
    int posPessoal = 0, posTrabalho = 0;
    int opcao;
    int tipo;
    int erro;

    contatos agendaPessoal[Total];
    contatos agendaTrabalho[Total];

    do {
        // Menu print
        printf("\nAgenda de contatos\n\n");
        printf("1. Criar contato\n");
        printf("2. Deletar contato\n");
        printf("3. Listar contato\n");
        printf("4. Salvar contatos\n");
        printf("5. Carregar contatos\n");
        printf("0. Sair\n\n");

        // Opção menu
        printf("Digite o número da opção desejada: ");
        scanf("%d", &opcao);
        printf("\n");

        if (opcao != 0 && opcao != 4 && opcao != 5) {
            printf("Escolha o tipo de contato:\n");
            printf("1. Pessoal\n");
            printf("2. Trabalho\n");
            printf("Digite o tipo de contato: ");
            scanf("%d", &tipo);
            printf("\n");
        }

        // Inicio funções
        if (opcao != 0) {
            if (opcao == 1) {
                if (tipo == 1) {
                    erro = add_contatos(&posPessoal, agendaPessoal);
                } else if (tipo == 2) {
                    erro = add_contatos(&posTrabalho, agendaTrabalho);
                } else {
                    printf("Opção Inválida!");
                }
            } else if (opcao == 2) {
                if (tipo == 1) {
                    erro = del_contatos(&posPessoal, agendaPessoal);
                } else if (tipo == 2) {
                    erro = del_contatos(&posTrabalho, agendaTrabalho);
                } else {
                    printf("Opção Inválida!");
                }
            } else if (opcao == 3) {
                if (tipo == 1) {
                    erro = listar_contatos(&posPessoal, agendaPessoal);
                } else if (tipo == 2) {
                    erro = listar_contatos(&posTrabalho, agendaTrabalho);
                } else {
                    printf("Opção Inválida!");
                }
            } else if (opcao == 4) {
                erro = adicionar_arquivo_binario(&posPessoal, agendaPessoal, "contatos_pessoais.bin");
                trat_erros(erro);
                erro = adicionar_arquivo_binario(&posTrabalho, agendaTrabalho, "contatos_trabalho.bin");
            } else if (opcao == 5) {
                erro = carregar_arquivo_binario(&posPessoal, agendaPessoal, "contatos_pessoais.bin");
                trat_erros(erro);
                erro = carregar_arquivo_binario(&posTrabalho, agendaTrabalho, "contatos_trabalho.bin");
            } else {
                printf("Opção Inválida!");
            }
        } else{
            erro = OK;
        }

        trat_erros(erro);

    } while (opcao != 0);

    printf("\nEncerrando programa...\n");
}