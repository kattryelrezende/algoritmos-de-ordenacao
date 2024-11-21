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
    printf("\n\nVetor original:\n");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }
    
    
    clock_t inicio, fim;
    double tempo_ordenacao;

    // Inicia a contagem de tempo
    inicio = clock();
    
    // Executa o algoritmo de ordenação
    alg_ordenacao(vetor, tamanho);
    
    // Finaliza a contagem de tempo
    fim = clock();

    printf("\nVetor ordenado:\n");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }

    // Calcula o tempo de execução em segundos
    tempo_ordenacao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    // Imprime o resultado
    printf("\n\nTempo de ordenacao: %.6f segundos\n", tempo_ordenacao);
}

void quicksort_wrapper(int *vetor, int tamanho) {
    quicksort(vetor, 0, tamanho - 1); // Chama o QuickSort com índices
}

void shellsort_wrapper(int *vetor, int tamanho) {
    int incrementos[] = {121, 40, 13, 4, 1}; // Sequência de Knuth
    int num_incrementos = sizeof(incrementos) / sizeof(incrementos[0]);
    shellsort(vetor, tamanho, incrementos, num_incrementos);
}

void mergesort_wrapper(int *vetor, int tamanho) {
    mergesort(vetor, 0, tamanho - 1); // Chama o MergeSort com índices
}



/*
 * Algoritmo de ordenação baseado no Bubble Sort.
 * Compara e troca elementos adjacentes até que o array esteja ordenado.
 * Complexidade: O(n^2). Simples e intuitivo, mas ineficiente para grandes conjuntos.
 */
void bubblesort(int v[], int n) {
    int i, j, aux;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - 1; j++) {
            // Troca pares adjacentes fora de ordem
            if (v[j] > v[j + 1]) {
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
    int i, j, min;
    for (i = 0; i < (tam - 1); i++) {
        min = i;
        for (j = (i + 1); j < tam; j++) {
            if (num[j] < num[min]) {
                min = j;
            }
        }
        // Troca apenas se o índice atual não for o do menor
        if (i != min) {
            int swap = num[i];
            num[i] = num[min];
            num[min] = swap;
        }
    }
}

/*
 * Algoritmo de ordenação baseado no Insertion Sort.
 * Insere elementos em suas posições corretas à medida que o array é percorrido.
 * Complexidade: O(n^2), mas eficiente para listas pequenas ou quase ordenadas.
 */
void insertion_sort(int v[], int n) {
    int i, j, elem;
    for (i = 1; i < n; i++) {
        elem = v[i];
        // Move os elementos maiores para abrir espaço
        for (j = i - 1; j >= 0 && elem < v[j]; j--) {
            v[j + 1] = v[j];
        }
        v[j + 1] = elem; // Insere o elemento na posição correta
    }
}

/*
 * Algoritmo de ordenação baseado no Shell Sort.
 * Utiliza incrementos (gaps) para melhorar a eficiência do Insertion Sort.
 * Complexidade: Depende dos gaps utilizados, mas geralmente O(n^1.5) em média.
 */
void shellsort(int v[], int n, int incrementos[], int numinc) {
    int incr, i, j, h, aux;
    for (incr = 0; incr < numinc; incr++) {
        h = incrementos[incr]; // Gap atual
        for (i = h; i < n; i++) {
            aux = v[i];
            for (j = i - h; j >= 0 && v[j] > aux; j -= h) {
                v[j + h] = v[j]; // Move elementos dentro do gap
            }
            v[j + h] = aux; // Insere o elemento
        }
    }
}

/*
 * Algoritmo de ordenação baseado no Quick Sort.
 * Divide o array em dois subarrays e os ordena recursivamente.
 * Complexidade: O(n log n) em média, mas O(n^2) no pior caso.
 */
void quicksort(int v[], int inf, int sup) {
    int aux;
    if (inf < sup) {
        int meio = (inf + sup) / 2;
        int a = v[inf], b = v[meio], c = v[sup];
        int pivoIndex;

        // Determina a mediana como pivô
        if ((a > b) ^ (a > c))
            pivoIndex = inf;
        else if ((b > a) ^ (b > c))
            pivoIndex = meio;
        else
            pivoIndex = sup;

        int pivo = v[pivoIndex];
        v[pivoIndex] = v[meio];
        v[meio] = pivo;

        int i = inf;
        int j = sup;

        do {
            while (v[i] < pivo) i++;
            while (v[j] > pivo) j--;
            if (i <= j) {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
                i++;
                j--;
            }
        } while (i <= j);

        if (inf < j) quicksort(v, inf, j);
        if (i < sup) quicksort(v, i, sup);
    }
}

/*
 * Rearranja um heap para manter a propriedade de heap (pai maior que os filhos).
 */
void rearranjar_heap(int v[], int i, int tamanho_do_heap) {
    int esq, dir, maior, aux;
    esq = 2 * i + 1;
    dir = 2 * i + 2;

    // Verifica se o filho esquerdo ou direito é maior que o pai
    if ((esq < tamanho_do_heap) && (v[esq] > v[i]))
        maior = esq;
    else
        maior = i;
    if ((dir < tamanho_do_heap) && (v[dir] > v[maior]))
        maior = dir;

    if (maior != i) {
        aux = v[i];
        v[i] = v[maior];
        v[maior] = aux;
        rearranjar_heap(v, maior, tamanho_do_heap);
    }
}

/*
 * Constrói um heap máximo a partir do array fornecido.
 */
void construir_heap(int v[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        rearranjar_heap(v, i, n);
    }
}

/*
 * Algoritmo de ordenação baseado no Heap Sort.
 * Utiliza a estrutura de heap para ordenar os elementos, extrair o maior e reconstruir o heap.
 * Complexidade: O(n log n).
 */
void heapsort(int v[], int n) {
    construir_heap(v, n); // Constrói o heap máximo
    for (int i = n - 1; i > 0; i--) {
        int aux = v[0];
        v[0] = v[i];
        v[i] = aux; // Coloca o maior elemento no final
        rearranjar_heap(v, 0, i); // Ajusta o heap
    }
}

/*
 * Merge Sort: divide o array em duas partes, ordena-as e as combina.
 */
void merge(int v[], int inf, int meio, int sup) {
    int i = inf, j = meio + 1, k = 0;
    int aux[sup - inf + 1];

    // Combina os dois subarrays em ordem
    while (i <= meio && j <= sup) {
        if (v[i] <= v[j]) {
            aux[k++] = v[i++];
        } else {
            aux[k++] = v[j++];
        }
    }

    // Copia elementos restantes
    while (i <= meio) aux[k++] = v[i++];
    while (j <= sup) aux[k++] = v[j++];

    // Copia o array auxiliar de volta
    for (i = inf, k = 0; i <= sup; i++, k++) {
        v[i] = aux[k];
    }
}

/*
 * Algoritmo de ordenação baseado no Merge Sort.
 * Divide o array em subarrays, ordena cada subarray e os combina.
 * Complexidade: O(n log n), sempre.
 */
void mergesort(int v[], int inf, int sup) {
    if (inf < sup) {
        int meio = (inf + sup) / 2;
        mergesort(v, inf, meio);
        mergesort(v, meio + 1, sup);
        merge(v, inf, meio, sup);
    }
}

/*
 * Algoritmo de ordenação baseado no Counting Sort.
 * Conta quantos elementos são menores que cada elemento e os reposiciona.
 * Complexidade: O(n^2), por causa dos dois loops aninhados.
 */
void contagem_de_menores(int v[], int n) {
    int X[n], B[n], i, j;

    // Inicializa o vetor de contagem com zero
    for (i = 0; i < n; i++) {
        X[i] = 0;
    }

    // Conta quantos elementos são menores que cada elemento v[i]
    for (i = 1; i < n; i++) {
        for (j = i - 1; j >= 0; j--) {
            if (v[i] < v[j]) {
                X[j]++;
            } else {
                X[i]++;
            }
        }
    }

    // Reposiciona os elementos no vetor B com base na contagem
    for (i = 0; i < n; i++) {
        B[X[i]] = v[i];
    }

    // Copia os elementos ordenados de volta para o vetor original
    for (i = 0; i < n; i++) {
        v[i] = B[i];
    }
}

/*
 * Radix Sort: ordena inteiros usando dígitos individuais (base 10).
 */
int obter_maior(int v[], int n) {
    int maior = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] > maior) {
            maior = v[i];
        }
    }
    return maior;
}

/*
 * Realiza Counting Sort para um dígito específico.
 */
void contar_classificar(int v[], int n, int exp) {
    int aux[n];
    int contagem[10] = {0};

    for (int i = 0; i < n; i++) {
        int digito = (v[i] / exp) % 10;
        contagem[digito]++;
    }

    for (int i = 1; i < 10; i++) {
        contagem[i] += contagem[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int digito = (v[i] / exp) % 10;
        aux[--contagem[digito]] = v[i];
    }

    for (int i = 0; i < n; i++) {
        v[i] = aux[i];
    }
}

/*
 * Algoritmo de ordenação baseado no Radix Sort.
 * Ordena números inteiros usando seus dígitos individuais, de menor para maior ordem.
 * Complexidade: O(nk), onde k é o número de dígitos do maior número.
 */
void radixsort(int v[], int n) {
    int maior = obter_maior(v, n);
    for (int exp = 1; maior / exp > 0; exp *= 10) {
        contar_classificar(v, n, exp);
    }
}
