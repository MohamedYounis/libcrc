project(crc32)

set (SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/crc32.c
    )
add_library (crc32 ${SOURCES})

set (LIBS
crc32
)
# Make sure the compiler can find include files for our crc library
# when other libraries or executables link to crc
#target_include_directories (crc32 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})