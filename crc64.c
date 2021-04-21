#include <stdbool.h>
#include <stdlib.h>
#include "checksum.h"

/*
 * Include the lookup table for the CRC 64 calculation
 */

#include "gentab64.h"

/*
 * uint64_t crc_64_ecma( const unsigned char *input_str, size_t num_bytes );
 *
 * The function crc_64_ecma() calculates in one pass the ECMA 64 bit CRC value
 * for a byte string that is passed to the function together with a parameter
 * indicating the length.
 */

uint64_t crc_64_ecma( const unsigned char *input_str, size_t num_bytes ) {

	uint64_t crc;
	const unsigned char *ptr;
	size_t a;

	crc = CRC_START_64_ECMA;
	ptr = input_str;

	if ( ptr != NULL ) for (a=0; a<num_bytes; a++) {

		crc = (crc << 8) ^ crc_tab64[ ((crc >> 56) ^ (uint64_t) *ptr++) & 0x00000000000000FFull ];
	}

	return crc;

}  /* crc_64_ecma */

/*
 * uint64_t crc_64_we( const unsigned char *input_str, size_t num_bytes );
 *
 * The function crc_64_we() calculates in one pass the CRC64-WE 64 bit CRC
 * value for a byte string that is passed to the function together with a
 * parameter indicating the length.
 */

uint64_t crc_64_we( const unsigned char *input_str, size_t num_bytes ) {

	uint64_t crc;
	const unsigned char *ptr;
	size_t a;

	crc = CRC_START_64_WE;
	ptr = input_str;

	if ( ptr != NULL ) for (a=0; a<num_bytes; a++) {

		crc = (crc << 8) ^ crc_tab64[ ((crc >> 56) ^ (uint64_t) *ptr++) & 0x00000000000000FFull ];
	}

	return crc ^ 0xFFFFFFFFFFFFFFFFull;

}  /* crc_64_we */

/*
 * uint64_t update_crc_64( uint64_t crc, unsigned char c );
 *
 * The function update_crc_64() calculates a new CRC-64 value based on the
 * previous value of the CRC and the next byte of the data to be checked.
 */

uint64_t update_crc_64( uint64_t crc, unsigned char c ) {

	return (crc << 8) ^ crc_tab64[ ((crc >> 56) ^ (uint64_t) c) & 0x00000000000000FFull ];

}  /* update_crc_64 */
