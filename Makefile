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
WARNINGS = -Wall -Werror
CFLAGS   = -DVERSION='"${VERSION}"' ${WARNINGS} -ansi -pedantic -fPIC
LFLAGS   =

all: ${OBJ} liblist.so

.c.o:
	${CC} -c ${CFLAGS} $< -o $@

liblist.so:
	${CC} -shared -o $@ ${OBJ}

clean:
	rm -f ${OBJ} liblist.so
