#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern char *  pop();
extern void push(char *);

int main(int argc, char * argv[])
{
  int ch;
  int idCounter;
  char tag_id[100]; 
  while ((ch = getchar()) != EOF) {
    if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/')){
      continue;
    }
    if(ch == '<'){
      ch = getchar();
      if(ch != '/'){
         idCounter = 0;
         while(isalpha(ch) && ch!='>'){
            tag_id[idCounter] = ch;
            idCounter++;
            ch = getchar();
         }
         tag_id[idCounter] = '\0'; 
         if(ch != '>'){
            fprintf(stderr, "Error: Tag does not have an end -> Invalid Tag");
            exit(1);
         }
         push(tag_id[0]);
      }
      if(ch == '/'){
         idCounter = 0;
         ch = getchar();
         while(isalpha(ch) && ch!='>'){
            tag_id[idCounter] = ch;
            idCounter++;
            ch = getchar();
         }
         tag_id[idCounter] = '\0'; 
         if(ch != '>'){
            fprintf(stderr, "Error: Tag does not have an end -> Invalid Tag");
            exit(1);
         }

         char start;
         start = pop();
         if(start == -1){
            fprintf(stderr, "Error: Stack is empty");
            exit(1);
         }
         if(start != tag_id[0]){
            //fprintf("%c, %c", &start, tag_id[0]);
            fprintf(stderr, "Error: Tag identities do not match -> XML expression invalid");
            exit(1);
         }
      }
    }
  }
  int ifEmpty = isEmpty();
  if(ifEmpty == 0){
     fprintf(stderr, "Error: Stack is not Empty -> XML expression not closed");
     exit(1);
  }
  printf("Valid: XML expression is valid");
  exit(0);
}
