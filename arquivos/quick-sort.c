#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

int Verify_Sorting (int *vetor, int tamanho);
void PrintElements (int *vetor, int tamanho);
void PrintInverseElements (int *vetor, int tamanho);
void QuickSort (int *vetor, int esq, int dir);
void Decrescent_QuickSort(int *vetor, int dir);
void Crescent_QuickSort (int *vetor, int esq, int dir);
void Random_QuickSort (int *vetor, int esq, int dir);
int RandomElem (int *A, int array_size);
int Random_Particione (int A[], int l, int r);
int Particione(int *vetor, int esq, int dir);
void SwapElements (int *vetor, int i, int j);

/*Função que retorna 1 se a ordenação estiver correta e 0 caso contrário.*/
int Verify_Sorting (int *vetor, int tamanho) {
  int i;
  for (i = 0; i < tamanho-1; i++) {
    if (vetor[i] > vetor[i+1]) {
      return 0;
    }
  }
  return 1;
}

void PrintElements (int *vetor, int tamanho) {
  int i;
  for (i = 0; i < tamanho; i++) {
    printf("%d ", vetor[i]);
  } 
  printf ("\n");
}

void PrintInverseElements (int *vetor, int tamanho) {
  int i;
  for (i = tamanho-1; i >= 0; i--) {
    printf("%d ", vetor[i]);
  } 
  printf ("\n");
}

void QuickSort (int *vetor, int esq, int dir) {

  if (esq < dir) {
    int pivot = Particione(vetor, esq, dir);
    QuickSort(vetor, esq, pivot-1);
    QuickSort(vetor, pivot+1, dir);
  }
}

/*void CrescentQuickSort (int *vetor, int esq, int dir) {
  if (esq >= dir) return;
  if (vetor[esq] > vetor[dir]) {
      int t = vetor[esq]; 
      vetor[esq] = vetor[dir]; 
      vetor[dir] = t; }
  CrescentQuickSort  (vetor, esq, dir-1);
  CrescentQuickSort  (vetor, esq+1, dir); 
}
*/

void Crescent_QuickSort (int *vetor, int esq, int dir) {
  if (esq < dir) {;
    int i = esq, 
    j = dir, 
    c = vetor[(esq+dir)/2];
    while (vetor[i] < c) ++i;
    while (c < vetor[j]) --j;
    if (i <= j) {
      SwapElements(vetor, i, j);
      ++i, --j;
    }
  Crescent_QuickSort  (vetor, esq, j);
  Crescent_QuickSort  (vetor, i, dir); 
}
}

/* Retorna o valor booleano da proposição "x menor que y" */
static int cmpInt (int x, int y) {
  return x < y;
}

void Decrescent_QuickSort (int *vetor, int dir) {
  int x = vetor[0], temp, a = 1, b = dir;
  if (dir<=1) return;
  do {
    while (a < dir && !cmpInt(vetor[a],x)) {a++;}
    while (cmpInt(vetor[b],x)) {b--;}
    if (a < b) {
      temp = vetor[a];
      vetor[a] = vetor[b];
      vetor[b] = temp;
      a++;
      b--;
    }
  } while (a <= b);
  vetor[0] = vetor[b];
  vetor[b] = x;
  Decrescent_QuickSort (vetor, b);
  Decrescent_QuickSort (&vetor[a], dir-a);
}

int Particione(int *vetor, int esq, int dir) {

  int p = vetor[dir];
  int i = esq-1;
  for (int j = esq; j<=dir - 1; j++) {
    if(vetor[j]<p) {
      i++;
      SwapElements (vetor, i, j);
      //PrintElements(vetor, dir);
    }
  }
  SwapElements (vetor, i+1, dir);
  return i+1;
}

int RandomElement (int *A, int array_size){
  int random_pos = rand () % array_size+1;
  return A[random_pos];
}

/* Sorteio aleatório da posição do pivô */
int Random_Particione (int A[], int l, int r) {
//-> Sorteio da posição.
//-> Verifica se a posição do sorteio pertence ao intervalo correto.
//-> Faz swap do elemento sorteado com a posição do pivô.
int pivot = RandomElement(A, r);
SwapElements(A, pivot, r);
return Particione(A, l, r);
}

void Random_QuickSort (int *vetor, int esq, int dir) {

  if (esq < dir) {
    int pivot = Random_Particione(vetor, esq, dir);
    QuickSort(vetor, esq, pivot-1);
    QuickSort(vetor, pivot+1, dir);
  }
}

// Substituição trivial - "troca os elementos de posição"
/*
  (1): Copia o valor da pos mais à esquerda do vetor, p/ a var aux  
  (2): Altera o valor do vetor na pos desejada (mais à esquerda) p/ o do index min
  (3): Modifica o valor do index min, atribuindo o valor de aux
*/
void SwapElements (int *vetor, int i, int j) {
  int tmp = vetor[i]; // (1)
  vetor[i] = vetor[j]; // (2)
  vetor[j] = tmp; // (3)
}

/*Função principal.*/
//int main (int argc, char *argv[])
int main () {

  clock_t start, end;
  double elapsed_time;
  srand(time(NULL));
  int i;

  printf("Este programa possui como finalidade calcular o tempo de resposta da ordenacao do algoritmo Quick Sort de diferentes formas...\n");
  printf("O calculo sera feito com 10, 100, 1.000, 10.000, 100.000 e 1.000.000 elementos!\n\n");

  int tamanho = 10;
  int *vetor = (int *)malloc(tamanho * sizeof(int));

  for (i = 0; i < tamanho; i++) {
  vetor[i] = rand() % (tamanho+1);
  }

  printf("|[Exemplo com 10 elementos]|\n");
  printf("DESORDENADO: ");
  PrintElements (vetor, tamanho);

  QuickSort(vetor, 0, tamanho-1);
  if (!Verify_Sorting(vetor, tamanho)) {
    printf("Erro: a ordenacao nao esta correta!\n");
  }

  printf("CRESCENTE:   ");
  PrintElements (vetor, tamanho);
  printf("DECRESCENTE: ");
  PrintInverseElements (vetor, tamanho);

  free (vetor);

//////////////////////////////////////////////////////////////////////

  printf("\n|[Tempo de execucao (Quick-Sort)] ORDENACAO ALEATORIA]|\n");

  for (int k = 10; k<=MAX_SIZE; k *= 10){
    int tamanho = k;
    int *vetor = (int *)malloc(tamanho * sizeof(int));

    for (i = 0; i < tamanho; i++) {
    vetor[i] = rand() % (tamanho+1);
    }

    //PrintElements (vetor, tamanho);
    start = clock();
    QuickSort (vetor, 0, tamanho-1);
    end = clock();
    elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;

    if (k<1000) {printf("%d elementos: ", k);}
    else if (k<=100000) {printf("%d.000 elementos: ", k/1000);}
    else {printf("%d.000.000 elementos: ", k/1000000);}
    
    printf("%.2fs\n", elapsed_time);
    if (!Verify_Sorting(vetor, tamanho)) {
      printf("Erro: a ordenacao nao esta correta!\n");
    }
    //PrintElements (vetor, tamanho);
    free (vetor);
    }

//////////////////////////////////////////////////////////////////////

printf("\n|[Tempo de execucao (Quick-Sort)] ORDENACAO CRESCENTE, COM PIVOT NA ULTIMA POSICAO]|\n");

  for (int k = 10; k<=10000; k *= 10){
    int tamanho = k;
    int *vetor = (int *)malloc(tamanho * sizeof(int));

    for (i = 0; i < tamanho; i++) {
    vetor[i] = rand() % (tamanho+1);
    }

    //PrintElements (vetor, tamanho);
    start = clock();
    Crescent_QuickSort (vetor, 0, tamanho-1);
    end = clock();
    elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;

    if (k<1000) {printf("%d elementos: ", k);}
    else if (k<=100000) {printf("%d.000 elementos: ", k/1000);}
    else {printf("%d.000.000 elementos: ", k/1000000);}
    
    printf("%.2fs\n", elapsed_time);
    if (!Verify_Sorting(vetor, tamanho)) {
      printf("Erro: a ordenacao nao esta correta!\n");
    }
    //PrintElements (vetor, tamanho);
    free (vetor);
    }

//////////////////////////////////////////////////////////////////////

  printf("\n|[Tempo de execucao (Quick-Sort)] ORDENACAO CRESCENTE, COM PIVOT ALEATORIO]|\n");

  for (int k = 10; k<=MAX_SIZE; k *= 10){
    int tamanho = k;
    int *vetor = (int *)malloc(tamanho * sizeof(int));

    for (i = 0; i < tamanho; i++) {
    vetor[i] = rand() % (tamanho+1);
    }

    //PrintElements (vetor, tamanho);
    start = clock();
    Random_QuickSort (vetor, 0, tamanho-1);
    end = clock();
    elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;

    if (k<1000) {printf("%d elementos: ", k);}
    else if (k<=100000) {printf("%d.000 elementos: ", k/1000);}
    else {printf("%d.000.000 elementos: ", k/1000000);}
    
    printf("%.2fs\n", elapsed_time);
    if (!Verify_Sorting(vetor, tamanho)) {
      printf("Erro: a ordenacao nao esta correta!\n");
    }
    //PrintElements (vetor, tamanho);
    free (vetor);
  }

//////////////////////////////////////////////////////////////////////

printf("\n|[Tempo de execucao (Quick-Sort)] ORDENACAO DECRESCENTE / NAO FUNFA :/ ]|\n");

  for (int k = 10; k<=10; k *= 10){
    int tamanho = k;
    int *vetor = (int *)malloc(tamanho * sizeof(int));

    for (i = 0; i < tamanho; i++) {
    vetor[i] = rand() % (tamanho+1);
    }

    //PrintElements (vetor, tamanho);
    start = clock();
    Decrescent_QuickSort (vetor, tamanho-1);
    end = clock();
    elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;

    if (k<1000) {printf("%d elementos: ", k);}
    else if (k<=100000) {printf("%d.000 elementos: ", k/1000);}
    else {printf("%d.000.000 elementos: ", k/1000000);}
    
    printf("%.2fs\n", elapsed_time);
    //PrintElements (vetor, tamanho);
    free (vetor);
  }

  return 0;
}