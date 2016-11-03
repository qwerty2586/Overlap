#include "intstack.h"
#include "errors.h"
#include <malloc.h>

Intstack *create_intstack(int start_size) {
    Intstack *s = (Intstack *) malloc(sizeof(Intstack));
    if (!s) exit_with_error(ERROR_OUT_OF_MEMORY);
    s->stacksize=start_size;
    s->current_item=EMPTY_STACK;
    s->stack = (int *) malloc(sizeof(int) * start_size);
    if (!s->stack) exit_with_error(ERROR_OUT_OF_MEMORY);
    return s;
}

void intstack_push(Intstack *s,int v) {
    if (s->current_item >= (s->stacksize-1)) {
        s->stacksize *= 2;
        s->stack = (int *) realloc(s->stack ,sizeof(int)* s->stacksize);
        if (!s->stack) exit_with_error(ERROR_OUT_OF_MEMORY);
    }
    s->stack[++(s->current_item)]=v;
}

int intstack_pop(Intstack *s) {
    if (intstack_isempty(s)) { return EMPTY_STACK;}
    return s->stack[s->current_item--];
}

int intstack_isempty(Intstack *s) {
    return (s->current_item==EMPTY_STACK);
}

void free_intstack(Intstack *s) {
    free(s->stack);
    free(s);
}