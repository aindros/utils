#!/bin/sh

VERSION=0.0.1

while [ $# -gt 0 ]
do
	case $1 in
		-p|--prefix)
			shift
			PREFIX=$1
		;;
		-n|--name)
			shift
			NAME=$1
		;;
		-ln|--lib-name)
			shift
			LIBNAME=$1
		;;
		-d|--description)
			shift
			DESCR=$1
		;;
		-v|--version)
			shift
			VERSION=$1
		;;
		*)
			TARGET=$1
		;;
	esac
	shift
done

if [ -z $PREFIX ]; then
	echo 'prefix must be set'
	exit 1
elif [ -z $NAME ]; then
	echo 'name must be set'
	exit 1
fi

cat <<EOF > $TARGET
prefix=$PREFIX
exec_prefix=\${prefix}
includedir=\${prefix}/include
libdir=\${exec_prefix}/lib


Name: $NAME
Description: $LIBNAME - $DESCR
Version: $VERSION
Cflags: -I\${includedir}
Libs: -L\${libdir} -l$NAME
EOF
