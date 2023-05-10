# See LICENSE file for copyright and license details.

PREFIX = /usr/local/aiezzi

CC   = cc
SRC != find src -name "*.c"
OBJ  = ${SRC:.c=.o}

LIBNAME = libutils
LIBDSCR = A utility library
LIBVER  = 0.0.1

CFLAGS  = -Wall --std=c99 -pedantic ${OPT} -DLIBVER=\"${LIBVER}\"

PKG_CONFIG_PATH != pkg-config --variable pc_path pkg-config | sed -E "s|.*(${PREFIX}[^:]*)[:].*|\1|g"
