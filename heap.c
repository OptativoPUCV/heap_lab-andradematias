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
  (pq->size)++;
  if (pq->size == pq->capac) {
    pq->capac = pq->capac*2+1;
    pq->heapArray = realloc (pq->heapArray, pq->capac*2+1);
  }
  int i = pq->size-1;  
  pq->heapArray[i].data = data;
  pq->heapArray[i].priority = priority;
  
  while (i != 0) {
      if (pq->heapArray[(i-1)/2].priority < priority) {      
        void *aux_data = pq->heapArray[(i-1)/2].data;
        int aux_priority = pq->heapArray[(i-1)/2].priority;
        pq->heapArray[(i-1)/2].data = data;
        pq->heapArray[(i-1)/2].priority = priority;
        pq->heapArray[i].data = aux_data;
        pq->heapArray[i].priority = aux_priority;
      }        
    i = (i-1)/2;
  }
}


void heap_pop(Heap* pq) {
  pq->heapArray[0].data = pq->heapArray[pq->size-1].data;
  pq->heapArray[0].priority = pq->heapArray[pq->size-1].priority;
  (pq->size)--;
  int i = 0 ;

  while (i != pq->size-1) {
    if (i > pq->size-1) break;
    if (pq->heapArray[i].priority < pq->heapArray[(2*i)+1].priority) {
      void *aux_data = pq->heapArray[i].data;
      int aux_priority = pq->heapArray[i].priority;
      pq->heapArray[i].data = pq->heapArray[(2*i)+1].data;
      pq->heapArray[i].priority = pq->heapArray[(2*i)+1].priority;
      pq->heapArray[(2*i)+1].data = aux_data;
      pq->heapArray[(2*i)+1].priority = aux_priority;
    } else if (pq->heapArray[i].priority < pq->heapArray[(2*i)+2].priority) {
      void *aux_data = pq->heapArray[i].data;
      int aux_priority = pq->heapArray[i].priority;
      pq->heapArray[i].data = pq->heapArray[(2*i)+2].data;
      pq->heapArray[i].priority = pq->heapArray[(2*i)+2].priority;
      pq->heapArray[(2*i)+2].data = aux_data;
      pq->heapArray[(2*i)+2].priority = aux_priority;
    }
    i = 2*i+2;
  }
}

Heap* createHeap(){
  Heap *h = (Heap*) malloc (sizeof(Heap));
  h->heapArray = (heapElem*) calloc (3, sizeof(heapElem));
  h->capac = 3;
  h->size = 0;
  return h;
}
