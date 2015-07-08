/*
 * specific ld opts: -lcrypt
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <crypt.h>
#include <sys/types.h>
#include <unistd.h>

int main (int argc, char *argv[]) {
    char pid[16];

    int id;
    for (id = 0;  id < 32000; id++) {
     snprintf(pid, sizeof(pid), "%i", id);
     printf("%s %s\n",pid, crypt(pid, "$1$awesome"));
   }
}

