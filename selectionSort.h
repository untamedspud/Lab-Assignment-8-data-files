#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

// How to order the sort
#define SORT_ASCENDING  'a'
#define SORT_DESCENDING 'd'


// prototypes
void sort_array( int a[], int n, char sortorder );
int  get_min_range( int a[], int first, int last );
int  get_max_range( int a[], int first, int last );


int get_min_range( int a[], int first, int last )
{
	int i = first;
	int smallest = first;

	for ( i = first + 1 ; i <= last ; i++ ) 
		if ( a[ i ] < a[ smallest ] ) 
			smallest = i;

	return smallest;
}



int get_max_range( int a[], int first, int last )
{
	int i = first;
	int largest = first;
	
	for ( i = first + 1; i <= last; i++ )
		if ( a[ i ] > a[ largest ] )
			largest = i;
		
	return largest;
}

void sort_array( int a[], int n, char ordering )
{
	int fill, temp, index_of_min;
	
	if ( ordering == SORT_ASCENDING ) {
	    for ( fill = 0; fill < n - 1; ++fill ) {
		    index_of_min = get_min_range( a, fill, n - 1 );

		    if ( fill != index_of_min ) {
			    temp = a[ index_of_min ];
			    a[ index_of_min ] = a[ fill ];
			    a[ fill ] = temp;
		    }
	    }
	} 

	else 
	if ( ordering == SORT_DESCENDING ) {
	    for ( fill = 0; fill < n - 1; ++fill ) {
		    index_of_min = get_max_range( a, fill, n - 1 );

		    if ( fill != index_of_min ) {
			    temp = a[ index_of_min ];
			    a[ index_of_min ] = a[ fill ];
			    a[ fill ] = temp;
		    }
	    }
	} 

	else
		printf( "Invalid sort order passed: \"%c\".  Must be %c or %c.\n", ordering, SORT_ASCENDING, SORT_DESCENDING );

	return;
}

#endif
