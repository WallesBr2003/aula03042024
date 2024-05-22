#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_DESCRICAO 100
#define MAX_TAREFAS 100

struct Tarefa {
    char data[11]; 
    char descricao[MAX_DESCRICAO];
};

void adicionar_tarefa(struct Tarefa tarefas[], int *num_tarefas) {
    if (*num_tarefas >= MAX_TAREFAS) {
        printf("Limite de tarefas alcançado.\n");
        return;
    }

    printf("Digite a data da tarefa (DD-MM-AAAA): ");
    scanf("%s", tarefas[*num_tarefas].data);

    printf("Digite a descricao da tarefa: ");
    scanf(" %[^\n]s", tarefas[*num_tarefas].descricao);

    (*num_tarefas)++;
    printf("Tarefa adicionada com sucesso!\n");
}

void mostrar_tarefas_do_dia(struct Tarefa tarefas[], int num_tarefas) {
    char data_atual[11];
    time_t t = time(NULL);
    struct tm *tm_struct = localtime(&t);
    strftime(data_atual, sizeof(data_atual), "%d-%m-%Y", tm_struct);

    int encontrou_tarefa = 0;
    printf("Tarefas para o dia de hoje:\n");
    int i = 0;
    while (i < num_tarefas) {
        if (strncmp(tarefas[i].data, data_atual, 10) == 0) {
            printf("- %s\n", tarefas[i].descricao);
            encontrou_tarefa = 1;
        }
        i++;
    }

    if (!encontrou_tarefa) {
        printf("Nao ha tarefas para hoje.\n");
    }
}

int main() {
    struct Tarefa tarefas[MAX_TAREFAS];
    int num_tarefas = 0;
    int opcao;

    while (1) {
        printf("\n     Menu    \n");
        printf("1. Nova tarefa\n");
        printf("2. Tarefas do dia atual \n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionar_tarefa(tarefas, &num_tarefas);
                break;
            case 2:
                mostrar_tarefas_do_dia(tarefas, num_tarefas);
                break;
            case 3:
                printf("Saindo do programa...\n");
                exit(0);
            default:
                printf("Opcao invalida, tente novamente.\n");
        }
    }

    return 0;
}

