#
# Copyright (C) 2022-2023  Alessandro Iezzi <aiezzi AT alessandroiezzi PERIOD it>
#
# This file is part of libutils.
#
# libutils is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# libutils is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with libutils. If not, see <https://www.gnu.org/licenses/>.
#

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
