#include <stdlib.h>
#include <stdio.h>

struct Node {
  int data; 
  struct Node *next;
};

struct LinkedList {
  struct Node *first;
  struct Node *last;

  int size;

  void(*push)(struct LinkedList *self, int data);
  int(*pop)(struct LinkedList *self);
  void(*print)(struct LinkedList *self);
  void(*forEach)(struct LinkedList *self, void(*callback)(int data, int index));
};

void push(struct LinkedList *self, int value) {
  struct Node *node = 
    (struct Node*) malloc(sizeof(struct Node));

  node->data = value;
  node->next = NULL;

  if(self->first == NULL) {
    self->first = node;
    self->last = node;

    self->size++;

    return;
  }

  struct Node *last_node = self->last;
  last_node->next = node;

  self->last = node;
  self->size++;
}

int pop(struct LinkedList *self) {
  struct Node *last_element = self->last;
  struct Node *current_element = self->first;

  if(current_element == last_element) {
    int statement = last_element->data;
    free(last_element);

    self->size--;

    return statement;
  }

  while(current_element != NULL) {
    if(current_element->next == last_element) {
      current_element->next = NULL;
      break;
    }

    current_element = current_element->next;
  }

  int statement = last_element->data;
  free(last_element);

  self->size--;

  return statement;
}

void print(struct LinkedList *self) {
  printf("[");

  struct Node *curr_node = self->first;

  for(
    int i = 0;
    curr_node != NULL; 
    curr_node = curr_node->next, i++
  ) {
    printf("%i%s", curr_node->data, i != self->size - 1 ? ", " : "");
  }

  printf("]");
}

//Simple implementation of functional programming in C
void forEach(struct LinkedList* self, void(*callback)(int data, int index)) {
  struct Node *curr_node = self->first;

  for(int i = 0; curr_node != NULL; i++, curr_node = curr_node->next) {
    (*callback)(curr_node->data, i);
  }
}

struct LinkedList* new_linked_list() {
  struct LinkedList *self = 
    (struct LinkedList*) malloc(sizeof(struct LinkedList));
    
  self->first = NULL;
  self->last = NULL;
  self->size = 0;

  self->push = &push;
  self->pop = &pop;
  self->print = &print;
  self->forEach = &forEach;

  return self;
}