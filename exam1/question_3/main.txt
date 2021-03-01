// Correct the following program:

// This program reads a string in argv[1], 
// stores it in a buffer created using malloc and 
// concatenates it with a second program. 
// (a) Describe all the errors in the program.  
// (b) Write the corrected program
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int main(int argc, char *argv[]) {
    int len = strlen(argv[1]) + 1; // needed to add 1 
    char *arr = (char *)  malloc(len); // this is now a correct size buffer

    if (arr != NULL) { // we have to prevent buffer overflow
        strcpy(arr, argv[1]); // there was a typo
        strcat(arr, " this is a test"); // this was actually correct
    }

    return 0;
}