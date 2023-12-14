set (SOURCES
     crc32.c
     crc16.c
     )

set (HEADERS
     checksum.h 
     gentab32.h
     )

set (LIBS
    )

add_library (crc 
             ${SOURCES}
             ${HEADERS})

