# See LICENSE file for copyright and license details.

include config.mk

all: dist tests

dist: static shared
	./build-pc.sh -p ${PREFIX} -n ${NAME} -ln ${LIBNAME} -d "${LIBDSCR}" -v ${LIBVER} ${PC_FILE}

static:
	@make OPT='-O2 -pipe -Werror' ${LIBNAME:=.a}
	rm -f ${OBJ}

shared:
	@make OPT='-O2 -pipe -Werror -fPIC' ${LIBNAME:=.so}
	rm -f ${OBJ}

debug:
	@make OPT=-g all

${LIBNAME:=.so}: ${OBJ}
	${CC} ${LDFLAGS} -shared ${OBJ} -o $@

${LIBNAME:=.a}: ${OBJ}
	ar rcs $@ ${OBJ}

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${OBJ} ${LIBNAME}.* *.core ${PC_FILE}
	cd test && make clean

tests: dist
	@make -C test

install: dist
	mkdir -p ${PREFIX}/include
	mkdir -p ${PREFIX}/lib
	cp src/utils.h ${PREFIX}/include/utils.h
	cp ${LIBNAME:=.so} ${PREFIX}/lib/${LIBNAME:=.so}
	cp ${LIBNAME:=.a} ${PREFIX}/lib/${LIBNAME:=.a}
	cp ${PC_FILE} ${PKG_CONFIG_PATH}/${PC_FILE}

uninstall:
	rm -f ${PREFIX}/include/utils.h
	rm -f ${PREFIX}/lib/${LIBNAME:=.so}
	rm -f ${PREFIX}/lib/${LIBNAME:=.a}
	rm -f ${PKG_CONFIG_PATH}/${PC_FILE}
