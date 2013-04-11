
#
# fU9ANg (backbonejym@163.com)
#

# which c compiler
CC       = gcc

# which c++ compiler
CXX      = g++

# ar program
AR       = ar rc

# where are include files kept
INCLUDES = -I.
LIB      = -L.
LINKS    = -lpthread -lm

# define some macro for standalone
MAINFLAG =  -D_BASE_STANDALONE  \
            -D_BM_STANDALONE    \
            -D_HASH_FUNC_TEST   \
            -D_TEST_STRSTR_MAIN \
            -D_CRC8_STANDALONE  \
            -D_CRC16_STANDALONE \
            -D_CRC32_STANDALONE \
            -D_PRINT_STANDALONE

# options for development
CFLAGS   =  $(INCLUDES) -g -Wall $(MAINFLAG)
CXXFLAGS =  $(INCLUDES) -g -Wall $(MAINFLAG)

D2_BM_OBJS      = d2_bm.o
D2_BM_TEST      = tst_d2_bm
D2_HASH_OBJS    = d2_hash.o
D2_HASH_TEST    = tst_d2_bash
D2_BASE_OBJS    = d2_base64.o
D2_BASE_TEST    = tst_d2_base64
D2_STRING_OBJS  = d2_string.o d2_ctype.o
D2_STRING_TEST  = tst_d2_string
D2_CRC8_OBJS    = d2_crc8.o
D2_CRC8_TEST    = tst_d2_crc8
D2_CRC16_OBJS   = d2_crc16.o
D2_CRC16_TEST   = tst_d2_crc16
D2_CRC32_OBJS   = d2_crc32.o
D2_CRC32_TEST   = tst_d2_crc32
D2_PRINTF_OBJS  = d2_printf.o
D2_PRINTF_TEST  = tst_d2_print

all:    $(D2_STRING_TEST)   \
        $(D2_BM_TEST)       \
        $(D2_HASH_TEST)     \
        $(D2_BASE_TEST)     \
        $(D2_CRC8_TEST)     \
        $(D2_CRC16_TEST)    \
        $(D2_CRC32_TEST)    \
        $(D2_PRINTF_TEST)

$(D2_BM_TEST):$(D2_BM_OBJS)
	$(CC) $(CFLAGS) $(LIB) $(D2_BM_OBJS)   -o $@ $(LINKS)
$(D2_BASE_TEST):$(D2_BASE_OBJS)
	$(CC) $(CFLAGS) $(LIB) $(D2_BASE_OBJS) -o $@ $(LINKS)
$(D2_HASH_TEST):$(D2_HASH_OBJS)
	$(CC) $(CFLAGS) $(LIB) $(D2_HASH_OBJS) -o $@ $(LINKS)
$(D2_STRING_TEST):$(D2_STRING_OBJS)
	$(CC) $(CFLAGS) $(LIB) $(D2_STRING_OBJS) -o $@ $(LINKS)
$(D2_CRC8_TEST):$(D2_CRC8_OBJS)
	$(CC) $(CFLAGS) $(LIB) $(D2_CRC8_OBJS) -o $@ $(LINKS)
$(D2_CRC16_TEST):$(D2_CRC16_OBJS)
	$(CC) $(CFLAGS) $(LIB) $(D2_CRC16_OBJS) -o $@ $(LINKS)
$(D2_CRC32_TEST):$(D2_CRC32_OBJS)
	$(CC) $(CFLAGS) $(LIB) $(D2_CRC32_OBJS) -o $@ $(LINKS)
$(D2_PRINTF_TEST):$(D2_PRINTF_OBJS)
	$(CC) $(CFLAGS) $(LIB) $(D2_PRINTF_OBJS) -o $@ $(LINKS)

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o:%.c
	$(CC)  $(CFLAGS)   -c $< -o $@



.PHONY: clean
clean:
	-rm -rf *.o tst_*
