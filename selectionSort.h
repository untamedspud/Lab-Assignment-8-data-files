#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

// How to order the sort
#define SORT_ASCENDING  'a'
#define SORT_DESCENDING 'd'


// prototypes

// public prototyes
void sort_array( int a[], int n, char sortorder );
void chomp( char a[] );
void skip_file_input_line( FILE *IN );

// private prototypes
int  get_min_range( int a[], int first, int last );
int  get_max_range( int a[], int first, int last );


// find the smallest item in the array
int get_min_range( int a[], int first, int last )
{
	int i = first;
	int smallest = first;

	for ( i = first + 1 ; i <= last ; i++ ) 
		if ( a[ i ] < a[ smallest ] ) 
			smallest = i;

	return smallest;
}

// find the largest item in the array
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
		puts( "Invalid sorting order passed to function find_item_to_swap( )." );
		exit( EXIT_FAILURE );
	}
		    
	return swapitem;
}

void sort_array( int a[], int n, char ordering )
{
	int fill, temp, index_of_min;

	if ( ordering != SORT_ASCENDING && ordering != SORT_DESCENDING ) {
		printf( "Invalid sort ordering passed to function sort_array.  Value=%c.\n", ordering );
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



void skip_file_input_line( FILE *IN )
{
        char c = fgetc( IN );

        while ( c != '\012' && ! feof ( IN ) ) 
                c = fgetc( IN );

        return;
}


void chomp( char a[] )
{
        int i;

        // find the end of the string
        while ( a[i++] );
                // null body

        i -= 2;
        if ( a[ i ] == '\n' )
                a[ i ] = '\0';

        return;
}

#endif
