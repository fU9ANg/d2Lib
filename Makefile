
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
            -D_HASH_FUNC_TEST
# options for development
CFLAGS   =  $(INCLUDES) -g -Wall $(MAINFLAG)
CXXFLAGS =  $(INCLUDES) -g -Wall $(MAINFLAG)

D2_BM_OBJS      = d2_bm.o
D2_BM_TEST      = tst_d2_bm
D2_HASH_OBJS    = d2_hash.o
D2_HASH_TEST    = tst_d2_bash
D2_BASE_OBJS    = d2_base64.o
D2_BASE_TEST    = tst_d2_base64
all: $(D2_BM_TEST) $(D2_HASH_TEST) $(D2_BASE_TEST)

$(D2_BM_TEST):$(D2_BM_OBJS)
	$(CC) $(CFLAGS) $(LIB) $(D2_BM_OBJS)   -o $@ $(LINKS)
$(D2_BASE_TEST):$(D2_BASE_OBJS)
	$(CC) $(CFLAGS) $(LIB) $(D2_BASE_OBJS) -o $@ $(LINKS)
$(D2_HASH_TEST):$(D2_HASH_OBJS)
	$(CC) $(CFLAGS) $(LIB) $(D2_HASH_OBJS) -o $@ $(LINKS)

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o:%.c
	$(CC)  $(CFLAGS)   -c $< -o $@



.PHONY: clean
clean:
	-rm -rf *.o tst_*
