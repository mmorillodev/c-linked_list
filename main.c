#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

int main() {
  struct LinkedList *linked_list = new_linked_list();

  int value = 0;

  do {
    printf("Type a value to push: \n");
    scanf("%i", &value);

    if(value > 0) {
      linked_list->push(linked_list, value);
    }

  } while(value > 0);

  printf("Removed last value: \n");
  printf("%i\n", linked_list->pop(linked_list));

  printf("Entire list:\n");
  linked_list->print(linked_list);
  printf("\n");
  
  system("PAUSE");

  return 0;
}