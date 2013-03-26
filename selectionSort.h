#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

// How to order the sort
#define SORT_ASCENDING  'a'
#define SORT_DESCENDING 'd'


// ----------------------------------------------------------------
// function prototypes

// public prototypes:  These are the functions in this header file 
//                     that are meant to be used by the programmer.
void sort_array( int a[], int n, char sortorder );
void sort_arrays( int a[], int n, int b[], char ordering );
void chomp( char a[] );
void skip_file_input_line( FILE *IN );


// ----------------------------------------------------------------


// private prototypes; These are functions in this header file
//                     that are used by other functions in this 
//                     header file.  They're not meant to be used
//                     by programmers (they're utility functions).
int  get_min_range( int a[], int first, int last );
int  get_max_range( int a[], int first, int last );
int  find_item_to_swap( int a[], char sortorder, int first, int last );


// ----------------------------------------------------------------









// function definitions
//     in a "real world" situation, this C code doesn't get put in the
//     header file.  We'll learn how to do this right in lab 9.
//     For now, it's useful to have it here.


// finds the smallest integer value in the array *a*.
int get_min_range( int a[], int first, int last )
{
	int i = first;
	int smallest = first;

	for ( i = first + 1 ; i <= last ; i++ ) 
		if ( a[ i ] < a[ smallest ] ) 
			smallest = i;

	return smallest;
}

// finds the largest integer value in the array *a*.
int get_max_range( int a[], int first, int last )
{
	int i = first;
	int largest = first;
	
	for ( i = first + 1; i <= last; i++ )
		if ( a[ i ] > a[ largest ] )
			largest = i;
		
	return largest;
}

// this function can be used instead of get_min_range or get_max_range.
int find_item_to_swap( int a[], char sortorder, int first, int last )
{
	int i = first;
	int swapitem = first;
	
	if ( sortorder == SORT_ASCENDING )
		for ( i = first + 1; i <= last; i++ ) {
			if ( a[ i ] > a[ swapitem ] )
				swapitem = i;
		}
	else if ( sortorder == SORT_DESCENDING ) 
		for ( i = first + 1; i <= last; i++ ) {
			if ( a[ i ] < a[ swapitem ] )
				swapitem = i;
		}
	else {
		puts( "Invalid sorting order passed to the "
			"function find_item_to_swap( )." );

		exit( EXIT_FAILURE );
	}
		    
	return swapitem;
}



// Sorts the array *a* in place.  
// 	Sorting in place means it changes the original array.
// Looks at the first *n* elements of array *a* only.
// ordering should be the value 'a' (SORT_ASCENDING)  or 'd' (SORT_DESCENDING)
void sort_array( int a[], const int n, const char ordering )
{
	int fill, temp, index_of_min;

	if ( ordering != SORT_ASCENDING && ordering != SORT_DESCENDING ) {
		printf( "Invalid sort ordering passed to function sort_array.  "
			"Value=%c.\n", ordering );
		printf( "Must be %c or %c.\n", SORT_ASCENDING, SORT_DESCENDING );
		exit( EXIT_FAILURE );
	}
	
	for ( fill = 0; fill < n - 1; ++fill ) {
	    index_of_min = find_item_to_swap( a, ordering, fill, n - 1 );

	    if ( fill != index_of_min ) {
		    temp = a[ index_of_min ];
		    a[ index_of_min ] = a[ fill ];
		    a[ fill ] = temp;
	    }
	} 

	return;
}



// sorts the arrays *a* and *b* in place.  
// 	Sorting in place means it changes the original arrays.
// Looks at the first *n* elements of array *a* only.
// ordering should be the value 'a' (SORT_ASCENDING)  or 'd' (SORT_DESCENDING)
void sort_arrays( int a[], int n, int b[], char ordering )
{
	int fill, temp, index_of_min;

	if ( ordering != SORT_ASCENDING && ordering != SORT_DESCENDING ) {
		printf( "Invalid sort ordering passed to function sort_array.  "
			"Value=%c.\n", ordering );
		printf( "Must be %c or %c.\n", SORT_ASCENDING, SORT_DESCENDING );
		exit( EXIT_FAILURE );
	}
	
	for ( fill = 0; fill < n - 1; ++fill ) {
	    index_of_min = find_item_to_swap( a, ordering, fill, n - 1 );

	    if ( fill != index_of_min ) {
		    temp = a[ index_of_min ];
		    a[ index_of_min ] = a[ fill ];
		    a[ fill ] = temp;

		    temp = b[ index_of_min ];
		    b[ index_of_min ] = b[ fill ];
		    b[ fill ] = temp;
	    }
	} 

	return;
}



void skip_file_input_line( FILE *IN )
{
        char c = fgetc( IN );

        while ( c != '\012' && ! feof ( IN ) ) 
                c = fgetc( IN );

        return;
}



void chomp( char a[] )
{
        int i = 0;

        // find the end of the string
        while ( a[i++] );
                // null body

        i -= 2;
        if ( a[ i ] == '\n' )
                a[ i ] = '\0';

        return;
}

#endif
