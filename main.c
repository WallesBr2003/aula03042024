#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Definindo a estrutura do ponto
typedef struct {
    int Id;     // Identificador do ponto
    float PX;   // Coordenada X do ponto
    float PY;   // Coordenada Y do ponto
} Ponto;

// Definindo a estrutura do indiv�duo
typedef struct {
    int Individuo[10];  // Vetor que representa a rota dos pontos (de 0 a 9)
    float Valor;        // Custo total da rota
} Individuo;

// Fun��o para calcular a dist�ncia euclidiana entre dois pontos
float calcular_distancia(Ponto a, Ponto b) {
    // Calcula a dist�ncia euclidiana usando a f�rmula da dist�ncia
    return sqrt(pow(a.PX - b.PX, 2) + pow(a.PY - b.PY, 2));
}

// Fun��o de compara��o para ordenar os indiv�duos pelo valor
int comparar_individuos(const void *a, const void *b) {
    Individuo *indA = (Individuo *)a;
    Individuo *indB = (Individuo *)b;
    // Retorna um valor negativo, zero ou positivo se indA for, respectivamente,
    // menor, igual ou maior que indB em termos de valor de rota (Valor)
    return (indA->Valor > indB->Valor) - (indA->Valor < indB->Valor);
}

// Fun��o para preencher um vetor de inteiros de 0 a 9 sem repeti��o
void preencher_vetor_individuo(int vetor[10]) {
    int i, j, temp;
    // Inicializa o vetor com valores de 0 a 9
    for (i = 0; i < 10; i++) {
        vetor[i] = i;
    }
    // Embaralha os elementos do vetor aleatoriamente
    for (i = 0; i < 10; i++) {
        j = rand() % 10;
        temp = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = temp;
    }
}

// Fun��o para criar e preencher o vetor Pontos
void preencher_pontos(Ponto pontos[10]) {
    int i;
    // Atribui um ID e coordenadas X e Y aleat�rias para cada ponto
    for (i = 0; i < 10; i++) {
        pontos[i].Id = i;
        pontos[i].PX = (float)rand() / RAND_MAX * 100;
        pontos[i].PY = (float)rand() / RAND_MAX * 100;
    }
}

// Fun��o para calcular a matriz de dist�ncias
void calcular_matriz_distancias(float dist[10][10], Ponto pontos[10]) {
    int i, j;
    // Calcula a dist�ncia entre todos os pares de pontos
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (i == j) {
                dist[i][j] = 0.0;  // Dist�ncia de um ponto para ele mesmo � zero
            } else {
                dist[i][j] = calcular_distancia(pontos[i], pontos[j]);
            }
        }
    }
}

// Fun��o para preencher a popula��o com rotas e calcular seus valores
void preencher_populacao(Individuo populacao[100], float dist[10][10]) {
    int i, j;
    // Preenche cada indiv�duo na popula��o
    for (i = 0; i < 100; i++) {
        // Gera uma rota aleat�ria sem repeti��o de pontos
        preencher_vetor_individuo(populacao[i].Individuo);

        // Calcula o valor (custo) da rota
        populacao[i].Valor = 0.0;
        for (j = 0; j < 9; j++) {
            int ponto_a = populacao[i].Individuo[j];
            int ponto_b = populacao[i].Individuo[j + 1];
            // Soma a dist�ncia entre os pontos adjacentes na rota
            populacao[i].Valor += dist[ponto_a][ponto_b];
        }
        // Fechando o ciclo (voltando ao ponto inicial)
        int ponto_a = populacao[i].Individuo[9];
        int ponto_b = populacao[i].Individuo[0];
        // Adiciona a dist�ncia para retornar ao ponto inicial
        populacao[i].Valor += dist[ponto_a][ponto_b];
    }
}

// Fun��o para exibir a popula��o ordenada
void exibir_populacao(Individuo populacao[100]) {
    int i, j;
    // Exibe cada indiv�duo na popula��o
    for (i = 0; i < 100; i++) {
        printf("Individuo %d: Rota = [", i + 1);
        // Exibe a rota do indiv�duo
        for (j = 0; j < 10; j++) {
            printf("%d ", populacao[i].Individuo[j]);
        }
        printf("] Valor = %.2f\n", populacao[i].Valor);
    }
}

int main() {
    // Inicializa a semente do gerador de n�meros aleat�rios
    srand(time(NULL));

    // Criando e preenchendo o vetor Pontos com 10 elementos
    Ponto Pontos[10];
    preencher_pontos(Pontos);

    // Criando a matriz Dist de 10x10 para armazenar as dist�ncias euclidianas
    float Dist[10][10];
    calcular_matriz_distancias(Dist, Pontos);

    // Criando e preenchendo o vetor Populacao com 100 elementos
    Individuo Populacao[100];
    preencher_populacao(Populacao, Dist);

    // Ordenando a popula��o pelo campo Valor (custo da rota)
    qsort(Populacao, 100, sizeof(Individuo), comparar_individuos);

    // Exibindo a popula��o ordenada
    exibir_populacao(Populacao);

    return 0;
}

