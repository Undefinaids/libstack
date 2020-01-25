#include "stack.h"

static void stack_show(stack_t *self) {
    stack_node_t *cell;
    size_t i = 0;

    cell = self->content;
    if (cell == NULL) {
        printf("Stack vide.\n");
        return;
    }
    printf("---------------\n");
    printf("-STACK-CONTENT-\n");
    while (cell != NULL) {
        printf("---------------\n");
        printf("%ld-%p\n", i, (cell->data));
        cell = cell->previous;
        i += 1;
    }
    printf("---------------\n");
    return;
}

static void stack_push(stack_t *self, void *data) {
    stack_node_t *data_node;

    data_node = malloc(sizeof(stack_node_t));
    if (data_node == NULL) {
        return;
    }
    data_node->data = data;
    data_node->previous = self->content;
    self->content = data_node;
    self->size += 1;
    return;
}

void *stack_pop(stack_t *self) {
    stack_node_t *data_node;
    void *data;

    if (self->content == NULL) {
        return (NULL);
    }
    data_node = self->content;
    self->content = data_node->previous;
    self->size -= 1;
    data = data_node->data;
    free(data_node);
    return (data);
}

stack_t *stack_init(void) {
    stack_t *stack;

    stack = malloc(sizeof(stack_t));
    if (stack == NULL) {
        return (NULL);
    }
    stack->size = 0;
    stack->push = &stack_push;
    stack->pop = &stack_pop;
    stack->show = &stack_show;
    stack->content = NULL;
    return (stack);
}

void stack_destroy(stack_t *self) {
    stack_node_t *data_prev;
    stack_node_t *data_node;

    data_node = self->content;
    while (data_node != NULL) {
        data_prev = data_node->previous;
        free(data_node);
        data_node = data_prev;
    }
    free(self);
}