#!/bin/sh

gcc -o ch13 ch13.c -fno-stack-protector

cat inputdata | ./ch13
