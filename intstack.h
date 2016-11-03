#ifndef INTSTACK
#define INTSTACK

#define EMPTY_STACK -1

#define DEFAULT_INTSTACK_START_SIZE 20

/* zasobnik intu pokud popneme EMPTY_STACK
 * znamena to ze je prazdny */
typedef struct {

    /*velikost pole*/
    int stacksize;
    /*pole polozek*/
    int *stack;
    /*vrchol zasobniku*/
    int current_item;

} Intstack;


/* alokuje strukturu v pameti */
Intstack *create_intstack(int start_size);
/* push */
void intstack_push(Intstack *s,int v);
/* pop */
int intstack_pop(Intstack *s);
/* vraci 0 pokud je prazdny */
int intstack_isempty(Intstack *s);
/* uvolnuje strukturu z pameti */
void free_intstack(Intstack *s);

#endif
