# See LICENSE file for copyright and license details.

CC   = cc
SRC != find * -name '*.c'
OBJ  = ${SRC:.c=.o}

LIBNAME  = utils
SHARED   = ../lib${LIBNAME}.so

#WARNINGS = -Wall -Werror -pedantic
STANDARD = -std=c99
CFLAGS   = ${WARNINGS} -I../src/
LFLAGS   = -l${LIBNAME} -L../ -Wl,-rpath=../

NAME = test1

all: ${SHARED} ${NAME}
	@echo
	@echo '+-----------------+'
	@echo '| Executing tests |'
	@echo '+-----------------+'
	@echo
	./${NAME}

${SHARED}:
	@make -C ..

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJ}
	${CC} ${LFLAGS} -o $@ ${OBJ}

clean:
	rm -f ${OBJ} ${NAME} *.core
