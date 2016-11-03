#include "node.h"
#include "errors.h"
#include <malloc.h>
#include <stdlib.h>

Node *create_node(int t){
	Node *n=(Node *)malloc(sizeof(Node));
	if (!n) exit_with_error(ERROR_OUT_OF_MEMORY);
	n->transmitter=t;
	n->next=NULL;
	return n;
}

