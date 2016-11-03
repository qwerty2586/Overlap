#ifndef OVERLAP
#define OVERLAP 
#include "transmitter.h"


/* hlavni struktura v pameti obsahuje 
 * seznam dostupnych frekvenci a vysilacu */
typedef struct {
	
	/* pole s frekvencemi */
	int *freqlist;
	/* dvojity p ointer ve smyslu pole ukazatelu na vysilac */
	Transmitter **translist;
	/* delky poli */
	int freqc,translistc;
	/* maximalni vzdalenost mezi dvema vysilaci
	 * pri niz dochazi ke kolizi signalu */
	int radius;
	
} Overlap;


/* alokuje overlap */
Overlap *create_overlap(int freqc,int translistc);
/* podle vzdalenosti mezi vysilaci vytvori sousedni vazby*/
void create_overlap_graph(Overlap *o);
/* prochazeni grafu a ladeni frekvenci vysilacu */
int find_lowest_frequencies(Overlap *o);
/* vypis vsech vysilacu */
void print_transmitter_list(Overlap *o);
/* uvolneni overlapu z pameti */
void free_overlap(Overlap *o);

#endif
