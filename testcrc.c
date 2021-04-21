#include <inttypes.h>
#include <stdio.h>
#include <string.h>
#include "testall.h"

#include "checksum.h"

						/************************************************/
struct chk_tp {					/*						*/
	const char *	input;			/* The input string to be checked		*/
	uint8_t		crc8;			/* The  8 bit wide CRC8 of the input string	*/
	uint16_t	crc16;			/* The 16 bit wide CRC16 of the input string	*/
	uint32_t	crc32;			/* The 32 bit wide CRC32 of the input string	*/
	uint64_t	crc64_ecma;		/* The 64 bit wide CRC64-ECMA of the input	*/
	uint64_t	crc64_we;		/* The 64 bit wide CRC64-WE of the input string	*/
	uint16_t	crcdnp;			/* The 16 bit wide DNP CRC of the string	*/
	uint16_t	crcmodbus;		/* The 16 bit wide Modbus CRC of the string	*/
	uint16_t	crcsick;		/* The 16 bit wide Sick CRC of the string	*/
	uint16_t	crcxmodem;		/* The 16 bit wide XModem CRC of the string	*/
	uint16_t	crc1d0f;		/* The 16 bit wide CCITT CRC with 1D0F start	*/
	uint16_t	crcffff;		/* The 16 bit wide CCITT CRC with FFFF start	*/
	uint16_t	crckermit;		/* The 16 bit wide CRC Kermit of the string	*/
};						/*						*/
						/************************************************/

static struct chk_tp checks[] = {
	{ "123456789",    0xA2, 0xBB3D, 0xCBF43926ul, 0x6C40DF5F0B497347ull, 0x62EC59E3F1A4F00Aull, 0x82EA, 0x4B37, 0x56A6, 0x31C3, 0xE5CC, 0x29B1, 0x8921 },
	{ "Lammert Bies", 0xA5, 0xB638, 0x43C04CA6ul, 0xF806F4F5C0F3257Cull, 0xFE25A9F50630F789ull, 0x4583, 0xB45C, 0x1108, 0xCEC8, 0x67A2, 0x4A31, 0xF80D },
	{ "",             0x00, 0x0000, 0x00000000ul, 0x0000000000000000ull, 0x0000000000000000ull, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x1D0F, 0xFFFF, 0x0000 },
	{ " ",            0x86, 0xD801, 0xE96CCF45ul, 0xCC7AF1FF21C30BDEull, 0x568617D9EF46BE26ull, 0x50D6, 0x98BE, 0x2000, 0x2462, 0xE8FE, 0xC592, 0x0221 },
	{ NULL,           0,    0,      0,            0,                     0,                     0,      0,      0,      0,      0,      0,      0      }
};

/*
 * int test_crc( bool verbose );
 *
 * The function test_crc_32() tests the functionality of the implementation of
 * the CRC library functions on a specific platform.
 */

int test_crc( bool verbose ) {

	int a;
	int errors;
	int len;
	const unsigned char *ptr;

	uint32_t crc32;


	errors = 0;

	printf( "Testing CRC routines: " );

	a = 0;
	//while ( checks[a].input != NULL ) {

		ptr = (const unsigned char *) checks[a].input;
		len = strlen( checks[a].input );

		crc32      = crc_32(         ptr, len );


		if ( crc32 != checks[a].crc32 ) {

			if ( verbose ) printf( "\n    FAIL: CRC32 \"%s\" returns 0x%08" PRIX32 ", not 0x%08" PRIX32
							, checks[a].input, crc32, checks[a].crc32 );
			errors++;
		}
	
	if ( errors == 0 ) printf( "OK\n" );
	else {

		if ( verbose ) printf( "\n    " );
		printf( "FAILED %d checks\n", errors );
	}
//	}
	return errors;

}  /* test_crc */
