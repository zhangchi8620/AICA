#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned char **createImage(int, int);
unsigned char **readPGM(char *, int *, int *, int *);
int writePGM(unsigned char **, int, int, int, char *);

