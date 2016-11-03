#include "overlap.h"
#include "intstack.h"
#include "errors.h"
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

Overlap *create_overlap(int freqc, int translistc) {
	Overlap *o = (Overlap *)malloc (sizeof(Overlap));
	if (!o) exit_with_error(ERROR_OUT_OF_MEMORY);
	o->freqc = freqc;
	o->translistc = translistc;
	o->freqlist = (int *) malloc (sizeof(int) * freqc);
	if (!o->freqlist) exit_with_error(ERROR_OUT_OF_MEMORY);
	o->translist = (Transmitter **) malloc (sizeof(Transmitter *) * translistc);
	if (!o->translist) exit_with_error(ERROR_OUT_OF_MEMORY);
	return o;
}

void create_overlap_graph(Overlap *o) {
	int i,u;
	double l;
	for (i=0;i<o->translistc;i++) {
 		for (u=0;u<o->translistc;u++) {
			if (i!=u) {
				l = length_between_transmitters(o->translist[i],o->translist[u]);
				if(l<=(o->radius*2)) {
					add_node(o->translist[i],u);
				}
			}
		}
	}
}


int find_lowest_frequencies(Overlap *o) {
	int i,t,interference;
	Node *n;
	Intstack *s;

	s = create_intstack(DEFAULT_INTSTACK_START_SIZE);
	/*nekonecna smycka ma vice vystupnich situaci*/
	while (TRUE) {

		/* zarazeni prvniho nenaladeneho transmiteru do zasobniku*/
		i=0;
		while (TRUE) {
			if (i >= o->translistc) {
				/* nenalezame zadny nenaladeny transmiter - hotovo */
				free_intstack(s);
				return EXIT_SUCCESS;
			}
			if ((o->translist[i])->freq==UNTUNED) {
				intstack_push(s,i);
				break;
			}
			i++;
		}


		/* prochazeni stacku s nenaladenymi vrcholy*/
		while (!intstack_isempty(s)) {
			t = intstack_pop(s);
			if ((o->translist[t])->freq!=UNTUNED) continue; /* pokud jiz naladeno pokracuj dal v zasobniku */
			i=0;
			while (TRUE) {
				if (i>= o->freqc) {
					/*dosli frekvence*/
					free_intstack(s);
					return EXIT_FAILURE;
				}
				interference = FALSE;
				n = (o->translist[t])->node;
				while (n) {
					if ((o->translist[n->transmitter])->freq==i) interference = TRUE;
					n=n->next;
				}
				if (!interference) {
					/* u sousedu nekoliduji zadne frekvence - ladime */
					(o->translist[t])->freq=i;
					/* ted je zapotrebi pridat sousedy do stacku */
					n = (o->translist[t])->node;
					while (n) {
						if ((o->translist[n->transmitter])->freq==UNTUNED) intstack_push(s,n->transmitter);
						n=n->next;
					}
					break;
				}
				i++;
			}
		}
	}

	/* sem bychom jsme se nemeli dostat ale co budiz */
	free_intstack(s);
	return EXIT_FAILURE;
}

void print_transmitter_list(Overlap *o) {
	int i;
	for (i=0;i<o->translistc;i++) {
		printf("%d %d\n",i,o->freqlist[(o->translist[i])->freq]);
	}
}


void free_overlap(Overlap *o) {
	int i;
	free(o->freqlist);
	for (i=0;i<o->translistc;i++) {
		free_transmitter(o->translist[i]);
	}
	free(o->translist);
	free(o);

}
