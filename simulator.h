#ifndef SIMULATOR_H
#define SIMULATOR_H

#define MEM_SIZE 100

int loader(char *mem[], int *PC,FILE *fp);
int fetch(char byte[], int *j, int *c, int *d1, int *d0, int *Sreg, int *s, int imm[]);
int mux(int ALU_out, int imm_val, int Sreg);
int decoder(int d1, int d0);
int ALU(int RA, int RB, int s, int d1);

#endif
