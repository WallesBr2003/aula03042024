#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Define o tamanho máximo da pilha

// Definindo a estrutura da pilha
typedef struct {
    int itens[MAX];
    int topo;
} Pilha;

// Função para inicializar a pilha
void inicializar(Pilha *p) {
    p->topo = -1;
}

// Função para verificar se a pilha está cheia
int cheia(Pilha *p) {
    return p->topo == MAX - 1;
}

// Função para verificar se a pilha está vazia
int vazia(Pilha *p) {
    return p->topo == -1;
}

// Função para inserir um elemento na pilha
void push(Pilha *p, int valor) {
    if (cheia(p)) {
        printf("Pilha cheia!\n");
        return;
    }
    p->itens[++(p->topo)] = valor;
    printf("%d inserido na pilha.\n", valor);
}

// Função para remover um elemento da pilha
int pop(Pilha *p) {
    if (vazia(p)) {
        printf("Pilha vazia!\n");
        return -1;  // Retorna -1 se a pilha estiver vazia
    }
    return p->itens[(p->topo)--];
}

int main() {
    Pilha pilha;
    inicializar(&pilha);
    int escolha, valor;

    while (1) {
        printf("Escolha uma opcao:\n");
        printf("1. Inserir na pilha\n");
        printf("2. Remover da pilha (\n");
        printf("3. Sair\n");
        printf("Opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                push(&pilha, valor);
                break;
            case 2:
                valor = pop(&pilha);
                if (valor != -1) {
                    printf("Valor removido: %d\n", valor);
                }
                break;
            case 3:
                printf("Saindo...\n");
                exit(0);
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    }

    return 0;
}

