# See LICENSE file for copyright and license details.

PREFIX = /usr/local

CC   = cc
SRC != find src -name "*.c"
OBJ  = ${SRC:.c=.o}

NAME    = utils
LIBNAME = lib${NAME}
LIBDSCR = A utility library
LIBVER  = 0.0.2

PC_FILE = ${NAME}.pc

CFLAGS  = -Wall --std=c99 -pedantic ${OPT} -DLIBVER=\"${LIBVER}\"

PKG_CONFIG_PATH != pkg-config --variable pc_path pkg-config | sed -E "s|.*(/usr/local[^:]*)[:].*|\1|g"
