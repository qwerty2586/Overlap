#include <stdio.h>
#include <stdlib.h>
#include "errors.h" 

void exit_with_error (int err_no) {
    if (err_no==ERROR_MISSING_ARGUMENT) printf(ERROR_MISSING_ARGUMENT_TEXT);
    if (err_no==ERROR_OUT_OF_MEMORY) printf(ERROR_OUT_OF_MEMORY_TEXT);
    if (err_no==ERROR_NON_EXISTENT_SOLUTION) printf(ERROR_NON_EXISTENT_SOLUTION_TEXT);
    if (err_no==ERROR_OPENING_FILE) printf(ERROR_OPENING_FILE_TEXT);
    
    exit(err_no);
}