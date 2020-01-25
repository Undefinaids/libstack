#ifndef STACK_H_
#define STACK_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct stack_node_s {
    void *data;
    struct stack_node_s *previous;
} stack_node_t;

typedef struct stack_s {
    size_t size;
    void (*push)(struct stack_s *self, void *data);
    void *(*pop)(struct stack_s *self);
    void (*show)(struct stack_s *self);
    stack_node_t *content;
} stack_t;

stack_t *stack_init(void);
void stack_destroy(stack_t *self);

#endif /* STACK_H_ */