#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fetch(char byte[], int *j, int *c, int *d1, int *d0, int *Sreg, int *s, int imm[]) {
    if (byte == NULL) {
        printf("Null byte received in fetch\n");
        return 1;
    }

    *j = byte[0] - '0';
    *c = byte[1] - '0';
    *d1 = byte[2] - '0';
    *d0 = byte[3] - '0';
    *Sreg = byte[4] - '0';
    
    if (*j == 0 && *c == 0 && *Sreg == 0) {
        *s = byte[5] - '0';
    } else {
        *s = 0;
        imm[2] = byte[5] - '0';
    }
    
    imm[1] = byte[6] - '0';
    imm[0] = byte[7] - '0';

    return 0;
}
