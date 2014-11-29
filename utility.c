#include "utility.h"
#include <string.h>

#define TRUE 1
#define FALSE 0
#define SUCCESS 1
#define FAILURE 0
#define TEMP_STRING_LENGTH 11

/* Tidy up residual data in stdin when encountering an error. You will 
 * need to use this when there is a possibility that there will be 
 * leftover characters in the input buffer. */
void read_rest_of_line(void)
{
    int ch;
    /* remove all characters from the buffer */
    while(ch = getc(stdin), ch!='\n' && ch!=EOF) 
        ;
    /* clear the error status of the input pointer */
    clearerr(stdin);
}

int getInteger(int* integer, unsigned length, char* prompt, int min, int max)
{
   int finished = FALSE;
   char tempString[TEMP_STRING_LENGTH + 2];
   int tempInteger = 0;
   char* endPtr;

   /* Continue to interact with the user until the input is valid. */
   do
   {
      /* Provide a custom prompt. */
      printf("%s", prompt);
      
      /* Accept input. "+2" is for the \n and \0 characters. */
      fgets(tempString, length + 2, stdin);

      /* A string that doesn't have a newline character is too long. */
      if (tempString[strlen(tempString) - 1] != '\n')
      {
         printf("Input was too long.\n");
         read_rest_of_line();
      }
      else
      {
         /* Overwrite the \n character with \0. */
         tempString[strlen(tempString) - 1] = '\0';

         /* Convert string to an integer. */
         tempInteger = (int) strtol(tempString, &endPtr, 10);

         /* Validate integer result. */
         if (strcmp(endPtr, "") != 0)
         {
            printf("Input was not numeric.\n");
         }
         else if (tempInteger < min || tempInteger > max)
         {
            printf("Input was not within range %d - %d.\n", min, max);
         }
         else
         {
            finished = TRUE;
         }
      }
   } while (finished == FALSE);

   /* Make the result integer available to calling function. */
   *integer = tempInteger;

   return SUCCESS;
}
int getString(char* string, unsigned length, char* prompt)
{
	int finished = FALSE;
	char tempString[TEMP_STRING_LENGTH + 2];
	/* Continue to interact with the user until the input is valid. */
	do
	{
	/* Provide a custom prompt. */
	printf("%s", prompt);
	/* Accept input. "+2" is for the \n and \0 characters. */
	fgets(tempString, length + 2, stdin);
	/* A string that doesn't have a newline character is too long. */
	if (tempString[strlen(tempString) - 1] != '\n')
	{
		printf("Input was too long.\n");
		read_rest_of_line();
	}
	else
	{
		finished = TRUE;
	}
	}
	while (finished == FALSE);
	/* Overwrite the \n character with \0. */
	tempString[strlen(tempString) - 1] = '\0';
	/* Make the result string available to calling function. */
	strcpy(string, tempString);
	return SUCCESS;
}



