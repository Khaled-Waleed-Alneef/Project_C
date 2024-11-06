#include <stdio.h>
#include <string.h>
#include <ctype.h>

void instr(char *bu3, char *bu2) {
    if (strcmp(bu3, "RA=RA+RB") == 0)
        strcpy(bu2, "00000000");
    else if (strcmp(bu3, "RB=RA+RB") == 0)
        strcpy(bu2, "00010000");
    else if (strcmp(bu3, "RA=RA−RB") == 0)
        strcpy(bu2, "00000100");
    else if (strcmp(bu3, "RB=RA−RB") == 0)
        strcpy(bu2, "00010100");
    else if (strcmp(bu3, "RO=RA") == 0)
        strcpy(bu2, "00100000");
    else if (strcmp(bu3, "RA=0") == 0)
        strcpy(bu2, "00001000");
    else if (strcmp(bu3, "RA=1") == 0)
        strcpy(bu2, "00001001");
    else if (strcmp(bu3, "RA=2") == 0)
        strcpy(bu2, "00001010");
    else if (strcmp(bu3, "RA=3") == 0)
        strcpy(bu2, "00001011");
    else if (strcmp(bu3, "RA=4") == 0)
        strcpy(bu2, "00001100");
    else if (strcmp(bu3, "RA=5") == 0)
        strcpy(bu2, "00001101");
    else if (strcmp(bu3, "RA=6") == 0)
        strcpy(bu2, "00001110");
    else if (strcmp(bu3, "RA=7") == 0)
        strcpy(bu2, "00001111");
    else if (strcmp(bu3, "RB=0") == 0)
        strcpy(bu2, "00011000");
    else if (strcmp(bu3, "RB=1") == 0)
        strcpy(bu2, "00011001");
    else if (strcmp(bu3, "RB=2") == 0)
        strcpy(bu2, "00011010");
    else if (strcmp(bu3, "RB=3") == 0)
        strcpy(bu2, "00011011");
    else if (strcmp(bu3, "RB=4") == 0)
        strcpy(bu2, "00011100");
    else if (strcmp(bu3, "RB=5") == 0)
        strcpy(bu2, "00011101");
    else if (strcmp(bu3, "RB=6") == 0)
        strcpy(bu2, "00011110");
    else if (strcmp(bu3, "RB=7") == 0)
        strcpy(bu2, "00011111");
    else if (strcmp(bu3, "JC=0") == 0)
        strcpy(bu2, "01110000");
    else if (strcmp(bu3, "JC=1") == 0)
        strcpy(bu2, "01110001");
    else if (strcmp(bu3, "JC=2") == 0)
        strcpy(bu2, "01110010");
    else if (strcmp(bu3, "JC=3") == 0)
        strcpy(bu2, "01110011");
    else if (strcmp(bu3, "JC=4") == 0)
        strcpy(bu2, "01110100");
    else if (strcmp(bu3, "JC=5") == 0)
        strcpy(bu2, "01110101");
    else if (strcmp(bu3, "JC=6") == 0)
        strcpy(bu2, "01110110");
    else if (strcmp(bu3, "JC=7") == 0)
        strcpy(bu2, "01110111");
    else if (strcmp(bu3, "J=0") == 0)
        strcpy(bu2, "01110000");
    else if (strcmp(bu3, "J=1") == 0)
        strcpy(bu2, "10110001");
    else if (strcmp(bu3, "J=2") == 0)
        strcpy(bu2, "10110010");
    else if (strcmp(bu3, "J=3") == 0)
        strcpy(bu2, "10110011");
    else if (strcmp(bu3, "J=4") == 0)
        strcpy(bu2, "10110100");
    else if (strcmp(bu3, "J=5") == 0)
        strcpy(bu2, "10110101");
    else if (strcmp(bu3, "J=6") == 0)
        strcpy(bu2, "10110110");
    else if (strcmp(bu3, "J=7") == 0)
        strcpy(bu2, "10110111");
    else 
	strcpy(bu2, "Nothing to Read!");
   
   
}

void asm_to_bin(char *bu1, char *bu2) {
    int i = 0;
    char bu3[100];
    while (*bu1 != '\0') {
         if(*bu1 != '\n'){  
	    if(*bu1 != ' ')
            bu3[i++] = toupper(*bu1);
	 }
        bu1++;
    }
    bu3[i] = '\0';
    instr(bu3, bu2);
}
