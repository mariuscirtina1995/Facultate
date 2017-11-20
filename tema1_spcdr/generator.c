#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>

bool is_prime(long n)
{
	int i;
	for(i = 2; i <= n/2; i++)
		if(n % i == 0)
			return false;
	return true;
}

bool is_4kAndPrim(long n)
{
	if(n % 4 == 1 && is_prime(n) == true)
		return true;

	return false;
}

int main(int argc, char *argv[] )
{
	long n;

	printf("The argument supplied is %s\n", argv[1]);
	n = atol(argv[1]);

	long i,j;
	for(i = 1; i <= n; i++)
		for(j = i; j <= n; j++)	{
			int x = i * i + j * j;

			if(is_4kAndPrim(x) == true)
				printf("%d ", x);
		}
	
	printf("\n");	
}
