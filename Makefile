# See LICENSE file for copyright and license details.

CC   = cc
SRC != find src -name '*.c'
OBJ  = ${SRC:.c=.o}
NAME = utils

LIBNAME = lib${NAME}
SHARED  = ${LIBNAME}.so
ARCHIVE = ${LIBNAME}.a
DISTNAME = ${LIBNAME}-${VERSION}

VERSION  = 0.0.1

PREFIX   = /usr/local
WARNINGS = -Wall -Werror -pedantic
STANDARD = -std=c99
CFLAGS   = -DVERSION='"${VERSION}"' ${WARNINGS} ${STANDARD} -fPIC
LFLAGS   = -shared

all: ${SHARED} ${ARCHIVE}

.c.o:
	${CC} -c ${CFLAGS} $< -o $@

${SHARED}: ${OBJ}
	${CC} ${LFLAGS} -o $@ ${OBJ}

${ARCHIVE}: ${OBJ}
	ar rcs $@ ${OBJ}

clean:
	rm -f ${SHARED} ${ARCHIVE}
	rm -f ${OBJ}
	rm -f ${DISTNAME}.tar.gz
	@make -C test $@

dist: clean
	mkdir -p ${DISTNAME}
	cp -R LICENSE Makefile DOSmakefile README.md src test ${DISTNAME}
	tar -cf ${DISTNAME}.tar ${DISTNAME}
	gzip ${DISTNAME}.tar
	rm -rf ${DISTNAME}

install: all
	mkdir -p ${PREFIX}/lib/${NAME}
	cp ${SHARED}  ${PREFIX}/lib/${NAME}/
	cp ${ARCHIVE} ${PREFIX}/lib/${NAME}/
	mkdir -p ${PREFIX}/include/${NAME}
	cp src/list.h ${PREFIX}/include/${NAME}/
	cp src/map.h  ${PREFIX}/include/${NAME}/

uninstall:
	rm -rf ${PREFIX}/lib/${NAME}
	rm -rf ${PREFIX}/include/${NAME}

tests: all
	@make -C test
