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
SRC != find * -name '*.c'
OBJ  = ${SRC:.c=.o}

WARNINGS = -Wall -Werror
CFLAGS   = ${WARNINGS} -ansi -pedantic
LFLAGS   =

all: ../liblist.so ${OBJ} test1

../liblist.so:
	@make -C ..

.c.o:
	${CC} -I../src/ -c ${CFLAGS} $< -o $@

test1:
	${CC} -o $@ -L../ -Wl,-rpath=../ ${OBJ} -llist

clean:
	rm -f ${OBJ} test1
