#include <stdio.h>
/* Counts the number of occurrences of each digit, the number */ /* of white space characters and the number of other characters. */
#define NUM_DIGITS 10

int main(void) {

int nwhite, nother, ndigit[NUM_DIGITS]; /* Counters. */ 
int c, i; /* Temporaries. */

/* Initialize all counts to zero. */
nwhite = nother = 0; 
for (i = 0; i < NUM_DIGITS; i++) ndigit[i] = 0;
/* Read each character from input and increment the */ /* appropriate counter. */
while ((c = getchar()) != EOF) { switch (c) 
{
/* Is it a digit? */
case ’0’ : 
case ’1’ :
 case ’2’ : 
 case ’3’ : 
 case ’4’ : 
 case ’5’ : 
 case ’6’ :
 case ’7’ : 
 case ’8’ : 
 case ’9’ : 
 ndigit[c-’0’]++; 
 break;
(over)
/* Is it a whitespace character? */
case ’ ’ : 
case ’\n’ : 
case ’\t’ : 
nwhite++;
 break;
/* Neither a digit nor a white space character. */
default : nother++; break;
} /* End of switch statement. */
} /* End of while loop */
/* Print the counts. */

	printf("Digits = "); for (i =0; i < NUM_DIGITS; i++) 
	printf("%d ", ndigit[i]);
	printf("\n White space = %d Other = %d\n", nwhite, nother);
return 0; } /* End of main. */