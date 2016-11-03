#include "transmitter.h"
#include "errors.h"
#include <malloc.h>
#include <stdlib.h>
#include <math.h>


Transmitter *create_transmitter(double x, double y) {
	Transmitter *t = (Transmitter *) malloc (sizeof(Transmitter));
	if (!t) exit_with_error(ERROR_OUT_OF_MEMORY);
	t->x = x;
	t->y = y;
	t->node = NULL;
	t->freq=UNTUNED;
	return t;
}

void add_node(Transmitter *t, int t2) {
	Node *n = (Node *) malloc(sizeof(Node));
	if (!n) exit_with_error(ERROR_OUT_OF_MEMORY);
	n->next = t->node;
	n->transmitter = t2;
	t->node = n;
}

double length_between_transmitters(Transmitter *t1,Transmitter *t2) {
	double a,b,c;
	a = t1->x - t2->x;
	b = t1->y - t2->y;
	c = sqrt((a * a) + (b * b));
	return c;
}

void free_transmitter(Transmitter *t) {
	Node *n;
	while (t->node) {
		n = t->node;
		t->node = (t->node)->next;
		free (n);
	}
	free(t);
}
