#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ALU(int RA, int RB, int s, int d1) {
    int result;
    if (s == 0 && d1 == 0) {
        result = RA + RB;
    } else if (s == 1) {
        result = RA - RB;
    } else {
        result = 0;
    }
    return result;
}
