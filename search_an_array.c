#include <stdio.h>
#include <stdlib.h>

/*
 * This was the program we created in class to do searching of
 * a 'needle', or value in an array.
 *
 * Please be sure you understand how this program works.
 *
 * Understand what the STUBS were in this progran before we 
 * started.
 *
 * We also discussed specifying -DDEBUG when we compile the
 * program ( cc -DDEBUG search_an_array.c ).
 *
 * It would appear our compilers zero out memory for int arrays 
 * that are initialized, even if ALL values of the array aren't
 * set to a specific value.
 *
 * If you read chapter 7 in the textbook, specifically #6 and #7
 * on page 438-439, you learn that arrays declared in functions 
 * (such as main(), f(), etc.), space (RAM) is allocated in the
 * function data area.  Later on, you'll learn that this space is
 * in the program stack (p705), an area of memory reserved for 
 * local * variables.  You'll also learn later that the C 
 * standard stores 'auto' storage class variables on the program
 * stack, but stores 'static' storage class variables in memory
 * that is always zeroed out.
 *
 * We also discussed EXIT_FAILURE, and the use of the exit() 
 * function from stdlib.h that allows us to end a C program
 * immediately.
 *
 */

#define MAXSIZE 20
#define NOT_FOUND "Value %d was not found.\n"

int sum ( int list[], int n );
int search( const int list[MAXSIZE], const int n, const int needle );

int main()
{
	int list1 [ MAXSIZE ] = { 9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9 };
	int mylist[ MAXSIZE ] = { 5, 4, 3, 2, 1 };
	int list2 [ MAXSIZE ] = { 9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9 };


	mylist[ 10 ] = 10;

	printf ( "The sum is %d.\n",  sum( mylist, 5 ) );
	printf ( "The search for 3 returned %d.\n", search( mylist, 5, 3 ) );
	printf ( "The search for 1 returned %d.\n", search( mylist, 5, 1 ) );
	printf ( "The search for 8 returned %d.\n", search( mylist, 5, 8 ) );
	
	return EXIT_SUCCESS;
}

int sum ( int list[], int n )
{
#ifdef DEBUG
	puts( "In the function sum." );
#endif

	int i;
	int sum = 0;

	for ( i = 0; i < n; i++ )
		sum += list[i];

	return sum;
}


// Function:	search()
// postcondition:   If return value is equal to *n*, then the needle wasn't found.
int search( const int list[MAXSIZE], const int n, const int needle )
{
#ifdef DEBUG
	puts( "In the function search." );
#endif

	int i;
	for ( i = 0; ( list[i] != needle ) && ( i < n ); i++ )
		; // null loop

	if ( i == n ) {
		fprintf( stderr, NOT_FOUND, needle );
		exit( EXIT_FAILURE );
	}
	
	return i;

}
