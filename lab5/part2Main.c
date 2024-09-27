#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern int pop();
extern void push(int);
extern void addHeap(int);
extern int heapSize();
extern int heapDelete();
extern int heap();
extern void printHeapXml();

int main(int argc, char * argv[])
{
  int value;
  int pushToStack;
  while (scanf("%d\n", &value) != EOF) {
    fprintf(stderr, "READING INPUT: %d\n", value);
    addHeap(value);
  }
  heap();
  printHeapXml(0);
  printf("\n\n Descending Order  \n");
  int size = heapSize();
  for(int i=0; i < size; i++){
     pushToStack = heapDelete();
     printf("%d\n", pushToStack);
     push(pushToStack);
  }

  printf("\n Ascending Order  \n");
  for(int i=0; i < size; i++){
     printf("%d\n", pop());
  }

  exit(0);
}
