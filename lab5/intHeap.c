#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern int pop();
extern void push(int);


/**
 *  The functions in this module implement a Heapdata structure
 *  of integers.
 */
static int heapCount;
int heapList[100];

void swap(int *first, int *second){
    int temp = *first;
    *first = *second;
    *second = temp;
}

void heapAlgorithm(int i){
    int largest = i;
    int left = (2 * i) + 1;//Heap as perceived through an array that starts from 0, not 1; thus the '+1' and '+2'
    int right = (2 * i) + 2;
    
    if((left < heapCount) && (heapList[left] > heapList[largest])){
       largest = left;
    }
 
    if((right < heapCount) && (heapList[right] > heapList[largest])){
       largest = right;
    }

    if(largest != i){
       swap(&heapList[largest], &heapList[i]);//largest value out of the three(Parents and two childs) takes the spot of the parent(i)
       heapAlgorithm(largest);
    }
}

void heap(){
    for(int i = (heapCount/2 - 1); i >= 0; i--){
       heapAlgorithm(i); //determines number of full sets(parent and two childs) to use the heapify method on
    } 
}


/**
 * heapDelete() removes the biggest integer in the heap and returns it.
 *
 */

int heapDelete()
{
  if(heapCount == 0){
     printf("Error: No data vlaues in the heap present -> Empty Heap");
     return -1;
  }
  int biggestInt = heapList[0];
  heapList[0] = heapList[heapCount-1];
  heapCount--;
  heapAlgorithm(0);
  return biggestInt;
}


/**
 *  addHeap(thing2add) adds the "thing2add" to the Heap.
 *
 */
void addHeap(int thing2add){
    heapList[heapCount] = thing2add;
    heapCount++;
}


/**
 * heapSize() returns the number of items in the Heap.
 *
 */
int heapSize()
{
  return heapCount;
}

void printHeapXml(int i){
    int left = (2*i) +1;
    int right = (2*i) + 2;

    if(i < heapCount){
       printf("<node id= '%d'>", heapList[i]);
       printHeapXml(left);
       printHeapXml(right);
       printf("</node>");
    }
}

