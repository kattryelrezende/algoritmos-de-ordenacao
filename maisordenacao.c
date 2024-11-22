// Este programa implementa e avalia diferentes algoritmos de ordenação conforme as especificações do Projeto 2.
// Universidade de São Paulo - ICMC
// Disciplina: Introdução à Ciência de Computação II
// Tarefa: Comparar algoritmos de ordenação quanto ao número de comparações, movimentações e tempo de execução.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vetores.h"

// Protótipo da função de ordenação, permitindo passar diferentes algoritmos como parâmetro
typedef int *(*AlgOrdenacao)(int *, int);

// Funções auxiliares para execução de algoritmos específicos
void executar_ordenacao(AlgOrdenacao alg_ordenacao, int *vetor, int tamanho);
int *quicksort_wrapper(int *vetor, int tamanho);
int *shellsort_wrapper(int *vetor, int tamanho);
int *mergesort_wrapper(int *vetor, int tamanho);
int *rearranjar_heap(int v[], int i, int tamanho_do_heap);
void construir_heap(int v[], int n);
int *merge(int v[], int inf, int meio, int sup);
int obter_maior(int v[], int n, int *eficiencia);
int *contar_classificar(int v[], int n, int exp);

// Declaração dos algoritmos de ordenação implementados
int *bubblesort(int v[], int n);
int *selection_sort(int num[], int tam);
int *insertion_sort(int v[], int n);
int *shellsort(int v[], int n, int incrementos[], int numinc);
int *quicksort(int v[], int inf, int sup);
int *heapsort(int v[], int n);
int *mergesort(int v[], int inf, int sup);
int *contagem_de_menores(int v[], int n);
int *radixsort(int v[], int n);

int main(void)
{

    // Variáveis para configurar os testes
    int id_ordenacao;       // Identifica o algoritmo de ordenação
    int tam_vetor;          // Tamanho do vetor a ser ordenado
    int padrao_vetor;       // Tipo de vetor (ordenado, inverso ou aleatório)
    int id_vetor_aleatorio; // Identifica o vetor aleatório específico (1..5)

    clock_t inicio, fim;    // Para medir o tempo de execução
    double tempo_ordenacao; // Armazena o tempo gasto na ordenação

    // Menu interativo para o usuário escolher o algoritmo e as condições de teste
    printf("Digite o codigo do algoritmo de ordenacao:\n\n");
    printf("0: BubbleSort \n1: SelectionSort \n2: InsertionSort \n3: ShellSort \n4: QuickSort \n5: HeapSort \n6: MergeSort \n7: Contagem de Menores \n8: RadixSort\n\n");
    printf("Codigo: ");
    scanf("%d", &id_ordenacao);

    printf("\nIndique o numero de elementos no vetor:\n");
    printf("0: 100 elementos \n1: 1.000 elementos \n2: 10.000 elementos \n3: 100.000 elementos\n\n");
    printf("Tamanho: ");
    scanf("%d", &tam_vetor);

    switch (tam_vetor)
    {
        case 0:
            tam_vetor = 100;
            break;
        case 1:
            tam_vetor = 1000;
            break;
        case 2:
            tam_vetor = 10000;
            break;
        case 3:
            tam_vetor = 100000;
            break;
        
        default:
            break;
    }

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

    switch (id_ordenacao)
    {
    case 0: // BubbleSort
        switch (tam_vetor)
        {
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
        switch (tam_vetor)
        {
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
        switch (tam_vetor)
        {
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
        switch (tam_vetor)
        {
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
        switch (tam_vetor)
        {
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
        switch (tam_vetor)
        {
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
        switch (tam_vetor)
        {
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
        switch (tam_vetor)
        {
            switch (tam_vetor)
            {
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
        switch (tam_vetor)
        {
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

void executar_ordenacao(AlgOrdenacao alg_ordenacao, int *vetor, int tamanho)
{
    printf("\n\nVetor original:\n");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }

    clock_t inicio, fim;
    double tempo_ordenacao;

    // Inicia a contagem de tempo
    inicio = clock();

    // Executa o algoritmo de ordenação e captura os dados de eficiência
    int *eficiencia = alg_ordenacao(vetor, tamanho);

    // Finaliza a contagem de tempo
    fim = clock();

    printf("\nVetor ordenado:\n");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }

    // Calcula o tempo de execução em segundos
    tempo_ordenacao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    // Imprime os resultados
    printf("\n\nTempo de ordenacao: %.6f segundos\n", tempo_ordenacao);
    printf("Comparacoes realizadas: %d\n", eficiencia[0]);
    printf("Movimentacoes realizadas: %d\n", eficiencia[1]);

    // Libera a memória alocada para os dados de eficiência
    free(eficiencia);
}

int *quicksort_wrapper(int *vetor, int tamanho)
{
    int *eficiencia = quicksort(vetor, 0, tamanho - 1); // Chama o QuickSort com índices
    return eficiencia;
}

int *shellsort_wrapper(int *vetor, int tamanho)
{
    int incrementos[] = {121, 40, 13, 4, 1}; // Sequência de Knuth
    int num_incrementos = sizeof(incrementos) / sizeof(incrementos[0]);
    int *eficiencia = shellsort(vetor, tamanho, incrementos, num_incrementos);
    return eficiencia;
}

int *mergesort_wrapper(int *vetor, int tamanho)
{
    int *eficiencia = mergesort(vetor, 0, tamanho - 1); // Chama o MergeSort com índices
    return eficiencia;
}

/*
 * Algoritmo de ordenação baseado no Bubble Sort.
 * Compara e troca elementos adjacentes até que o array esteja ordenado.
 * Complexidade: O(n^2). Simples e intuitivo, mas ineficiente para grandes conjuntos.
 */
int *bubblesort(int v[], int n)
{
    // Declaração de variáveis
    int i, j, aux;
    int *eficiencia = (int *)calloc(2, sizeof(int)); // eficiencia[0] -> comparações; eficiencia[1] -> movimentações

    // Laço externo que controla as iterações do algoritmo
    // Representa a quantidade de passagens pelo vetor
    for (i = 0; i < n; i++)
    {
        // Laço interno que compara pares adjacentes
        // A cada iteração, "empurra" o maior elemento restante para o final
        for (j = 0; j < n - 1; j++)
        {
            // Verifica se os elementos adjacentes estão fora de ordem
            eficiencia[0]++;
            if (v[j] > v[j + 1])
            {
                // Realiza a troca dos elementos
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
                eficiencia[1]++;
            }
        }
    }

    return eficiencia;
}

/*
 * Algoritmo de ordenação baseado no Selection Sort.
 * Seleciona o menor elemento a cada iteração e o coloca na posição correta.
 * Complexidade: O(n^2). Ideal para aprendizado, mas ineficiente para grandes conjuntos.
 */
int *selection_sort(int num[], int tam)
{
    // Declaração de variáveis
    int i, j, min;

    int *eficiencia = (int *)calloc(2, sizeof(int)); // eficiencia[0] -> comparações; eficiencia[1] -> movimentações

    // Laço externo que percorre o vetor até o penúltimo elemento
    for (i = 0; i < (tam - 1); i++)
    {
        // Assume que o menor elemento está na posição atual (i)
        min = i;

        // Laço interno para encontrar o menor elemento no subvetor restante
        for (j = (i + 1); j < tam; j++)
        {
            // Verifica se o elemento atual (num[j]) é menor que o mínimo encontrado
            eficiencia[0]++;
            if (num[j] < num[min])
            {
                min = j; // Atualiza o índice do menor elemento
            }
        }

        // Troca os elementos apenas se o menor encontrado não for o próprio elemento atual
        eficiencia[0]++;
        if (i != min)
        {
            int swap = num[i]; // Salva o valor atual em uma variável auxiliar
            num[i] = num[min]; // Coloca o menor valor na posição atual
            num[min] = swap;   // Coloca o valor original da posição atual na posição do menor
            eficiencia[1]++;
        }
    }
}

/*
 * Algoritmo de ordenação baseado no Insertion Sort.
 * Insere elementos em suas posições corretas à medida que o array é percorrido.
 * Complexidade: O(n^2), mas eficiente para listas pequenas ou quase ordenadas.
 */
int *insertion_sort(int v[], int n)
{
    // Declaração de variáveis
    int i, j, elem;
    int *eficiencia = (int *)calloc(2, sizeof(int)); // eficiencia[0] -> comparações; eficiencia[1] -> movimentações

    // Laço externo: percorre os elementos do vetor a partir do segundo elemento (índice 1)
    for (i = 1; i < n; i++)
    {
        // Armazena o elemento atual que será inserido na posição correta
        elem = v[i];

        // Laço interno: desloca os elementos maiores que "elem" para frente
        for (j = i - 1; j >= 0 && elem < v[j]; j--)
        {
            eficiencia[0]++;
            v[j + 1] = v[j]; // Move o elemento maior uma posição à frente
            eficiencia[1]++;
        }

        // Insere o elemento armazenado na posição correta
        v[j + 1] = elem;
        eficiencia[1]++;
    }
}

/*
 * Algoritmo de ordenação baseado no Shell Sort.
 * Utiliza incrementos (gaps) para melhorar a eficiência do Insertion Sort.
 * Complexidade: Depende dos gaps utilizados, mas geralmente O(n^1.5) em média.
 */
int *shellsort(int v[], int n, int incrementos[], int numinc)
{
    // Declaração de variáveis
    int incr, i, j, h, aux;
    int *eficiencia = (int *)calloc(2, sizeof(int)); // eficiencia[0] -> comparações; eficiencia[1] -> movimentações

    // Laço para iterar sobre os diferentes valores de "gap" (incremento) fornecidos
    for (incr = 0; incr < numinc; incr++)
    {
        h = incrementos[incr]; // Atualiza o valor do "gap" (distância de comparação entre elementos)

        // Laço principal para percorrer os elementos do vetor, começando pelo índice 'h'
        for (i = h; i < n; i++)
        {
            aux = v[i]; // Armazena o valor atual que será inserido na posição correta

            // Laço interno: compara o elemento atual com o anterior dentro do gap
            // Desloca os elementos maiores que "aux" para abrir espaço
            for (j = i - h; j >= 0 && v[j] > aux; j -= h)
            {
                eficiencia[0]++;
                v[j + h] = v[j]; // Move o elemento para frente dentro do gap
                eficiencia[1]++;
            }

            // Insere o elemento armazenado no lugar correto
            v[j + h] = aux;
            eficiencia[1]++;
        }
    }
}

/*
 * Algoritmo de ordenação baseado no Quick Sort.
 * Divide o array em dois subarrays e os ordena recursivamente.
 * Complexidade: O(n log n) em média, mas O(n^2) no pior caso.
 */
int *quicksort(int v[], int inf, int sup)
{
    // Aloca e inicializa o vetor de eficiência
    // eficiencia[0] -> número de comparações realizadas
    // eficiencia[1] -> número de movimentações realizadas
    int *eficiencia = (int *)calloc(2, sizeof(int));

    // Verifica se há mais de um elemento na partição atual
    if (inf < sup)
    {
        eficiencia[0]++; // Incrementa contagem de comparações para a condição do if

        // Determina o pivô como a mediana de três elementos: primeiro, central e último
        int meio = (inf + sup) / 2;              // Índice do elemento central
        int a = v[inf], b = v[meio], c = v[sup]; // Elementos para encontrar a mediana
        int pivoIndex;

        // Determina o índice do pivô com base na mediana
        if ((a > b) ^ (a > c))
        {
            eficiencia[0]++;
            pivoIndex = inf; // Primeiro elemento é o pivô
        }
        else if ((b > a) ^ (b > c))
        {
            eficiencia[0]++; 
            pivoIndex = meio; // Elemento central é o pivô
        }
        else
        {
            eficiencia[0]++;
            pivoIndex = sup; // Último elemento é o pivô
        }

        // Coloca o pivô na posição central para facilitar a partição
        int pivo = v[pivoIndex];
        v[pivoIndex] = v[meio];
        v[meio] = pivo;

        // Inicializa os índices para a partição
        int i = inf, j = sup;

        // Realiza a partição: separa os elementos menores e maiores que o pivô
        do
        {
            // Move o índice `i` até encontrar um elemento maior ou igual ao pivô
            while (v[i] < pivo)
            {
                eficiencia[0]++;
                i++;
            }
            eficiencia[0]++; // Comparação que interrompe o while

            // Move o índice `j` até encontrar um elemento menor ou igual ao pivô
            while (v[j] > pivo)
            {
                eficiencia[0]++;
                j--;
            }
            eficiencia[0]++; // Comparação que interrompe o while

            // Troca os elementos nas posições `i` e `j` se os índices ainda não se cruzaram
            if (i <= j)
            {
                eficiencia[1]++;
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
                i++;
                j--;
            }
        } while (i <= j); // Repete enquanto os índices não se cruzarem

        // Realiza chamadas recursivas para as partições esquerda e direita
        if (inf < j)
        {
            // Chama recursivamente para a partição esquerda
            int *eficiencia_esq = quicksort(v, inf, j);
            if (eficiencia_esq)
            {
                // Acumula os valores de eficiência da partição esquerda
                eficiencia[0] += eficiencia_esq[0];
                eficiencia[1] += eficiencia_esq[1];
                free(eficiencia_esq);
            }
        }

        if (i < sup)
        {
            // Chama recursivamente para a partição direita
            int *eficiencia_dir = quicksort(v, i, sup);
            if (eficiencia_dir)
            {
                // Acumula os valores de eficiência da partição direita
                eficiencia[0] += eficiencia_dir[0];
                eficiencia[1] += eficiencia_dir[1];
                free(eficiencia_dir);
            }
        }
    }

    // Retorna o vetor de eficiência contendo as contagens de comparações e movimentações
    return eficiencia;
}

/*
 * Rearranja um heap para manter a propriedade de heap (pai maior que os filhos).
 */
int *rearranjar_heap(int v[], int i, int tamanho_do_heap) {
    // Aloca e inicializa o vetor de eficiência
    // eficiencia[0] -> número de comparações realizadas
    // eficiencia[1] -> número de movimentações realizadas
    int *eficiencia = (int *)calloc(2, sizeof(int));
    if (!eficiencia)
        return NULL; // Retorna NULL em caso de falha na alocação

    // Calcula os índices dos filhos esquerdo e direito do nó atual
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;
    int maior = i; // Assume que o maior elemento está no índice atual
    int aux;

    // Verifica se o filho esquerdo existe e é maior que o pai
    if ((esq < tamanho_do_heap) && (v[esq] > v[i])) {
        eficiencia[0]++; // Incrementa a contagem de comparações
        maior = esq;     // Atualiza o índice do maior elemento
    } else {
        eficiencia[0]++; // Mesmo se a condição for falsa, a comparação foi feita
    }

    // Verifica se o filho direito existe e é maior que o maior encontrado até agora
    if ((dir < tamanho_do_heap) && (v[dir] > v[maior])) {
        eficiencia[0]++; // Incrementa a contagem de comparações
        maior = dir;     // Atualiza o índice do maior elemento
    }

    // Se o maior não for o nó atual, realiza a troca
    if (maior != i) {
        eficiencia[1]++; // Incrementa a contagem de movimentações

        // Troca os elementos entre o nó atual e o maior filho
        aux = v[i];
        v[i] = v[maior];
        v[maior] = aux;

        // Chamada recursiva para ajustar o sub-heap afetado
        int *eficiencia_recursiva = rearranjar_heap(v, maior, tamanho_do_heap);
        if (eficiencia_recursiva) {
            // Soma os valores de eficiência da recursão
            eficiencia[0] += eficiencia_recursiva[0]; // Comparações
            eficiencia[1] += eficiencia_recursiva[1]; // Movimentações
            free(eficiencia_recursiva);              // Libera memória da chamada recursiva
        }
    }

    // Retorna o vetor de eficiência contendo as contagens de comparações e movimentações
    return eficiencia;
}

/*
 * Constrói um heap máximo a partir do array fornecido.
 */
void construir_heap(int v[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        rearranjar_heap(v, i, n);
    }
}

/*
 * Algoritmo de ordenação baseado no Heap Sort.
 * Utiliza a estrutura de heap para ordenar os elementos, extrair o maior e reconstruir o heap.
 * Complexidade: O(n log n).
 */
int *heapsort(int v[], int n) {
    // Aloca e inicializa o vetor de eficiência
    // eficiencia[0] -> número de comparações realizadas
    // eficiencia[1] -> número de movimentações realizadas
    int *eficiencia = (int *)calloc(2, sizeof(int));
    if (!eficiencia)
        return NULL; // Retorna NULL em caso de falha na alocação

    // Etapa 1: Constrói o heap máximo a partir do vetor
    construir_heap(v, n); // O vetor é reorganizado para obedecer às propriedades de um heap

    // Etapa 2: Realiza o processo de ordenação extraindo os elementos do heap
    for (int i = n - 1; i > 0; i--) {
        // Troca o maior elemento (no topo do heap) com o último elemento
        int aux = v[0];
        v[0] = v[i];
        v[i] = aux; // O maior elemento é movido para a posição final do subarray ordenado
        eficiencia[1]++; // Incrementa a contagem de movimentações

        // Ajusta o heap para manter as propriedades do heap máximo
        int *auxiliar = rearranjar_heap(v, 0, i); // Reorganiza o heap excluindo o último elemento
        if (auxiliar) {
            // Soma as eficiências retornadas pela função `rearranjar_heap`
            eficiencia[0] += auxiliar[0]; // Comparações
            eficiencia[1] += auxiliar[1]; // Movimentações
            free(auxiliar);               // Libera a memória alocada para a eficiência da função chamada
        }
    }

    // Retorna o vetor de eficiência contendo as contagens de comparações e movimentações realizadas
    return eficiencia;
}

/*
 * Merge Sort: divide o array em duas partes, ordena-as e as combina.
 */
int *merge(int v[], int inf, int meio, int sup) {
    // Aloca e inicializa o vetor de eficiência
    // eficiencia[0] -> número de comparações realizadas
    // eficiencia[1] -> número de movimentações realizadas
    int *eficiencia = (int *)calloc(2, sizeof(int));
    if (!eficiencia)
        return NULL; // Retorna NULL em caso de falha na alocação

    // Calcula o tamanho necessário para o array auxiliar
    int tamanho = sup - inf + 1;

    // Aloca o array auxiliar para armazenar os elementos temporariamente
    int *aux = (int *)malloc(tamanho * sizeof(int));
    if (!aux) {
        free(eficiencia); // Libera a memória de eficiência em caso de falha
        return NULL;
    }

    // Inicializa índices para os dois subarrays e o array auxiliar
    int i = inf, j = meio + 1, k = 0;

    // Combina os dois subarrays ordenados no array auxiliar
    while (i <= meio && j <= sup) {
        eficiencia[0]++; // Incrementa a contagem de comparações

        // Verifica qual elemento é menor e insere no array auxiliar
        if (v[i] <= v[j]) {
            aux[k++] = v[i++]; // Elemento do primeiro subarray
            eficiencia[1]++;   // Incrementa a contagem de movimentações
        } else {
            aux[k++] = v[j++]; // Elemento do segundo subarray
            eficiencia[1]++;   // Incrementa a contagem de movimentações
        }
    }

    // Copia os elementos restantes do primeiro subarray (se houver)
    while (i <= meio) {
        aux[k++] = v[i++];
        eficiencia[1]++; // Incrementa a contagem de movimentações
    }

    // Copia os elementos restantes do segundo subarray (se houver)
    while (j <= sup) {
        aux[k++] = v[j++];
        eficiencia[1]++; // Incrementa a contagem de movimentações
    }

    // Copia os elementos do array auxiliar de volta para o array original
    for (i = inf, k = 0; i <= sup; i++, k++) {
        v[i] = aux[k];
        eficiencia[1]++; // Incrementa a contagem de movimentações
    }

    // Libera a memória alocada para o array auxiliar
    free(aux);

    // Retorna o vetor de eficiência contendo comparações e movimentações
    return eficiencia;
}

/*
 * Algoritmo de ordenação baseado no Merge Sort.
 * Divide o array em subarrays, ordena cada subarray e os combina.
 * Complexidade: O(n log n), sempre.
 */
int *mergesort(int v[], int inf, int sup)
{
    // Aloca e inicializa o vetor de eficiência
    // eficiencia[0] -> número de comparações realizadas
    // eficiencia[1] -> número de movimentações realizadas
    int *eficiencia = (int *)calloc(2, sizeof(int)); // Inicializa as contagens de comparações e movimentações
    if (!eficiencia)
        return NULL; // Retorna NULL caso a alocação falhe

    // Verifica se há mais de um elemento para ordenar
    if (inf < sup)
    {
        // Calcula o índice do meio para dividir o array em duas metades
        int meio = (inf + sup) / 2;

        // Chamada recursiva para ordenar a metade esquerda
        int *aux = mergesort(v, inf, meio);
        if (aux)
        {
            // Soma as comparações e movimentações das chamadas recursivas
            eficiencia[0] += aux[0];
            eficiencia[1] += aux[1];
            free(aux); // Libera a memória da chamada recursiva
        }

        // Chamada recursiva para ordenar a metade direita
        aux = mergesort(v, meio + 1, sup);
        if (aux)
        {
            // Soma as comparações e movimentações das chamadas recursivas
            eficiencia[0] += aux[0];
            eficiencia[1] += aux[1];
            free(aux); // Libera a memória da chamada recursiva
        }

        // Combina as duas metades ordenadas em um único array ordenado
        aux = merge(v, inf, meio, sup);
        if (aux)
        {
            // Soma as comparações e movimentações do processo de combinação
            eficiencia[0] += aux[0];
            eficiencia[1] += aux[1];
            free(aux); // Libera a memória da função merge
        }
    }

    // Retorna o vetor de eficiência com as comparações e movimentações acumuladas
    return eficiencia;
}

/*
 * Algoritmo de ordenação baseado no Counting Sort.
 * Conta quantos elementos são menores que cada elemento e os reposiciona.
 * Complexidade: O(n^2), por causa dos dois loops aninhados.
 */
int *contagem_de_menores(int v[], int n)
{
    // Aloca e inicializa o vetor de eficiência
    // eficiencia[0] -> número de comparações realizadas
    // eficiencia[1] -> número de movimentações realizadas
    int *eficiencia = (int *)calloc(2, sizeof(int)); // Inicializa as contagens de comparações e movimentações
    if (!eficiencia)
        return NULL; // Retorna NULL caso a alocação falhe

    // Aloca os vetores auxiliares X e B
    int *X = (int *)calloc(n, sizeof(int)); // Vetor X para contar quantos elementos são menores que cada elemento
    int *B = (int *)malloc(n * sizeof(int)); // Vetor B para armazenar o vetor ordenado
    if (!X || !B)
    {
        free(eficiencia);
        free(X);
        free(B);
        return NULL; // Retorna NULL se houver falha na alocação
    }

    // Conta quantos elementos são menores que cada elemento v[i]
    for (int i = 1; i < n; i++)
    {
        // Compara o elemento v[i] com os anteriores
        for (int j = i - 1; j >= 0; j--)
        {
            eficiencia[0]++; // Incrementa o contador de comparações

            // Se v[i] for menor que v[j], incrementa o contador de menores de v[i]
            if (v[i] < v[j])
            {
                X[j]++;
                eficiencia[1]++; // Incrementa o contador de movimentações
            }
            else
            {
                // Caso contrário, incrementa o contador de menores de v[i]
                X[i]++;
                eficiencia[1]++; // Incrementa o contador de movimentações
            }
        }
    }

    // Reposiciona os elementos no vetor B com base na contagem de menores
    for (int i = 0; i < n; i++)
    {
        B[X[i]] = v[i]; // Coloca v[i] na posição correta no vetor B
        eficiencia[1]++; // Incrementa o contador de movimentações
    }

    // Copia os elementos ordenados de volta para o vetor original
    for (int i = 0; i < n; i++)
    {
        v[i] = B[i]; // Copia de B para v
        eficiencia[1]++; // Incrementa o contador de movimentações
    }

    // Libera os vetores auxiliares X e B
    free(X);
    free(B);

    // Retorna o vetor de eficiência com as contagens de comparações e movimentações
    return eficiencia;
}

/*
 * Radix Sort: ordena inteiros usando dígitos individuais (base 10).
 */
int obter_maior(int v[], int n, int *eficiencia)
{
    int maior = v[0]; // Inicializa o maior valor com o primeiro elemento do vetor

    // Percorre o vetor para encontrar o maior valor
    for (int i = 1; i < n; i++)
    {
        eficiencia[0]++; // Incrementa o contador de comparações
        if (v[i] > maior) // Compara o elemento atual com o maior encontrado até o momento
        {
            maior = v[i]; // Atualiza o maior valor
        }
    }

    return maior; // Retorna o maior valor encontrado
}

/*
 * Realiza Counting Sort para um dígito específico.
 */
int *contar_classificar(int v[], int n, int exp)
{
    int *eficiencia = (int *)calloc(2, sizeof(int)); // eficiencia[0] -> comparações; eficiencia[1] -> movimentações
    int aux[n]; // Array auxiliar para armazenar a ordenação temporária
    int contagem[10] = {0}; // Array para contar a frequência de cada dígito (0 a 9)

    // Conta a frequência de cada dígito (unidade, dezena, etc.)
    for (int i = 0; i < n; i++)
    {
        int digito = (v[i] / exp) % 10; // Obtém o dígito correspondente à posição "exp"
        contagem[digito]++; // Incrementa o contador para o dígito encontrado
        eficiencia[1]++; // Incrementa o contador de movimentações
    }

    // Atualiza a contagem para determinar a posição dos elementos no vetor
    for (int i = 1; i < 10; i++)
    {
        contagem[i] += contagem[i - 1]; // Soma as frequências anteriores para determinar a posição acumulada
        eficiencia[1]++; // Incrementa o contador de movimentações
    }

    // Coloca os elementos ordenados no array auxiliar
    for (int i = n - 1; i >= 0; i--)
    {
        int digito = (v[i] / exp) % 10; // Obtém o dígito correspondente à posição "exp"
        aux[--contagem[digito]] = v[i]; // Coloca o elemento na posição correta do vetor auxiliar
        eficiencia[1]++; // Incrementa o contador de movimentações
    }

    // Copia os elementos do array auxiliar de volta para o array original
    for (int i = 0; i < n; i++)
    {
        v[i] = aux[i]; // Copia de volta os elementos ordenados
        eficiencia[1]++; // Incrementa o contador de movimentações
    }

    return eficiencia; // Retorna o vetor de eficiência com o número de comparações e movimentações
}

/*
 * Algoritmo de ordenação baseado no Radix Sort.
 * Ordena números inteiros usando seus dígitos individuais, de menor para maior ordem.
 * Complexidade: O(nk), onde k é o número de dígitos do maior número.
 */
int *radixsort(int v[], int n)
{
    int *eficiencia = (int *)calloc(2, sizeof(int)); // eficiencia[0] -> comparações; eficiencia[1] -> movimentações

    // Chama a função para obter o maior valor do vetor (para determinar o número de dígitos)
    int maior = obter_maior(v, n, eficiencia);

    // Para cada dígito do maior número (começando pela unidade, dezena, etc.), realiza o Counting Sort
    for (int exp = 1; maior / exp > 0; exp *= 10)
    {
        // Chama a função contar_classificar para ordenar com base no dígito "exp"
        int *aux_eficiencia = contar_classificar(v, n, exp);
        
        // Acumula as comparações e movimentações realizadas
        eficiencia[0] += aux_eficiencia[0]; // Soma as comparações
        eficiencia[1] += aux_eficiencia[1]; // Soma as movimentações
        
        // Libera a memória alocada para eficiência da função contar_classificar
        free(aux_eficiencia); 
    }

    return eficiencia; // Retorna o vetor de eficiência (comparações e movimentações)
}