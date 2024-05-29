#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX 100  // Define o tamanho máximo da fila

// Definindo a estrutura da fila
typedef struct {
    int itens[MAX];
    int frente, traseira;
} Fila;

// Função para inicializar a fila
void inicializar(Fila *f) {
    f->frente = -1;
    f->traseira = -1;
}

// Função para verificar se a fila está cheia
int cheia(Fila *f) {
    return (f->traseira + 1) % MAX == f->frente;
}

// Função para verificar se a fila está vazia
int vazia(Fila *f) {
    return f->frente == -1;
}

// Função para inserir um elemento na fila
void enqueue(Fila *f, int valor) {
    if (cheia(f)) {
        printf("Fila cheia!\n");
        return;
    }
    if (vazia(f)) {
        f->frente = 0;
    }
    f->traseira = (f->traseira + 1) % MAX;
    f->itens[f->traseira] = valor;
    printf("%d inserido na fila.\n", valor);
}

// Função para remover um elemento da fila
int dequeue(Fila *f) {
    if (vazia(f)) {
        printf("Fila vazia!\n");
        return -1;  // Retorna -1 se a fila estiver vazia
    }
    int valor = f->itens[f->frente];
    if (f->frente == f->traseira) {
        f->frente = -1;
        f->traseira = -1;
    } else {
        f->frente = (f->frente + 1) % MAX;
    }
    return valor;
}

// Função para mostrar os elementos da fila
void mostrarFila(Fila *f) {
    if (vazia(f)) {
        printf("Fila vazia!\n");
        return;
    }
    printf("Elementos na fila: ");
    int i = f->frente;
    while (i != f->traseira) {
        printf("%d ", f->itens[i]);
        i = (i + 1) % MAX;
    }
    printf("%d\n", f->itens[i]); // Print the last element
}

int main() {
    setlocale(LC_ALL,"Portuguese");
    Fila fila;
    inicializar(&fila);
    int escolha, valor;

    while (1) {
        printf("\nEscolha uma opção:\n");
        printf("1. Inserir na fila\n");
        printf("2. Remover da fila\n");
        printf("3. Mostrar fila\n");
        printf("4. Sair\n");
        printf("Opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                enqueue(&fila, valor);
                break;
            case 2:
                valor = dequeue(&fila);
                if (valor != -1) {
                    printf("Valor removido: %d\n", valor);
                }
                break;
            case 3:
                mostrarFila(&fila);
                break;
            case 4:
                printf("Saindo...\n");
                exit(0);
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    }

    return 0;
}

