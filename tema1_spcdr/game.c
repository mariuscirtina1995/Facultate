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

void get_s_r(long n, long *s, long *r)
{
	long i,j;
	for(i = 1; i <= sqrt(n); i++) {
		for(j = i; j <= sqrt(n); j++)
			if( i * i + j * j == n )
			{
	  			*s = i;
				*r = j;
				break;
			}
	}
}

bool is_4kAndPrim(long n)
{
	if(n < 4)
		return false;

	if(n % 4 == 1 && is_prime(n) == true)
		return true;

	return false;
}

int main(int argc, char *argv[] )
{
	long n;
	long s = 0, r = 0;

	printf("The argument supplied is %s\n", argv[1]);
	n = atol(argv[1]);

	if(is_4kAndPrim(n) == true) {
		get_s_r(n,&s,&r);
		printf("%ld %ld\n", s, r);
	}
	else {
		
		long left = n;
		long right = n;
		while(is_4kAndPrim(left) == false && is_4kAndPrim(right) == false) {
			left--;
			right++;
		}

		if(is_4kAndPrim(left) == true) {
			get_s_r(left,&s,&r);
			printf("left: %ld %ld %ld\n", left, s, r);
		}
		else {
			get_s_r(right,&s,&r);		
			printf("right: %ld %ld %ld\n", right, s, r);
		}
	}		

}
