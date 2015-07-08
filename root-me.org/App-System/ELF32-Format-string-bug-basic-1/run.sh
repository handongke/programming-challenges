
#gcc ch5.c -o  ch5

#objdump -D ch5 > dump.txt

# http://www.cplusplus.com/reference/cstdio/printf/

./ch5 'junk: %p %p %p %p %p %p :: LE-zero-teminated: %0.8llx %0.8llx %0.8llx %0.8llx'
