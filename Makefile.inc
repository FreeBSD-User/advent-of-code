ADVCROOT:= ${.PARSEDIR}
.PATH: . ${ADVCROOT}/lib

SRCS+= advc_utils.c

CFLAGS+= -I${ADVCROOT}/include
DBG?= -O0 -g -Wall
CSTD?= c23

WITH_CCACHE_BUILD=


MK_MAN=no
NO_OBJ=

# vim: ft=make
