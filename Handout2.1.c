#include <stdio.h>

/* Reads two integers from stdin and prints their sum to stdout. */
int main(void) 
{
int x, y;
/* Get values for the two integers. */
printf("Enter the value of x: "); scanf("%d", &x);

printf("Enter value the of y: "); scanf("%d", &y);

/* Print the sum. */

printf("Sum = %d\n", x+y);
return 0;
} /* End of main. */