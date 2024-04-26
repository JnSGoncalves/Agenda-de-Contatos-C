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

	return OK;
}


// 2. Deletar contato
int del_contatos(int *pos, contatos agenda[]){
	if (*pos == 0) {
		return sem_contatos;
	}

	printf("Digite o número de telefone do contato que deseja excluir: ");
	long numero;
	scanf("%ld", &numero);

	// Procura a posição do número no array
	int del_pos;
	for(del_pos = 0; del_pos < *pos;del_pos++ ){
		if (agenda[del_pos].numero == numero){
			break;
		}
	}
	if (del_pos == *pos || del_pos < 0){
		return nu_nao_encontrado;
	}
	else{
		for (int i = del_pos; i < *pos; i++){
			strcpy(agenda[i].nome, agenda[i+1].nome);
			strcpy(agenda[i].sobrenome, agenda[i+1].sobrenome);
			agenda[i].numero = agenda[i+1].numero;
			strcpy(agenda[i].email, agenda[i+1].email);
		}
		*pos = *pos - 1;
		printf("Contato excluido!\n");
		return OK;
	}
}


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
			printf("email: %s\n\n", agenda[i].email);
		}        
	}
	return OK;
}

// 4. Salvar contatos
int adicionar_arquivo_binario(int *pos, contatos agenda[]){
    FILE *f = fopen("tarefas.bin", "wb");
    if(f == NULL){
        return erro_abrir;
    }

    for (int i = 0; i < *pos; i++) {
        if (fwrite(&agenda[i], sizeof(contatos), 1, f) != 1) {
            fclose(f);
            return erro_escrever;
        }
    }

    fclose(f);
    printf("Contatos salvos no arquivo binário com sucesso.\n");
    return OK;
}

// 5. Carregar contatos
int carregar_arquivo_binario(int *pos, contatos agenda[]) {
    FILE *f = fopen("tarefas.bin", "rb");
    if (f == NULL) {
        return erro_abrir;
    }

    contatos contato;

	int pos_load = 0;
    while (fread(&contato, sizeof(contatos), 1, f) == 1) {
        agenda[pos_load] = contato;
        (pos_load)++;
    }

	*pos = pos_load;

    fclose(f);
    printf("Contatos carregados do arquivo binário com sucesso.\n");
    return OK;
}

// OK, contatos_cheios, sem_contatos, nu_nao_encontrado, erro_escrever, erro_fechar, erro_abrir
int trat_erros(int erro){
	if (erro != OK){
		if (erro == contatos_cheios){
			printf("Agenda lotada!\n");
			printf("Exclua algum contato para adicionar mais!.\n");
		}else if (erro == sem_contatos){
			printf("Não existem contatos cadastrados.\n");
		}else if (erro == nu_nao_encontrado){
			printf("Número de telefone não encontrado\n");
		}else if (erro == erro_escrever){
			printf("Erro ao salvar arquivo binário!\n");
		}else if (erro == erro_fechar){
			printf("Erro ao fechar arquivo binário!\n");
		}else if (erro == erro_abrir){
			printf("Erro ao abrir arquivo binário!");
		}
	}
}

void clearBuffer(){
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}