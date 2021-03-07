#ifndef LINKED_LIST_H
#define LINKED_LIST_H 

struct NodeInt {
  int data; 
  struct NodeInt *next;
};

struct LinkedList {
  struct NodeInt *first;
  struct NodeInt *last;
  int size;

  void(*push)(struct LinkedList *self, int data);
  int(*pop)(struct LinkedList *self);
  void(*print)(struct LinkedList *self);
  void(*forEach)(struct LinkedList *self, void(*callback)(int data, int index));

};

void push(struct LinkedList *self, int value);

void print(struct LinkedList *linked_list);

struct LinkedList* new_linked_list();

#endif