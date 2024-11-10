#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mux(int ALU_out, int imm_val, int Sreg) {
    return (Sreg == 0) ? ALU_out : imm_val;
}
