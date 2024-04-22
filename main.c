#include <stdio.h>

int main(){
    int pos;
    int opcao;

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

        switch (opcao){
            case 1:
                printf("Criar contato...\n");
                break;
            case 2:
                printf("Deletar contato...\n");
                break;
            case 3:
                printf("Listar contato...\n");
                break;
            case 4:
                printf("Salvar contatos...\n");
                break;
            case 5:
                printf("Carregar contatos...\n");
                break;
        }

    } while(opcao != 0);

    printf("\nEncerrando programa...");
}