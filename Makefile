#
# Copyright (C) 2022  Alessandro Iezzi <aiezzi AT alessandroiezzi PERIOD it>
#
# This file is part of clist.
#
# clist is free software: you can redistribute it and/or modify
# it under the terms of the GNU Affero General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# clist is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Affero General Public License for more details.
#
# You should have received a copy of the GNU Affero General Public License
# along with clist.  If not, see <https://www.gnu.org/licenses/>.
#

CC   = clang
SRC != find src -name '*.c'
OBJ  = ${SRC:.c=.o}

VERSION  = 0.0.0

PREFIX   = /usr/local
WARNINGS = -Wall -Werror
CFLAGS   = -DVERSION='"${VERSION}"' ${WARNINGS} -ansi -pedantic -fPIC
LFLAGS   =

all: ${OBJ} liblist.so liblist.a

.c.o:
	${CC} -c ${CFLAGS} $< -o $@

liblist.so:
	${CC} -shared -o $@ ${OBJ}

liblist.a:
	ar rcs $@ ${OBJ}

clean:
	rm -f liblist.so ${OBJ} clist-${VERSION}.tar.gz
	@make -C test $@

dist: clean
	mkdir -p clist-${VERSION}
	cp -R LICENSE Makefile DOSmakefile README.md src test clist-${VERSION}
	tar -cf clist-${VERSION}.tar clist-${VERSION}
	gzip clist-${VERSION}.tar
	rm -rf clist-${VERSION}

install: all
	mkdir -p ${PREFIX}/lib/clist
	cp liblist.so ${PREFIX}/lib/clist/
