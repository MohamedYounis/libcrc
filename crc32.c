#include <stdbool.h>
#include <stdlib.h>
#include "checksum.h"

/*
 * Include the lookup table for the CRC 32 calculation
 */

#include "gentab32.h"

/*
 * uint32_t crc_32( const unsigned char *input_str, size_t num_bytes );
 *
 * The function crc_32() calculates in one pass the common 32 bit CRC value for
 * a byte string that is passed to the function together with a parameter
 * indicating the length.
 */

uint32_t crc_32( const unsigned char *input_str, size_t num_bytes ) {

	uint32_t crc;
	const unsigned char *ptr;
	size_t a;

	crc = CRC_START_32;
	ptr = input_str;

	if ( ptr != NULL ) for (a=0; a<num_bytes; a++) {

		crc = (crc >> 8) ^ crc_tab32[ (crc ^ (uint32_t) *ptr++) & 0x000000FFul ];
	}

	return (crc ^ 0xFFFFFFFFul);

}  /* crc_32 */

/*
 * uint32_t update_crc_32( uint32_t crc, unsigned char c );
 *
 * The function update_crc_32() calculates a new CRC-32 value based on the
 * previous value of the CRC and the next byte of the data to be checked.
 */

uint32_t update_crc_32( uint32_t crc, unsigned char c ) {

	return (crc >> 8) ^ crc_tab32[ (crc ^ (uint32_t) c) & 0x000000FFul ];

}  /* update_crc_32 */
