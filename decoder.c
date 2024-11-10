#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int decoder(int d1, int d0) {
    if (d1 == 0 && d0 == 0) return 0;
    if (d1 == 0 && d0 == 1) return 1;
    if (d1 == 1 && d0 == 0) return 2;
    return -1;
}
