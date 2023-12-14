#include <stdbool.h>
#include <stdlib.h>
#include "checksum.h"

static void             init_crc16_tab( void );

static bool             crc_tab16_init          = false;
static uint16_t         crc_tab16[256];

/******************************************************************************
* Function Definitions
*******************************************************************************/

/// @brief a function to calculate the crc16 for a number of length data 
/// @param pData pointer to the first element of data
/// @param Length length of data to calculate crc16 for
/// @return the value of crc16 in union of type CRC16Type_t
CRC16Type_t crc16(uint8_t* const pData, const uint8_t Length)
{
  // uint16_t n;
  CRC16Type_t crc;
  crc.crc16 = 0xFFFF;
  uint8_t* pTmpData = pData;
  uint8_t tmpLength = Length;

  /****************************** CRC Calculation *******************************/
  const uint16_t ccitt_L[] = {
  0x0000, 0x1189, 0x2312, 0x329b, 0x4624, 0x57ad, 0x6536, 0x74bf,
  0x8c48, 0x9dc1, 0xaf5a, 0xbed3, 0xca6c, 0xdbe5, 0xe97e, 0xf8f7
  };

  const uint16_t ccitt_H[] = {
  0x0000, 0x1081, 0x2102, 0x3183, 0x4204, 0x5285, 0x6306, 0x7387,
  0x8408, 0x9489, 0xa50a, 0xb58b, 0xc60c, 0xd68d, 0xe70e, 0xf78f
  };

  while(tmpLength > 0U)
  {
    uint16_t n = *pTmpData ^ crc.crc16;
    crc.crc16  = ccitt_L[n & (uint16_t)0x0f] ^ ccitt_H[(n >> 4U) & (uint16_t)0x0f] ^ ((crc.crc16) >> 8U);
    pTmpData++;
    tmpLength--;
  }

  return crc;
}

/*
 * uint16_t crc_modbus( const unsigned char *input_str, size_t num_bytes );
 *
 * The function crc_modbus() calculates the 16 bits Modbus CRC in one pass for
 * a byte string of which the beginning has been passed to the function. The
 * number of bytes to check is also a parameter.
 */

uint16_t crc_modbus( const unsigned char *input_str, size_t num_bytes ) {

	uint16_t crc;
	const unsigned char *ptr;
	size_t a;

	if ( ! crc_tab16_init ) init_crc16_tab();

	crc = CRC_START_MODBUS;
	ptr = input_str;

	if ( ptr != NULL ) for (a=0; a<num_bytes; a++) {

		crc = (crc >> 8) ^ crc_tab16[ (crc ^ (uint16_t) *ptr++) & 0x00FF ];
	}

	return crc;

}  /* crc_modbus */

/*
 * uint16_t update_crc_16( uint16_t crc, unsigned char c );
 *
 * The function update_crc_16() calculates a new CRC-16 value based on the
 * previous value of the CRC and the next byte of data to be checked.
 */

uint16_t update_crc_16( uint16_t crc, unsigned char c ) {

	if ( ! crc_tab16_init ) init_crc16_tab();

	return (crc >> 8) ^ crc_tab16[ (crc ^ (uint16_t) c) & 0x00FF ];

}  /* update_crc_16 */

/*
 * static void init_crc16_tab( void );
 *
 * For optimal performance uses the CRC16 routine a lookup table with values
 * that can be used directly in the XOR arithmetic in the algorithm. This
 * lookup table is calculated by the init_crc16_tab() routine, the first time
 * the CRC function is called.
 */

static void init_crc16_tab( void ) {

	uint16_t i;
	uint16_t j;
	uint16_t crc;
	uint16_t c;

	for (i=0; i<256; i++) {

		crc = 0;
		c   = i;

		for (j=0; j<8; j++) {

			if ( (crc ^ c) & 0x0001 ) crc = ( crc >> 1 ) ^ CRC_POLY_16;
			else                      crc =   crc >> 1;

			c = c >> 1;
		}

		crc_tab16[i] = crc;
	}

	crc_tab16_init = true;

}  /* init_crc16_tab */
