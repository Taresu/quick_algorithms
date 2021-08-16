#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Imprimir (int *vetor, int tamanho) {
  int i;
  for (i = 0; i < tamanho; i++) {
    printf("%d ", vetor[i]);
  } 
  printf ("\n");
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

int QuickFind (int *vetor, int esq, int dir, int k) {
  if (esq == dir) {return vetor[esq];}

  int pivot = particione(vetor, esq, dir);

  int i = pivot - esq + 1;

  if (i = k) //pivô é o i-ésimo menor!
    return vetor[pivot];
  else if (k < i) {return QuickFind(vetor, esq, pivot-1, k);}
    else {return QuickFind(vetor, pivot+1, dir, k-i);}
}

int particione(int *vetor, int esq, int dir) {

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

/*Função principal.*/
int main (int argc, char *argv[]) {
  clock_t start, end;
  double elapsed_time;
  srand(time(NULL));
  int i;
  
   //int tamanho = 10;
   //int *vetor = (int *)malloc(tamanho * sizeof(int));
   //for (i = 0; i < tamanho; i++) {
   //   vetor[i] = rand() % (tamanho+1);
   //}
  
  int tamanho = 8;
  int vetor[] = {7, 1, 3, 10, 17, 2, 21, 9};
  
  Imprimir (vetor, tamanho);
  start = clock();
  int pos = 4;
  printf("O elemento procurado na posicao %d e %d\n", pos, QuickFind(vetor, 0, tamanho-1, pos));
  
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
   //free (vetor);
  return 0;
}
