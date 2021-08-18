#include <stdio.h> 
#include <unistd.h>
#include <stdlib.h>

unsigned int factorial(unsigned int n) 
{ 
	if (n==0) 
		return 1; 
	return n * factorial(n-1); 
} 

int main(int argc, char *argv[]) 
{ 
	int num;
	scanf("%d", &num); 
	printf("Factorial of %d is %d", num, factorial(num)); 
	printf("\n");
	return 0; 
} 

