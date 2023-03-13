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
	./${NAME}

${SHARED}:
	@make -C ..

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJ}
	${CC} ${LFLAGS} -o $@ ${OBJ}

clean:
	rm -f ${OBJ} ${NAME} *.core
