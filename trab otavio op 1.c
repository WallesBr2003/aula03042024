#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DESCRICAO 100

void adicionar_tarefa() {
    FILE *arquivo;
    char data[11], descricao[MAX_DESCRICAO];

    printf("Digite a data da tarefa (formato: DD-MM-AAAA): ");
    scanf("%s", data);
    printf("Digite a descricao da tarefa: ");
    scanf(" %[^\n]s", descricao);

    arquivo = fopen("tarefas.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    fprintf(arquivo, "%s - %s\n", data, descricao);
    fclose(arquivo);

    printf("Tarefa adicionada com sucesso!\n");
}

void mostrar_tarefas_do_dia() {
    FILE *arquivo;
    char data_atual[11], linha[120];
    time_t t = time(NULL);
    struct tm *tm_struct = localtime(&t);
    strftime(data_atual, sizeof(data_atual), "%d-%m-%Y", tm_struct);

    arquivo = fopen("tarefas.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    printf("Tarefas para o dia de hoje:\n");
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        if (strncmp(linha, data_atual, 10) == 0) {
            printf("- %s", linha + 11);
        }
    }

    fclose(arquivo);
}

int main() {
    int opcao;

    while (1) {
        printf("\nMenu\n");
        printf("1. Nova tarefa\n");
        printf("2. Tarefas do dia\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionar_tarefa();
                break;
            case 2:
                mostrar_tarefas_do_dia();
                break;
            case 3:
                printf("Saindo do programa...\n");
                exit(0);
            default:
                printf("Opção inválida, tente novamente.\n");
        }
    }

    return 0;
}

