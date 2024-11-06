#include <stdio.h>
#include <string.h>
#include "assembler.h"



int main(int argc, char* argv []) {
    char if1[100];
    char of1[100];	
    sprintf(if1, "%s.asm", argv[1]);
    sprintf(of1, "%s.bin", argv[1]);
	
    if(argc == 2){
    FILE *fp1 = fopen(if1, "r");
    FILE *fp2 = fopen(of1, "a");
    int i = 1;

    if (fp1 == NULL || fp2 == NULL) {
        printf("File not found\n");
        return 1;
    }
    char bu1[100], bu2[100];

    while (fgets(bu1, 100, fp1)) {
        if(bu1[0] != '\n'){
	asm_to_bin(bu1, bu2);
	fprintf(fp2, "%s\n", bu2);	
        printf("Line %d: %s -> Machine Code: %s\n",i,bu1,bu2);
        i++;
	}
    }

    fclose(fp1);
    fclose(fp2);
    }
    else
	printf("Wrong Argc!\n");
    return 0;
}
