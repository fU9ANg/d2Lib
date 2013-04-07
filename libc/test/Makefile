

##### makeassert
all: tassert

tassert: tassert.o d2assert.o
	cc -o tassert tassert.o d2assert.o -D_D2_LIBC
tassert.o: tassert.c d2assert.h
	cc -o tassert.o -c tassert.c -D_D2_LIBC
d2assert.o: d2assert.h d2assert.c
	cc -o d2assert.o -c d2assert.c -D_D2_LIBC

clean:
	-rm tassert tassert.o d2assert.o

##### makectype
all: tctype

tctype: tctype.o d2ctype.o d2assert.o
	cc -o tctype tctype.o d2ctype.o d2assert.o -D_D2_LIBC
tctype.o: tctype.c d2ctype.h
	cc -o tctype.o -c tctype.c -D_D2_LIBC
d2assert.o: d2assert.c d2assert.h
	cc -o d2assert.o -c d2assert.c -D_D2_LIBC
d2ctype.o: d2ctype.c d2ctype.h
	cc -o d2ctype.o -c d2ctype.c -D_D2_LIBC

clean:
	-rm tctype tctype.o d2ctype.o d2assert.o

##### makeerrno
all: terrno

terrno: terrno.o d2errno.o d2assert.o
	cc -o terrno terrno.o d2errno.o d2assert.o -lm -D_D2_LIBC
terrno.o: terrno.c d2errno.h
	cc -o terrno.o -c terrno.c -D_D2_LIBC
d2assert.o: d2assert.c d2assert.h
	cc -o d2assert.o -c d2assert.c -D_D2_LIBC
d2errno.o: d2errno.c d2errno.h
	cc -o d2errno.o -c d2errno.c -D_D2_LIBC

clean:
	-rm terrno terrno.o d2errno.o d2assert.o

##### makelimits
all: tlimits

tlimits: tlimits.o
	cc -o tlimits tlimits.o -D_D2_LIBC
tlimits.o: tlimits.c d2limits.h
	cc -o tlimits.o -c tlimits.c -D_D2_LIBC
#d2limits.o: d2limits.h d2limits.c
#	cc -o d2limits.o -c d2limits.c -D_D2_LIBC

clean:
	-rm tlimits tlimits.o

##### makesignal
all: tsignal

tsignal: tsignal.o d2signal.o d2assert.o
	cc -o tsignal tsignal.o d2signal.o d2assert.o -D_D2_LIBC
tsignal.o: tsignal.c
	cc -o tsignal.o -c tsignal.c -D_D2_LIBC
d2assert.o: d2assert.c d2assert.h
	cc -o d2assert.o -c d2assert.c -D_D2_LIBC
d2signal.o: d2signal.c d2signal.h
	cc -o d2signal.o -c d2signal.c -D_D2_LIBC

clean:
	-rm tsignal tsignal.o d2signal.o d2assert.o

##### makestdarg
all: tstdarg

tstdarg: tstdarg.o d2assert.o
	cc -o tstdarg tstdarg.o d2assert.o -D_D2_LIBC
tstdarg.o: tstdarg.c
	cc -o tstdarg.o -c tstdarg.c -D_D2_LIBC
d2assert.o: d2assert.c d2assert.h
	cc -o d2assert.o -c d2assert.c -D_D2_LIBC

clean:
	-rm tstdarg tstdarg.o d2assert.o

##### makestddef
all: tstddef

tstddef: tstddef.o d2assert.o
	cc -o tstddef tstddef.o d2assert.o -D_D2_LIBC
tstddef.o: tstddef.c d2limits.h d2stdarg.h
	cc -o tstddef.o -c tstddef.c -D_D2_LIBC
d2assert.o: d2assert.c d2assert.h
	cc -o d2assert.o -c d2assert.c -D_D2_LIBC

clean:
	-rm tstddef tstddef.o d2assert.o
