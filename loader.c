#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEM_SIZE 100

int loader(char *mem[], int *PC,FILE *fp) {

    
    char bu[100];
    char byte[9];
    *PC = 0;

    while (fgets(bu, sizeof(bu), fp)) {
        int counter = 0;
        for (int i = 0; bu[i] != '\0' && bu[i] != '\n' && counter < 8; i++) {
            byte[counter] = bu[i];
            counter++;
        }
        if (counter == 8) {
            byte[8] = '\0';
            mem[*PC] = malloc(9);
            if (mem[*PC] == NULL) {
                printf("Memory allocation failed\n");
                fclose(fp);
                return 1;
            }
            strcpy(mem[*PC], byte);
            (*PC)++;
        }
    }
    fclose(fp);
    return 0;
}
