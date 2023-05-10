#!/bin/sh

cat <<EOF > print.sh
prefix=$1
exec_prefix=\${prefix}
includedir=\${prefix}/include
libdir=\${exec_prefix}/lib


Name: $2
Description: $3 - $4
Version: $5
Cflags: -I\${includedir}
Libs: -L\${libdir} -l$2
EOF
