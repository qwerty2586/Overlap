#ifndef ERRORS
#define ERRORS

/* cisla chyb */
#define ERROR_MISSING_ARGUMENT 1
#define ERROR_OUT_OF_MEMORY 2
#define ERROR_NON_EXISTENT_SOLUTION 3
#define ERROR_OPENING_FILE 4

/* texty chybovych hlasek */
#define ERROR_MISSING_ARGUMENT_TEXT "ERR#1: Missing argument!"
#define ERROR_OUT_OF_MEMORY_TEXT "ERR#2: Out of memory!"
#define ERROR_NON_EXISTENT_SOLUTION_TEXT "ERR#3: Non-existent solution!"
#define ERROR_OPENING_FILE_TEXT "ERR#4: Cant open file!"

/* vypise chybu v zadanem formatu,
 * ukonci program a preda systemu cislo chyby */
void exit_with_error (int err_no);


#endif
