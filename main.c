#include <stdio.h>
#include "funcoes.h"

int main(){
    int pos = 0;
    int opcao;
    int erro;

    contatos agenda[Total];

    do{
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

        // Inicio funções
        if (opcao != 0){
            if (opcao == 1){
                erro = add_contatos(&pos, agenda);
            }else if (opcao == 2){
                erro = del_contatos(&pos, agenda);
            }else if (opcao == 3){
                erro = listar_contatos(&pos, agenda);
            }else if (opcao == 4){
                erro = adicionar_arquivo_binario(&pos, agenda);
            }else if (opcao == 5){
                erro = carregar_arquivo_binario(&pos, agenda);
            }else {
                printf("Opção Inválida!");
            }
        }
        
        trat_erros(erro);

    } while(opcao != 0);

    printf("\nEncerrando programa...");
}
