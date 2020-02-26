#include <stdio.h>
#define LOWER 0 
#define UPPER 300 
#define STEP 20

/* Prints a Farenheit-Celsius table. */

int main(void) {

int fahr;

for (fahr = LOWER; fahr <= UPPER; fahr += STEP) {

	printf("%4d %6.1f\n", fahr, (5.0/9.0)*(fahr - 32.0)); 
	
	} return 0;
} /* End of main. */