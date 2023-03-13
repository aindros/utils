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
VERSION  = 0.0.0

PREFIX   = /usr/local
WARNINGS = -Wall -Werror
CFLAGS   = -DVERSION='"${VERSION}"' ${WARNINGS} -ansi -pedantic -fPIC
LFLAGS   =

all: ${SHARED} ${ARCHIVE}

.c.o:
	${CC} -c ${CFLAGS} $< -o $@

${SHARED}: ${OBJ}
	${CC} -shared -o $@ ${OBJ}

${ARCHIVE}: ${OBJ}
	ar rcs $@ ${OBJ}

clean:
	rm -f ${SHARED} ${ARCHIVE}
	rm -f ${OBJ}
	rm -f *.tar.gz
	@make -C test $@

dist: clean
	mkdir -p clist-${VERSION}
	cp -R LICENSE Makefile DOSmakefile README.md src test clist-${VERSION}
	tar -cf clist-${VERSION}.tar clist-${VERSION}
	gzip clist-${VERSION}.tar
	rm -rf clist-${VERSION}

install: all
	mkdir -p ${PREFIX}/lib/${NAME}
	cp ${SHARED} ${PREFIX}/lib/${NAME}/
