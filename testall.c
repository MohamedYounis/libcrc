#include <stdio.h>
#include <stdlib.h>
#include "testall.h"

/*
 * int main( void );
 *
 * Testall is a commandline utility that tests the functionality of the libcrc
 * routines on a the current platform. The result is printed to stdout. The
 * program returns an integer value which can be catched by a shell script. The
 * value is equal to the number of errors encountered.
 */

int main( void ) {

	int problems;

	printf( "\n" );

	problems  = 0;
	problems += test_crc( true );


	printf( "\n" );

	if ( problems == 0 ) printf( "**** All tests succeeded\n\n" );
	else                 printf( "**** A TOTAL OF %d TESTS FAILED, PLEASE CORRECT THE DETECTED PROBLEMS ****\n\n", problems );

	return problems;

}  /* main (libcrc test) */
