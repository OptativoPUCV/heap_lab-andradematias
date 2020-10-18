#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
  if (pq->size == 0) {
    return NULL;
  } else {
    return pq->heapArray[0].data;
  }
}


void heap_push(Heap* pq, void* data, int priority){
  int aux = 0;

  if (pq->size == pq->capac) pq->heapArray = realloc (pq->heapArray, (pq->capac*2)+1); 

  while (pq->heapArray[aux].data != NULL) {    
    aux++;
  }
  pq->heapArray[aux].data = data;
  pq->heapArray[aux].priority = priority;


}


void heap_pop(Heap* pq){  

}

Heap* createHeap(){
  Heap *h = (Heap*) malloc (sizeof(Heap));
  h->heapArray = (heapElem*) calloc (3, sizeof(heapElem));
  h->capac = 3;
  h->size = 0;
  return h;
}
