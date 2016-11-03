#ifndef TRANSMITTER
#define TRANSMITTER
#include "node.h"

/* pocatecni frekvence vysilace */
#define UNTUNED -1

/* struktura prestavuje vysilac, osahuje jeho souradnice,
 * naladenou frekvenci a pocitek spojoveho seznamu
 * predtavujici jeho seznam sousedicich vysilacu*/
typedef struct {

	/* spojovy seznam sousedu */
	Node *node;
	/* pozice vysilace */
	double x,y;
	/* naladena frekvence, ve smyslu indexu v poli frekvenci */
	int freq;

} Transmitter;


/* alokuje strukturu v pameti */
Transmitter *create_transmitter(double x, double y);
/* pridani souseda do spojoveho seznamu
 * t2 je indexem v seznamu vysilacu */
void add_node(Transmitter *t, int t2);
/* vraci vzdalenost mezi dvema vysilaci */
double length_between_transmitters(Transmitter *t1,Transmitter *t2);
/* uvolni vysilac z pameti, vcetne spojoveho seznamu sousedu */
void free_transmitter(Transmitter *t);

#endif
