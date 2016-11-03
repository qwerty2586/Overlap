#ifndef NODE
#define NODE
/* polozka spojoveho seznamu sousedu */
typedef struct node {

	/* dalsi polozka */
	struct node *next;
	/* soused - index v poli vysilacu */
	int transmitter;

} Node;


/* alokuje polozku v pameti*/
Node *create_node(int t) ;

#endif

