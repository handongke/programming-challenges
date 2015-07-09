
gcc ch5.c -o  ch5

objdump -D ch5 > dump.txt

# http://www.cplusplus.com/reference/cstdio/printf/

./ch5 "%0.8llx %0.8llx %0.8llx %0.8llx %0.8llx %0.8llx %0.8llx"


exit

28 29 36 64 39 61 70 44 
b7 00 0a 64 6d 61 70 45

