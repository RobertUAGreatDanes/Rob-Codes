#include <stdio.h> 
#include <stdlib.h>
/* The following program rolls a six-sided die 6000 times and */ /* counts the number of times the values 1 through 6 occur. */
#define SIZE 7 
#define NUM_FACES 6
#define SEED 937
#define NUM_TRIALS 6000
	int main(void) { 
	int face; /* Random die value: 1 to 6. */ 
	int count; /* Roll counter: 1 to 6000. */
	int i; /* Temporary. */
/* Array to keep track of frequencies. Note that array */ 
/* element 0 is not used in the program. */ 
	int frequency[SIZE];
/* Initialize all frequencies to 0. */ 
for (i = 1; i <= NUM_FACES; i++) 
	frequency[i] = 0;
/* Initialize the random number generator with the see value. */ 
	srand(SEED);
/* Roll the die 6000 times and update frequencies. */
for (count = 1; count <= NUM_TRIALS; count++)
	{ 
	face = 1 + rand() % NUM_FACES; /* Results in a value from 1 to 6. */ 

	frequency[face]++; }
	
	/* Print out the frequency values. */
for (i = 1; i <= NUM_FACES; i++) { 

	printf("%3d %5d\n", i, frequency[i]); 
}
return 0; } /* End of main. */