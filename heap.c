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
  if (pq->size == pq->capac) pq->heapArray = realloc (pq->heapArray, (pq->capac*2)+1); 
  (pq->size)++;
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
    printf("\n%i\n", i);
  }
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
