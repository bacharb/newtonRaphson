#!/usr/bin/env bash

PREFIX=`pwd`/build

touch NEWS README AUTHORS ChangeLog

aclocal --install -I m4 &&
autoconf &&
automake 	--add-missing --copy &&
configure 	--prefix=$PREFIX "$@"
