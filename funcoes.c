#include <stdio.h>
#include <string.h>
#include "funcoes.h"

int numero_existe(long numero, int *pos, contatos agenda[]) {
    for (int i = 0; i < *pos; i++) {
        if (agenda[i].numero == numero) {
            return 1;
        }
    }
    return 0;
}

int validar_email(char *email){
	char *character = email;

	int ver_arroba = 0;
	int ver_ponto = 0;
	while (*character != '\0'){
		if (*character == '@' && *(character + 1) != '.'){
			if (ver_arroba == 1){
				return 0;
			}
			ver_arroba = 1;

		}else if (*character == '.' && *(character - 1) != '@' && *(character + 1) != '\0'){
			if (ver_ponto == 1 || *(character + 1) == '@' || *(character + 1) == '.'){
				return 0;
			}
			if (ver_arroba == 1){
				ver_ponto = 1;
			}
		}

		(character)++;
	}

	if (ver_arroba && ver_ponto){
		return 1;
	}else{
		return 0;
	}
}


long long ver_numero() {
    long long numero;

    if (scanf("%lld", &numero) != 1) {
        printf("Entrada inválida. Digite apenas números.\n");
        clearBuffer();
        return nao_e_numero;
    }

    if (numero <= 0) {
        printf("Entrada inválida.\n");
        return nao_e_numero;
    }

    return numero;
}

// 1. Criar contato
int add_contatos(int *pos, contatos agenda[]) {
    if (*pos >= Total) {
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


	long long ver;
	do{
		printf("Número de Telefone (DDD+Número - 15994204917): ");
		ver = ver_numero();
        if (numero_existe(ver, pos, agenda)) {
            printf("Número de telefone já existe. Digite um número único.\n");
            ver = nao_e_numero;
        }
	}while (ver == nao_e_numero || ver == erro_conversao);
	agenda[*pos].numero = ver;

    clearBuffer();

    int val_email;
    char email[Total];
    do{
        printf("Email: ");
        fgets(email, Total, stdin);
        email[strcspn(email, "\n")] = '\0';
        val_email = validar_email(email);
        if (val_email != 1){
            printf("Email inválido.\n");
        }
    }while (val_email != 1);
	strcpy(agenda[*pos].email, email);

    *pos = *pos + 1;

    printf("\nContato adicionado com sucesso!\n");

    return OK;
}

// 2. Deletar contato
int del_contatos(int *pos, contatos agenda[]) {
    if (*pos == 0) {
        return sem_contatos;
    }

    long long ver;
    do {
        printf("Digite o número de telefone do contato que deseja excluir: ");
        ver = ver_numero();
    } while (ver == nao_e_numero || ver == erro_conversao);
    long long numero = ver;

    // Procura a posição do número no array
    int del_pos;
    for (del_pos = 0; del_pos < *pos; del_pos++) {
        if (agenda[del_pos].numero == numero) {
            break;
        }
    }
    if (del_pos == *pos || del_pos < 0) {
        return nu_nao_encontrado;
    } else {
        for (int i = del_pos; i < *pos - 1; i++) {
            strcpy(agenda[i].nome, agenda[i + 1].nome);
            strcpy(agenda[i].sobrenome, agenda[i + 1].sobrenome);
            agenda[i].numero = agenda[i + 1].numero;
            strcpy(agenda[i].email, agenda[i + 1].email);
        }
        *pos = *pos - 1;
        printf("Contato excluído!\n");
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
        if (strlen(agenda[i].nome) > 0) {
            printf("Nome: %s\n", agenda[i].nome);
            printf("Sobrenome: %s\n", agenda[i].sobrenome);
            printf("Telefone: %lld\n", agenda[i].numero);
            printf("Email: %s\n\n", agenda[i].email);
        }
    }
    return OK;
}

// 4. Salvar contatos
int adicionar_arquivo_binario(int *pos, contatos agenda[], const char* filename) {
    FILE *f = fopen(filename, "wb");
    if (f == NULL) {
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
int carregar_arquivo_binario(int *pos, contatos agenda[], const char* filename) {
    FILE *f = fopen(filename, "rb");
    if (f == NULL) {
        return erro_abrir;
    }

    contatos contato;

    int pos_load = 0;
    while (fread(&contato, sizeof(contatos), 1, f) == 1) {
        agenda[pos_load] = contato;
        pos_load++;
    }

    *pos = pos_load;

    fclose(f);
    printf("Contatos carregados do arquivo binário com sucesso.\n");
    return OK;
}

// Tratamento de erros
int trat_erros(int erro) {
    if (erro != OK) {
        if (erro == contatos_cheios) {
            printf("Agenda lotada!\n");
            printf("Exclua algum contato para adicionar mais!.\n");
        } else if (erro == sem_contatos) {
            printf("Não existem contatos cadastrados.\n");
        } else if (erro == nu_nao_encontrado) {
            printf("Número de telefone não encontrado\n");
        } else if (erro == erro_escrever) {
            printf("Erro ao salvar arquivo binário!\n");
        } else if (erro == erro_fechar) {
            printf("Erro ao fechar arquivo binário!\n");
        } else if (erro == erro_abrir) {
            printf("Erro ao abrir arquivo binário!\n");
        }
    }
    return erro;
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}