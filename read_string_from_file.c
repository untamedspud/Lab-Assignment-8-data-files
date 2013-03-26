#include <stdio.h>
#include <stdlib.h>
#include "selectionSort.h"

// Using a C global constant variable.
// The only global variables you can use in your program are const.
const char *filename = "pop.txt";

int main()
{
        FILE *F;                // C file structure
        int pl;                 // holds the first value we read in from the file
        char city[30];          // holds the second value we read in from the file

        // associate the internal file name, F, with the external file name, pop.txt.
        F = fopen( filename, "r" );

        fscanf( F, "%d ", &pl );
        fgets( city, 30, F );
        chomp( city );                     // removes the newline at the end of the line read in
        while ( ! feof( F ) ) {
                printf( "Read in %d, city is %s.\n", pl, city );    // echo print!
                fscanf( F, "%d", &pl );    // scan in the first value from the file
                fgets( city, 30, F );      // reads in UP TO 30 characters, stopping at the 
                                           //     RETURN in the file
                chomp( city );             // removes the newline at the end of the line read in
        }

        fclose( F );

        return EXIT_SUCCESS;
}
