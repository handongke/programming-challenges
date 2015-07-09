#!/bin/sh

gcc -o ch13 ch13.c -fno-stack-protector

cat inputdata /dev/stdin | ./ch13
