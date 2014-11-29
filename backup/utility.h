#ifndef UTILITY_H
#define UTILITY_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LEN 20

typedef enum
{
    FALSE, TRUE
} BOOLEAN;

/*Clears residual data from stdin*/
void read_rest_of_line(void);
int getInteger(int* integer, unsigned length, char* prompt, int min, int max);
int getString(char* string, unsigned length, char* prompt);
#endif
