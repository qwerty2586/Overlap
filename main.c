/*
 * Seminarni prace predmetu Programovani v C
 * Reseni kolizi frekvence vysilacu
 *
 * (druhe zadani pro rok 2015/2016)
 *
 * zadani je mozno naleznout na
 * http://www.kiv.zcu.cz/studies/predmety/pc/doc/work/sw2015-02.pdf
 *
 * napsal Milan Hajzman
 * email qwerty2@students.zcu.cz
 *
 * Program je psany v ANSI C
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "overlap.h"
#include "errors.h"


/* delka nacitaciho retezce */
#define MAX_LINE_LENGTH 40

/* funkce pro nacteni vstupnich dat ze souboru
 * nejdrive zdana data nenacita a jenom
 * pocita pocty radku potom se vrati na zacatek
 * souboru a nacita je pomoci fscanf()
 * vraci nactenou strukturu overlap */
Overlap *load_file(char *filename) {
	Overlap *o;
	FILE *f;
	char s[MAX_LINE_LENGTH];
	int freqc = -1, transc = -1 ; /* pocet frekvenci a vysilacu */
	int i,freq,rad;
	double x,y;
		
	f = fopen(filename, "r");
	if (!f) exit_with_error(ERROR_OPENING_FILE);

	do {
		fgets(s,MAX_LINE_LENGTH,f);
	} while (strncmp(s,"Available frequencies:",20));
	
	do {
		freqc++;
		fgets(s,MAX_LINE_LENGTH,f);
	} while (isdigit(s[0]));
	
	do {
		fgets(s,MAX_LINE_LENGTH,f);
	} while (strncmp(s,"Transmitters:",13));
	
	do {
		transc++;
		fgets(s,MAX_LINE_LENGTH,f);
	} while (isdigit(s[0])&&s[0]!='\0'&&!feof(f));
	
	o=create_overlap(freqc,transc);
	if (!o)
		return o;
	rewind(f);
	
	do {
		fgets(s,MAX_LINE_LENGTH,f);
	} while (strncmp(s,"Available frequencies:",20));
	
	for (i=0;i<freqc;i++) {
		fscanf(f,"%d %d", &i,&freq);
		o->freqlist[i]=freq;
	}	
	
	do {
		fgets(s,MAX_LINE_LENGTH,f);
	} while (strncmp(s,"Transmission radius:",15));
	
	fscanf(f,"%d",&rad);
	o->radius=rad;
	
	do {
		fgets(s,MAX_LINE_LENGTH,f);
	} while (strncmp(s,"Transmitters:",13));
	
	for (i=0;i<transc;i++) {
		fscanf(f,"%d %lf %lf", &i,&x,&y);
		o->translist[i]=create_transmitter(x,y);
	}
	fclose(f);
	
	return o;	
}

int main(int argc, char *argv[]) {
	Overlap *overlap;
	int error;

	if (argc<2) {
		printf("Wrong count of arguments: %d \n", argc-1);
		printf("Please use correct syntax: %s <file-with-transmitters> \n", argv[0] );
		exit_with_error(ERROR_MISSING_ARGUMENT);
	}

	overlap = load_file(argv[1]);

	create_overlap_graph(overlap);

	error = find_lowest_frequencies(overlap);
	if (error!=EXIT_SUCCESS) exit_with_error(ERROR_NON_EXISTENT_SOLUTION);

	print_transmitter_list(overlap);
	free_overlap(overlap);
	
	return EXIT_SUCCESS;
	
}
