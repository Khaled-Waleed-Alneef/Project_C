#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simulator.h"
#define MEM_SIZE 100

int main(int argc, char* argv []) {
    char f1[100];
    sprintf(f1,"%s.bin",argv[1]);
    FILE *fp = fopen(f1, "r");
    if (fp == NULL) {
        printf("Cannot open file\n");
        return 1;
    }
    char *mem[MEM_SIZE],ch1;
    int PC = 0;
    for (int i = 0; i < MEM_SIZE; i++) {
        mem[i] = NULL;
    }

    if (loader(mem, &PC,fp) != 0) {
        return 1; 
    }

    int RA = 0, RB = 0, RO = 0;
    int j, c, d1, d0, Sreg, s;
    int imm[3];
    int current_instruction = 0;

    printf("\n\nSelect one of the following mode\nR - Run in continuous mode\nS - Run step-by-step\n");
    scanf(" %c",&ch1);

    while (current_instruction < PC) {
        if (fetch(mem[current_instruction], &j, &c, &d1, &d0, &Sreg, &s, imm) != 0) {
            break;
        }

        int ALU_out = ALU(RA, RB, s, d1);
        int result = mux(ALU_out, imm[0], Sreg);
        int target_register = decoder(d1, d0);

        if (target_register == 0) {
            RA = result;
        } else if (target_register == 1) {
            RB = result;
        } else if (target_register == 2) {
            RO = RA;
        }
        
        printf("\nInstruction %d: ", current_instruction);
        if (target_register == 0) {
            printf("RA=%d", RA);
        } else if (target_register == 1) {
            printf("RB=%d", RB);
        } else if (target_register == 2) {
            printf("RO=%d", RO);
        }
       
       	if(ch1 == 'S'){	
        printf("\n[Press Enter to continue]");
        getchar();
        current_instruction++;
	}
	else if(ch1 == 'R'){
	current_instruction++;	
	}	
    }

    for (int i = 0; i < PC; i++) {
        free(mem[i]);
    }

    return 0;
}

