// Este programa implementa e avalia diferentes algoritmos de ordenação conforme as especificações do Projeto 2.
// Universidade de São Paulo - ICMC
// Disciplina: Introdução à Ciência de Computação II
// Tarefa: Comparar algoritmos de ordenação quanto ao número de comparações, movimentações e tempo de execução.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vetores.h"

// Protótipo da função de ordenação, permitindo passar diferentes algoritmos como parâmetro
typedef void (*AlgOrdenacao)(int *, int); 

// Funções auxiliares para execução de algoritmos específicos
void executar_ordenacao(AlgOrdenacao alg_ordenacao, int *vetor, int tamanho);
void quicksort_wrapper(int *vetor, int tamanho);
void shellsort_wrapper(int *vetor, int tamanho);
void mergesort_wrapper(int *vetor, int tamanho);
void rearranjar_heap(int v[], int i, int tamanho_do_heap);
void construir_heap(int v[], int n);
void merge(int v[], int inf, int meio, int sup);
int obter_maior(int v[], int n);
void contar_classificar(int v[], int n, int exp);
 
// Declaração dos algoritmos de ordenação implementados
void bubblesort(int v[], int n);
void selection_sort(int num[], int tam);
void insertion_sort(int v[], int n);
void shellsort(int v[], int n, int incrementos[], int numinc);
void quicksort(int v[], int inf, int sup);
void heapsort(int v[], int n);
void mergesort(int v[], int inf, int sup);
void contagem_de_menores(int v[], int n);
void radixsort(int v[], int n);

int main(void){

    // Variáveis para configurar os testes
    int id_ordenacao;  // Identifica o algoritmo de ordenação
    int tam_vetor;     // Tamanho do vetor a ser ordenado
    int padrao_vetor;  // Tipo de vetor (ordenado, inverso ou aleatório)
    int id_vetor_aleatorio; // Identifica o vetor aleatório específico (1..5)

    clock_t inicio, fim;  // Para medir o tempo de execução
    double tempo_ordenacao; // Armazena o tempo gasto na ordenação

    // Menu interativo para o usuário escolher o algoritmo e as condições de teste
    printf("Digite o codigo do algoritmo de ordenacao:\n\n");
    printf("0: BubbleSort \n1: SelectionSort \n2: InsertionSort \n3: ShellSort \n4: QuickSort \n5: HeapSort \n6: MergeSort \n7: Contagem de Menores \n8: RadixSort\n\n");
    printf("Codigo: ");
    scanf("%d", &id_ordenacao);

    printf("\nIndique o numero de elementos no vetor:\n");
    printf("100: 100 elementos \n1000: 1.000 elementos \n10000: 10.000 elementos \n100000: 100.000 elementos\n\n");
    printf("Tamanho: ");
    scanf("%d", &tam_vetor);

    printf("\nEscolha o formato do arranjo de elementos no vetor:\n\n");
    printf("0: Aleatorios \n1: Ordenados \n2: Inversamente Ordenados\n\n");
    printf("Formato: ");
    scanf("%d", &padrao_vetor);

    // Determina o vetor específico para casos aleatórios (5 versões disponíveis)
    if (padrao_vetor == 0)
    {
        printf("Informe qual dos vetores aleatorios deve ser ordenado (1..5): ");
        scanf("%d", &id_vetor_aleatorio);
        id_vetor_aleatorio--;
    }

    /*
    * O bloco de código abaixo utiliza um switch para determinar qual algoritmo de ordenação será executado,
    * com base na escolha do usuário (armazenada na variável 'id_ordenacao'). Ele também considera o tamanho 
    * do vetor a ser ordenado (armazenado em 'tam_vetor') e o padrão dos elementos no vetor (armazenado em 'padrao_vetor').
    *
    * Funcionalidades principais:
    * 1. Determina o algoritmo de ordenação a ser utilizado:
    *    - BubbleSort, SelectionSort, InsertionSort, ShellSort, QuickSort, HeapSort, MergeSort,
    *      Contagem de Menores ou RadixSort.
    *
    * 2. Para cada algoritmo, verifica o tamanho do vetor (100, 1.000, 10.000 ou 100.000 elementos).
    *
    * 3. Em seguida, adapta a execução com base no padrão do vetor:
    *    - Ordenado: elementos já em ordem crescente.
    *    - Inversamente Ordenado: elementos em ordem decrescente.
    *    - Aleatório: elementos dispostos de forma randômica (com 5 versões disponíveis para cada tamanho).
    *
    * 4. Finalmente, chama a função 'executar_ordenacao', que encapsula:
    *    - A execução do algoritmo escolhido.
    *    - A medição do tempo de execução.
    *    - A exibição dos resultados antes e depois da ordenação.
    *
    * A estrutura utiliza nested switches (switch aninhados) para organizar as opções:
    * - O primeiro switch identifica o algoritmo de ordenação (com base em 'id_ordenacao').
    * - O segundo switch, dentro de cada case, avalia o tamanho do vetor (com base em 'tam_vetor').
    * - Estruturas condicionais ('if' e 'else if') verificam o padrão do vetor e selecionam a versão apropriada.
    */

    switch (id_ordenacao) {
    case 0: // BubbleSort
        switch (tam_vetor) {
            case 100:
                if (padrao_vetor == 1)
                    executar_ordenacao(bubblesort, vetor_100_ordenado, 100);
                else if (padrao_vetor == 2)
                    executar_ordenacao(bubblesort, vetor_100_inverso, 100);
                else
                    executar_ordenacao(bubblesort, vetor_100_aleatorio[id_vetor_aleatorio], 100);
                break;
            case 1000:
                if (padrao_vetor == 1)
                    executar_ordenacao(bubblesort, vetor_1000_ordenado, 1000);
                else if (padrao_vetor == 2)
                    executar_ordenacao(bubblesort, vetor_1000_inverso, 1000);
                else
                    executar_ordenacao(bubblesort, vetor_1000_aleatorio[id_vetor_aleatorio], 1000);
                break;
            case 10000:
                if (padrao_vetor == 1)
                    executar_ordenacao(bubblesort, vetor_10000_ordenado, 10000);
                else if (padrao_vetor == 2)
                    executar_ordenacao(bubblesort, vetor_10000_inverso, 10000);
                else
                    executar_ordenacao(bubblesort, vetor_10000_aleatorio[id_vetor_aleatorio], 10000);
                break;
            case 100000:
                if (padrao_vetor == 1)
                    executar_ordenacao(bubblesort, vetor_100000_ordenado, 100000);
                else if (padrao_vetor == 2)
                    executar_ordenacao(bubblesort, vetor_100000_inverso, 100000);
                else
                    executar_ordenacao(bubblesort, vetor_100000_aleatorio[id_vetor_aleatorio], 100000);
                break;
        }
        break;

    case 1: // SelectionSort
        switch (tam_vetor) {
            case 100:
                if (padrao_vetor == 1)
                    executar_ordenacao(selection_sort, vetor_100_ordenado, 100);
                else if (padrao_vetor == 2)
                    executar_ordenacao(selection_sort, vetor_100_inverso, 100);
                else
                    executar_ordenacao(selection_sort, vetor_100_aleatorio[id_vetor_aleatorio], 100);
                break;
            case 1000:
                if (padrao_vetor == 1)
                    executar_ordenacao(selection_sort, vetor_1000_ordenado, 1000);
                else if (padrao_vetor == 2)
                    executar_ordenacao(selection_sort, vetor_1000_inverso, 1000);
                else
                    executar_ordenacao(selection_sort, vetor_1000_aleatorio[id_vetor_aleatorio], 1000);
                break;
            case 10000:
                if (padrao_vetor == 1)
                    executar_ordenacao(selection_sort, vetor_10000_ordenado, 10000);
                else if (padrao_vetor == 2)
                    executar_ordenacao(selection_sort, vetor_10000_inverso, 10000);
                else
                    executar_ordenacao(selection_sort, vetor_10000_aleatorio[id_vetor_aleatorio], 10000);
                break;
            case 100000:
                if (padrao_vetor == 1)
                    executar_ordenacao(selection_sort, vetor_100000_ordenado, 100000);
                else if (padrao_vetor == 2)
                    executar_ordenacao(selection_sort, vetor_100000_inverso, 100000);
                else
                    executar_ordenacao(selection_sort, vetor_100000_aleatorio[id_vetor_aleatorio], 100000);
                break;
        }
        break;

    case 2: // InsertionSort
        switch (tam_vetor) {
            case 100:
                if (padrao_vetor == 1)
                    executar_ordenacao(insertion_sort, vetor_100_ordenado, 100);
                else if (padrao_vetor == 2)
                    executar_ordenacao(insertion_sort, vetor_100_inverso, 100);
                else
                    executar_ordenacao(insertion_sort, vetor_100_aleatorio[id_vetor_aleatorio], 100);
                break;
            case 1000:
                if (padrao_vetor == 1)
                    executar_ordenacao(insertion_sort, vetor_1000_ordenado, 1000);
                else if (padrao_vetor == 2)
                    executar_ordenacao(insertion_sort, vetor_1000_inverso, 1000);
                else
                    executar_ordenacao(insertion_sort, vetor_1000_aleatorio[id_vetor_aleatorio], 1000);
                break;
            case 10000:
                if (padrao_vetor == 1)
                    executar_ordenacao(insertion_sort, vetor_10000_ordenado, 10000);
                else if (padrao_vetor == 2)
                    executar_ordenacao(insertion_sort, vetor_10000_inverso, 10000);
                else
                    executar_ordenacao(insertion_sort, vetor_10000_aleatorio[id_vetor_aleatorio], 10000);
                break;
            case 100000:
                if (padrao_vetor == 1)
                    executar_ordenacao(insertion_sort, vetor_100000_ordenado, 100000);
                else if (padrao_vetor == 2)
                    executar_ordenacao(insertion_sort, vetor_100000_inverso, 100000);
                else
                    executar_ordenacao(insertion_sort, vetor_100000_aleatorio[id_vetor_aleatorio], 100000);
                break;
        }
        break;

    case 3: // ShellSort
        switch (tam_vetor) {
            case 100:
                if (padrao_vetor == 1)
                    executar_ordenacao(shellsort_wrapper, vetor_100_ordenado, 100);
                else if (padrao_vetor == 2)
                    executar_ordenacao(shellsort_wrapper, vetor_100_inverso, 100);
                else
                    executar_ordenacao(shellsort_wrapper, vetor_100_aleatorio[id_vetor_aleatorio], 100);
                break;
            case 1000:
                if (padrao_vetor == 1)
                    executar_ordenacao(shellsort_wrapper, vetor_1000_ordenado, 1000);
                else if (padrao_vetor == 2)
                    executar_ordenacao(shellsort_wrapper, vetor_1000_inverso, 1000);
                else
                    executar_ordenacao(shellsort_wrapper, vetor_1000_aleatorio[id_vetor_aleatorio], 1000);
                break;
            case 10000:
                if (padrao_vetor == 1)
                    executar_ordenacao(shellsort_wrapper, vetor_10000_ordenado, 10000);
                else if (padrao_vetor == 2)
                    executar_ordenacao(shellsort_wrapper, vetor_10000_inverso, 10000);
                else
                    executar_ordenacao(shellsort_wrapper, vetor_10000_aleatorio[id_vetor_aleatorio], 10000);
                break;
            case 100000:
                if (padrao_vetor == 1)
                    executar_ordenacao(shellsort_wrapper, vetor_100000_ordenado, 100000);
                else if (padrao_vetor == 2)
                    executar_ordenacao(shellsort_wrapper, vetor_100000_inverso, 100000);
                else
                    executar_ordenacao(shellsort_wrapper, vetor_100000_aleatorio[id_vetor_aleatorio], 100000);
                break;
        }
        break;

    case 4: // QuickSort
        switch (tam_vetor) {
            case 100:
                if (padrao_vetor == 1)
                    executar_ordenacao(quicksort_wrapper, vetor_100_ordenado, 100);
                else if (padrao_vetor == 2)
                    executar_ordenacao(quicksort_wrapper, vetor_100_inverso, 100);
                else
                    executar_ordenacao(quicksort_wrapper, vetor_100_aleatorio[id_vetor_aleatorio], 100);
                break;
            case 1000:
                if (padrao_vetor == 1)
                    executar_ordenacao(quicksort_wrapper, vetor_1000_ordenado, 1000);
                else if (padrao_vetor == 2)
                    executar_ordenacao(quicksort_wrapper, vetor_1000_inverso, 1000);
                else
                    executar_ordenacao(quicksort_wrapper, vetor_1000_aleatorio[id_vetor_aleatorio], 1000);
                break;
            case 10000:
                if (padrao_vetor == 1)
                    executar_ordenacao(quicksort_wrapper, vetor_10000_ordenado, 10000);
                else if (padrao_vetor == 2)
                    executar_ordenacao(quicksort_wrapper, vetor_10000_inverso, 10000);
                else
                    executar_ordenacao(quicksort_wrapper, vetor_10000_aleatorio[id_vetor_aleatorio], 10000);
                break;
            case 100000:
                if (padrao_vetor == 1)
                    executar_ordenacao(quicksort_wrapper, vetor_100000_ordenado, 100000);
                else if (padrao_vetor == 2)
                    executar_ordenacao(quicksort_wrapper, vetor_100000_inverso, 100000);
                else
                    executar_ordenacao(quicksort_wrapper, vetor_100000_aleatorio[id_vetor_aleatorio], 100000);
                break;
        }
        break;

    case 5: // HeapSort
        switch (tam_vetor) {
            case 100:
                if (padrao_vetor == 1)
                    executar_ordenacao(heapsort, vetor_100_ordenado, 100);
                else if (padrao_vetor == 2)
                    executar_ordenacao(heapsort, vetor_100_inverso, 100);
                else
                    executar_ordenacao(heapsort, vetor_100_aleatorio[id_vetor_aleatorio], 100);
                break;
            case 1000:
                if (padrao_vetor == 1)
                    executar_ordenacao(heapsort, vetor_1000_ordenado, 1000);
                else if (padrao_vetor == 2)
                    executar_ordenacao(heapsort, vetor_1000_inverso, 1000);
                else
                    executar_ordenacao(heapsort, vetor_1000_aleatorio[id_vetor_aleatorio], 1000);
                break;
            case 10000:
                if (padrao_vetor == 1)
                    executar_ordenacao(heapsort, vetor_10000_ordenado, 10000);
                else if (padrao_vetor == 2)
                    executar_ordenacao(heapsort, vetor_10000_inverso, 10000);
                else
                    executar_ordenacao(heapsort, vetor_10000_aleatorio[id_vetor_aleatorio], 10000);
                break;
            case 100000:
                if (padrao_vetor == 1)
                    executar_ordenacao(heapsort, vetor_100000_ordenado, 100000);
                else if (padrao_vetor == 2)
                    executar_ordenacao(heapsort, vetor_100000_inverso, 100000);
                else
                    executar_ordenacao(heapsort, vetor_100000_aleatorio[id_vetor_aleatorio], 100000);
                break;
        }
        break;

    case 6: // MergeSort
        switch (tam_vetor) {
            case 100:
                if (padrao_vetor == 1)
                    executar_ordenacao(mergesort_wrapper, vetor_100_ordenado, 100);
                else if (padrao_vetor == 2)
                    executar_ordenacao(mergesort_wrapper, vetor_100_inverso, 100);
                else
                    executar_ordenacao(mergesort_wrapper, vetor_100_aleatorio[id_vetor_aleatorio], 100);
                break;
            case 1000:
                if (padrao_vetor == 1)
                    executar_ordenacao(mergesort_wrapper, vetor_1000_ordenado, 1000);
                else if (padrao_vetor == 2)
                    executar_ordenacao(mergesort_wrapper, vetor_1000_inverso, 1000);
                else
                    executar_ordenacao(mergesort_wrapper, vetor_1000_aleatorio[id_vetor_aleatorio], 1000);
                break;
            case 10000:
                if (padrao_vetor == 1)
                    executar_ordenacao(mergesort_wrapper, vetor_10000_ordenado, 10000);
                else if (padrao_vetor == 2)
                    executar_ordenacao(mergesort_wrapper, vetor_10000_inverso, 10000);
                else
                    executar_ordenacao(mergesort_wrapper, vetor_10000_aleatorio[id_vetor_aleatorio], 10000);
                break;
            case 100000:
                if (padrao_vetor == 1)
                    executar_ordenacao(mergesort_wrapper, vetor_100000_ordenado, 100000);
                else if (padrao_vetor == 2)
                    executar_ordenacao(mergesort_wrapper, vetor_100000_inverso, 100000);
                else
                    executar_ordenacao(mergesort_wrapper, vetor_100000_aleatorio[id_vetor_aleatorio], 100000);
                break;
        }
        break;

    case 7: // Contagem de Menores
        switch (tam_vetor) {
            switch (tam_vetor) {
            case 100:
                if (padrao_vetor == 1)
                    executar_ordenacao(contagem_de_menores, vetor_100_ordenado, 100);
                else if (padrao_vetor == 2)
                    executar_ordenacao(contagem_de_menores, vetor_100_inverso, 100);
                else
                    executar_ordenacao(contagem_de_menores, vetor_100_aleatorio[id_vetor_aleatorio], 100);
                break;
            case 1000:
                if (padrao_vetor == 1)
                    executar_ordenacao(contagem_de_menores, vetor_1000_ordenado, 1000);
                else if (padrao_vetor == 2)
                    executar_ordenacao(contagem_de_menores, vetor_1000_inverso, 1000);
                else
                    executar_ordenacao(contagem_de_menores, vetor_1000_aleatorio[id_vetor_aleatorio], 1000);
                break;
            case 10000:
                if (padrao_vetor == 1)
                    executar_ordenacao(contagem_de_menores, vetor_10000_ordenado, 10000);
                else if (padrao_vetor == 2)
                    executar_ordenacao(contagem_de_menores, vetor_10000_inverso, 10000);
                else
                    executar_ordenacao(contagem_de_menores, vetor_10000_aleatorio[id_vetor_aleatorio], 10000);
                break;
            case 100000:
                if (padrao_vetor == 1)
                    executar_ordenacao(contagem_de_menores, vetor_100000_ordenado, 100000);
                else if (padrao_vetor == 2)
                    executar_ordenacao(contagem_de_menores, vetor_100000_inverso, 100000);
                else
                    executar_ordenacao(contagem_de_menores, vetor_100000_aleatorio[id_vetor_aleatorio], 100000);
                break;
            }
        }
        break;

    case 8: // RadixSort
        switch (tam_vetor) {
            case 100:
                if (padrao_vetor == 1)
                    executar_ordenacao(radixsort, vetor_100_ordenado, 100);
                else if (padrao_vetor == 2)
                    executar_ordenacao(radixsort, vetor_100_inverso, 100);
                else
                    executar_ordenacao(radixsort, vetor_100_aleatorio[id_vetor_aleatorio], 100);
                break;
            case 1000:
                if (padrao_vetor == 1)
                    executar_ordenacao(radixsort, vetor_1000_ordenado, 1000);
                else if (padrao_vetor == 2)
                    executar_ordenacao(radixsort, vetor_1000_inverso, 1000);
                else
                    executar_ordenacao(radixsort, vetor_1000_aleatorio[id_vetor_aleatorio], 1000);
                break;
            case 10000:
                if (padrao_vetor == 1)
                    executar_ordenacao(radixsort, vetor_10000_ordenado, 10000);
                else if (padrao_vetor == 2)
                    executar_ordenacao(radixsort, vetor_10000_inverso, 10000);
                else
                    executar_ordenacao(radixsort, vetor_10000_aleatorio[id_vetor_aleatorio], 10000);
                break;
            case 100000:
                if (padrao_vetor == 1)
                    executar_ordenacao(radixsort, vetor_100000_ordenado, 100000);
                else if (padrao_vetor == 2)
                    executar_ordenacao(radixsort, vetor_100000_inverso, 100000);
                else
                    executar_ordenacao(radixsort, vetor_100000_aleatorio[id_vetor_aleatorio], 100000);
                break;
        }
    break;

    default:
        printf("Algoritmo de ordenação não identificado.\n");
        break;
    }

    return 0;
}

void executar_ordenacao(AlgOrdenacao alg_ordenacao, int *vetor, int tamanho) {
    // Exibe o vetor original antes da ordenação
    printf("\n\nVetor original:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    
    // Declara variáveis para medir o tempo de execução
    clock_t inicio, fim;          // Variáveis para armazenar o tempo inicial e final
    double tempo_ordenacao;       // Variável para calcular o tempo em segundos

    // Inicia a contagem de tempo
    inicio = clock();
    
    // Chama o algoritmo de ordenação fornecido como argumento
    alg_ordenacao(vetor, tamanho);
    
    // Finaliza a contagem de tempo
    fim = clock();

    // Exibe o vetor após a ordenação
    printf("\nVetor ordenado:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }

    // Calcula o tempo total de execução em segundos
    tempo_ordenacao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    // Exibe o tempo de ordenação
    printf("\n\nTempo de ordenacao: %.6f segundos\n", tempo_ordenacao);
}

// Função de encapsulamento para o QuickSort
void quicksort_wrapper(int *vetor, int tamanho) {
    // Chama o QuickSort, passando o vetor e os índices inicial e final
    quicksort(vetor, 0, tamanho - 1);
}

// Função de encapsulamento para o ShellSort
void shellsort_wrapper(int *vetor, int tamanho) {
    // Define a sequência de incrementos (sequência de Knuth) para o ShellSort
    int incrementos[] = {121, 40, 13, 4, 1};
    int num_incrementos = sizeof(incrementos) / sizeof(incrementos[0]);
    
    // Chama o ShellSort com os incrementos definidos
    shellsort(vetor, tamanho, incrementos, num_incrementos);
}

// Função de encapsulamento para o MergeSort
void mergesort_wrapper(int *vetor, int tamanho) {
    // Chama o MergeSort, passando o vetor e os índices inicial e final
    mergesort(vetor, 0, tamanho - 1);
}

/*
 * Algoritmo de ordenação baseado no Bubble Sort.
 * Compara e troca elementos adjacentes até que o array esteja ordenado.
 * Complexidade: O(n^2). Simples e intuitivo, mas ineficiente para grandes conjuntos.
 */
void bubblesort(int v[], int n) {
    // Declaração de variáveis
    int i, j, aux;

    // Laço externo que controla as iterações do algoritmo
    // Representa a quantidade de passagens pelo vetor
    for (i = 0; i < n; i++) {
        // Laço interno que compara pares adjacentes
        // A cada iteração, "empurra" o maior elemento restante para o final
        for (j = 0; j < n - 1; j++) {
            // Verifica se os elementos adjacentes estão fora de ordem
            if (v[j] > v[j + 1]) {
                // Realiza a troca dos elementos
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
}

/*
 * Algoritmo de ordenação baseado no Selection Sort.
 * Seleciona o menor elemento a cada iteração e o coloca na posição correta.
 * Complexidade: O(n^2). Ideal para aprendizado, mas ineficiente para grandes conjuntos.
 */
void selection_sort(int num[], int tam) {
    // Declaração de variáveis
    int i, j, min;

    // Laço externo que percorre o vetor até o penúltimo elemento
    for (i = 0; i < (tam - 1); i++) {
        // Assume que o menor elemento está na posição atual (i)
        min = i;

        // Laço interno para encontrar o menor elemento no subvetor restante
        for (j = (i + 1); j < tam; j++) {
            // Verifica se o elemento atual (num[j]) é menor que o mínimo encontrado
            if (num[j] < num[min]) {
                min = j; // Atualiza o índice do menor elemento
            }
        }

        // Troca os elementos apenas se o menor encontrado não for o próprio elemento atual
        if (i != min) {
            int swap = num[i];    // Salva o valor atual em uma variável auxiliar
            num[i] = num[min];    // Coloca o menor valor na posição atual
            num[min] = swap;      // Coloca o valor original da posição atual na posição do menor
        }
    }
}

/*
 * Algoritmo de ordenação baseado no Insertion Sort.
 * Insere elementos em suas posições corretas à medida que o array é percorrido.
 * Complexidade: O(n^2), mas eficiente para listas pequenas ou quase ordenadas.
 */
void insertion_sort(int v[], int n) {
    // Declaração de variáveis
    int i, j, elem;

    // Laço externo: percorre os elementos do vetor a partir do segundo elemento (índice 1)
    for (i = 1; i < n; i++) {
        // Armazena o elemento atual que será inserido na posição correta
        elem = v[i];

        // Laço interno: desloca os elementos maiores que "elem" para frente
        for (j = i - 1; j >= 0 && elem < v[j]; j--) {
            v[j + 1] = v[j]; // Move o elemento maior uma posição à frente
        }

        // Insere o elemento armazenado na posição correta
        v[j + 1] = elem;
    }
}

/*
 * Algoritmo de ordenação baseado no Shell Sort.
 * Utiliza incrementos (gaps) para melhorar a eficiência do Insertion Sort.
 * Complexidade: Depende dos gaps utilizados, mas geralmente O(n^1.5) em média.
 */
void shellsort(int v[], int n, int incrementos[], int numinc) {
    // Declaração de variáveis
    int incr, i, j, h, aux;

    // Laço para iterar sobre os diferentes valores de "gap" (incremento) fornecidos
    for (incr = 0; incr < numinc; incr++) {
        h = incrementos[incr];  // Atualiza o valor do "gap" (distância de comparação entre elementos)

        // Laço principal para percorrer os elementos do vetor, começando pelo índice 'h'
        for (i = h; i < n; i++) {
            aux = v[i];  // Armazena o valor atual que será inserido na posição correta

            // Laço interno: compara o elemento atual com o anterior dentro do gap
            // Desloca os elementos maiores que "aux" para abrir espaço
            for (j = i - h; j >= 0 && v[j] > aux; j -= h) {
                v[j + h] = v[j];  // Move o elemento para frente dentro do gap
            }

            // Insere o elemento armazenado no lugar correto
            v[j + h] = aux;
        }
    }
}

/*
 * Algoritmo de ordenação baseado no Quick Sort.
 * Divide o array em dois subarrays e os ordena recursivamente.
 * Complexidade: O(n log n) em média, mas O(n^2) no pior caso.
 */
void quicksort(int v[], int inf, int sup) {
    // Declaração de variável auxiliar para troca de elementos
    int aux;

    // Verifica se o vetor tem mais de um elemento para ordenar
    if (inf < sup) {
        // Calcula o índice do meio do vetor
        int meio = (inf + sup) / 2;

        // Seleciona três elementos: o primeiro (inf), o do meio e o último (sup)
        int a = v[inf], b = v[meio], c = v[sup];
        int pivoIndex;

        // Determina o pivô utilizando a mediana dos três elementos
        // O pivô será o valor que está entre os outros dois
        if ((a > b) ^ (a > c)) 
            pivoIndex = inf;  // Se 'a' é maior que 'b' ou 'c', 'a' é o pivô
        else if ((b > a) ^ (b > c)) 
            pivoIndex = meio; // Se 'b' é maior que 'a' ou 'c', 'b' é o pivô
        else
            pivoIndex = sup;  // Se 'c' é o pivô

        // Coloca o pivô na posição do meio (para facilitar a partição)
        int pivo = v[pivoIndex];
        v[pivoIndex] = v[meio];
        v[meio] = pivo;

        // Inicializa os índices para percorrer o vetor
        int i = inf;
        int j = sup;

        // Loop de partição: organiza os elementos ao redor do pivô
        do {
            // Encontra o primeiro elemento maior ou igual ao pivô à esquerda
            while (v[i] < pivo) i++;
            // Encontra o primeiro elemento menor ou igual ao pivô à direita
            while (v[j] > pivo) j--;
            // Se os índices ainda estão na ordem correta (i <= j), troca os elementos
            if (i <= j) {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
                i++;  // Avança o índice da esquerda
                j--;  // Retrocede o índice da direita
            }
        } while (i <= j);  // Repete enquanto i e j não se cruzarem

        // Recursão: ordena as duas sublistas geradas pela partição
        if (inf < j) quicksort(v, inf, j);  // Ordena a parte à esquerda do pivô
        if (i < sup) quicksort(v, i, sup);  // Ordena a parte à direita do pivô
    }
}

/*
 * Rearranja um heap para manter a propriedade de heap (pai maior que os filhos).
 */
void rearranjar_heap(int v[], int i, int tamanho_do_heap) {
    // Declaração de variáveis
    int esq, dir, maior, aux;

    // Calcula os índices dos filhos esquerdo e direito do nó i
    esq = 2 * i + 1;  // Índice do filho esquerdo
    dir = 2 * i + 2;  // Índice do filho direito

    // Verifica se o filho esquerdo é maior que o nó atual
    if ((esq < tamanho_do_heap) && (v[esq] > v[i]))
        maior = esq;  // Se o filho esquerdo é maior, define 'maior' como esq
    else
        maior = i;  // Caso contrário, o maior é o nó atual

    // Verifica se o filho direito é maior que o maior valor encontrado até agora
    if ((dir < tamanho_do_heap) && (v[dir] > v[maior]))
        maior = dir;  // Se o filho direito é maior, atualiza 'maior'

    // Se o maior não for o nó atual, realiza a troca
    if (maior != i) {
        aux = v[i];  // Armazena o valor atual em 'aux'
        v[i] = v[maior];  // Coloca o maior valor no nó atual
        v[maior] = aux;  // Coloca o valor do nó atual no lugar do maior

        // Chama recursivamente para ajustar a subárvore alterada
        rearranjar_heap(v, maior, tamanho_do_heap);
    }
}

/*
 * Constrói um heap máximo a partir do array fornecido.
 */
void construir_heap(int v[], int n) {
    // Laço para percorrer os nós internos da árvore (começa do último nó pai)
    for (int i = n / 2 - 1; i >= 0; i--) {
        // Chama a função de rearranjo para construir o heap a partir do índice i
        rearranjar_heap(v, i, n);
    }
}

/*
 * Algoritmo de ordenação baseado no Heap Sort.
 * Utiliza a estrutura de heap para ordenar os elementos, extrair o maior e reconstruir o heap.
 * Complexidade: O(n log n).
 */
void heapsort(int v[], int n) {
    // Constrói o heap máximo a partir do vetor
    construir_heap(v, n);

    // Laço para remover o maior elemento (raiz) do heap e colocá-lo no final do vetor
    for (int i = n - 1; i > 0; i--) {
        // Troca o maior elemento (na posição 0) com o último elemento não ordenado
        int aux = v[0];
        v[0] = v[i];
        v[i] = aux;  // Coloca o maior elemento no final do vetor

        // Ajusta o heap após a remoção do maior elemento
        rearranjar_heap(v, 0, i);  // Ajusta o heap para manter a propriedade do heap máximo
    }
}


/*
 * Merge Sort: divide o array em duas partes, ordena-as e as combina.
 */
void merge(int v[], int inf, int meio, int sup) {
    // Inicializa os índices para percorrer os dois subarrays
    int i = inf, j = meio + 1, k = 0;
    int aux[sup - inf + 1];  // Array auxiliar para armazenar a combinação dos subarrays

    // Combina os dois subarrays em ordem crescente
    while (i <= meio && j <= sup) {
        if (v[i] <= v[j]) {
            aux[k++] = v[i++];  // Adiciona o menor elemento ao array auxiliar
        } else {
            aux[k++] = v[j++];  // Adiciona o menor elemento do segundo subarray
        }
    }

    // Copia os elementos restantes do primeiro subarray (se houver)
    while (i <= meio) aux[k++] = v[i++];

    // Copia os elementos restantes do segundo subarray (se houver)
    while (j <= sup) aux[k++] = v[j++];

    // Copia o array auxiliar de volta para o vetor original
    for (i = inf, k = 0; i <= sup; i++, k++) {
        v[i] = aux[k];  // Substitui os elementos do vetor original pelos ordenados
    }
}

/*
 * Algoritmo de ordenação baseado no Merge Sort.
 * Divide o array em subarrays, ordena cada subarray e os combina.
 * Complexidade: O(n log n), sempre.
 */
void mergesort(int v[], int inf, int sup) {
    // Verifica se o vetor contém mais de um elemento
    if (inf < sup) {
        // Calcula o índice do meio para dividir o vetor em duas metades
        int meio = (inf + sup) / 2;

        // Chama recursivamente a função para ordenar a primeira metade do vetor
        mergesort(v, inf, meio);

        // Chama recursivamente a função para ordenar a segunda metade do vetor
        mergesort(v, meio + 1, sup);

        // Combina as duas metades ordenadas em um único vetor ordenado
        merge(v, inf, meio, sup);
    }
}


/*
 * Algoritmo de ordenação baseado no Counting Sort.
 * Conta quantos elementos são menores que cada elemento e os reposiciona.
 * Complexidade: O(n^2), por causa dos dois loops aninhados.
 */
void contagem_de_menores(int v[], int n) {
    // Declaração dos vetores auxiliares X e B
    int X[n], B[n], i, j;

    // Inicializa o vetor de contagem (X) com zero
    for (i = 0; i < n; i++) {
        X[i] = 0;  // Inicializa a contagem de elementos menores com 0
    }

    // Conta quantos elementos são menores que cada elemento v[i]
    for (i = 1; i < n; i++) {
        for (j = i - 1; j >= 0; j--) {
            if (v[i] < v[j]) {
                X[j]++;  // Aumenta a contagem de elementos menores do que v[j]
            } else {
                X[i]++;  // Aumenta a contagem de elementos menores do que v[i]
            }
        }
    }

    // Reposiciona os elementos no vetor B com base na contagem em X
    for (i = 0; i < n; i++) {
        B[X[i]] = v[i];  // Coloca o valor de v[i] na posição de acordo com a contagem
    }

    // Copia os elementos ordenados de volta para o vetor original v
    for (i = 0; i < n; i++) {
        v[i] = B[i];  // Copia os elementos do vetor B para o vetor original v
    }
}

/*
 * Radix Sort: ordena inteiros usando dígitos individuais (base 10).
 */
int obter_maior(int v[], int n) {
    // Inicializa a variável 'maior' com o primeiro elemento do vetor
    int maior = v[0];

    // Laço para percorrer os elementos restantes do vetor
    for (int i = 1; i < n; i++) {
        // Se o elemento atual for maior que o maior valor encontrado até agora
        if (v[i] > maior) {
            maior = v[i];  // Atualiza o maior valor
        }
    }

    // Retorna o maior valor encontrado no vetor
    return maior;
}

/*
 * Realiza Counting Sort para um dígito específico.
 */
void contar_classificar(int v[], int n, int exp) {
    // Vetor auxiliar para armazenar os elementos classificados
    int aux[n];

    // Vetor de contagem para cada dígito (0 a 9)
    int contagem[10] = {0};

    // Conta a frequência de cada dígito no vetor
    for (int i = 0; i < n; i++) {
        int digito = (v[i] / exp) % 10;  // Extrai o dígito correspondente à posição exp
        contagem[digito]++;  // Aumenta a contagem do dígito
    }

    // Calcula as posições acumuladas para a classificação dos elementos
    for (int i = 1; i < 10; i++) {
        contagem[i] += contagem[i - 1];  // Ajusta a posição dos dígitos
    }

    // Reorganiza os elementos no vetor auxiliar com base na contagem
    for (int i = n - 1; i >= 0; i--) {
        int digito = (v[i] / exp) % 10;  // Extrai o dígito correspondente à posição exp
        aux[--contagem[digito]] = v[i];  // Coloca o elemento na posição correta
    }

    // Copia os elementos classificados de volta para o vetor original
    for (int i = 0; i < n; i++) {
        v[i] = aux[i];  // Substitui os elementos do vetor original pelos classificados
    }
}


/*
 * Algoritmo de ordenação baseado no Radix Sort.
 * Ordena números inteiros usando seus dígitos individuais, de menor para maior ordem.
 * Complexidade: O(nk), onde k é o número de dígitos do maior número.
 */
void radixsort(int v[], int n) {
    // Obtém o maior número do vetor para determinar o número de dígitos
    int maior = obter_maior(v, n);

    // Ordena o vetor considerando cada dígito, começando do menos significativo
    for (int exp = 1; maior / exp > 0; exp *= 10) {
        // Classifica os elementos com base no dígito atual (exp)
        contar_classificar(v, n, exp);
    }
}
