
// Header part
#ifndef STRUCTURES_H_
#define STRUCTURES_H_

#include <stdbool.h>

typedef char* string;

// TODO Add Tree
// TODO Add Graph

typedef struct Stack {
  void **stack;
  int length;
} Stack;

typedef struct Queue { 
  void **queue;
  int length;
} Queue;

typedef struct LinkedList {
  void *value;
  struct LinkedList *next;
} LinkedList;

Stack *init_stack(int size);
void push(Stack *stack, void *value);
void *pop(Stack *stack);

Queue *init_queue(int size);
void enqueue(Queue *queue, void *value);
void *dequeue(Queue *queue);

LinkedList *init_linkedlist(void *value);
void add(LinkedList *ll, void *value);

#endif

// Implementation part
#ifdef STRUCTURES_IMPLEMENTATION

Stack *init_stack(int size) {
  Stack *stack = (Stack*) malloc(size * sizeof(Stack));
  stack->stack = (void**) malloc(size * sizeof(void*));
  stack->length = 0;
  return stack;
}

void push(Stack *stack, void *value) {
  stack->stack[stack->length++] = value;
}

void *pop(Stack *stack) {
  return stack->stack[--stack->length];
}

Queue *init_queue(int size) {
  Queue *queue = (Queue*) malloc(size * sizeof(Queue));
  queue->queue = (void**) malloc(size * sizeof(void*));
  queue->length = 0;
  return queue;
}

void enqueue(Queue *queue, void *value) {
  queue->queue[queue->length++] = value;
}

void *dequeue(Queue *queue) {
  return queue->queue[--queue->length];
}

LinkedList *init_linkedlist(void *value) {
  LinkedList *ll = (LinkedList*) malloc(sizeof(LinkedList));
  ll->value = value;
  ll->next = NULL;
  return ll;
}

void add(LinkedList *ll, void *value) {
  LinkedList *node = (LinkedList*) malloc(sizeof(LinkedList));
  node->value = value;
  ll->next = node;
  ll = ll->next;
}

#endif
