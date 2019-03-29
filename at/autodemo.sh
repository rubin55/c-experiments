#!/usr/bin/env bash

if [ -e autodemo ]; then rm -r autodemo; fi

mkdir -p autodemo
cd autodemo
cat > hello.c <<\
"--------------"
#include <stdio.h>

int main(){ printf("Hi.\n"); }
--------------

cat > Makefile.am <<\
"--------------"
bin_PROGRAMS=hello
hello_SOURCES=hello.c
--------------

autoscan
sed -e 's/FULL-PACKAGE-NAME/hello/' \
    -e 's/VERSION/1/'   \
    -e 's|BUG-REPORT-ADDRESS|/dev/null|' \
    -e '10i\
AM_INIT_AUTOMAKE' \
       < configure.scan > configure.ac

touch NEWS README AUTHORS ChangeLog

autoreconf -iv
./configure
make distcheck
