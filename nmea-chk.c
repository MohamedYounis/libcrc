#include <stdio.h>
#include <stdlib.h>
#include "checksum.h"

/*
 * unsigned char *checksum_NMEA( const unsigned char *input_str, unsigned char *result );
 *
 * The function checksum_NMEA() calculates the checksum of a valid NMEA string.
 * The routine does not try to validate the string itself. A leading '$' will
 * be ignored, as this character is part of the NMEA sentence, but not part of
 * the checksum calculation. The calculation stops, whenever a linefeed,
 * carriage return, '*' or end of string is scanned.
 *
 * Because there is no NMEA syntax checking involved, the function always
 * returns with succes, unless a NULL pointer is provided as parameter. The
 * return value is a pointer to the result buffer provided by the calling
 * application, or NULL in case of error.
 *
 * The result buffer must be at least three characters long. Two for the
 * checksum value and the third to store the EOS. The result buffer is not
 * filled when an error occurs.
 */

unsigned char * checksum_NMEA( const unsigned char *input_str, unsigned char *result ) {

	const unsigned char *ptr;
	unsigned char checksum;

	if ( input_str == NULL ) return NULL;
	if ( result    == NULL ) return NULL;

	checksum = 0;
	ptr      = (const unsigned char *) input_str;

	if ( *ptr == '$' ) ptr++;

	while ( *ptr  &&  *ptr != '\r'  &&  *ptr != '\n'  &&  *ptr != '*' ) checksum ^= *ptr++;

	snprintf( (char *) result, 3, "%02hhX", checksum );

	return result; 

}  /* checksum_NMEA */
