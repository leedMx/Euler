//Euler project problem 3
/*
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
*/
#include <stdio.h>
#include <math.h>
#define NUMERO 64
#define LIMITE_SUPERIOR_PRIMOS 10000

int factorizar(long x);

int main(){
	printf("Factores Primos de %ld :\n",(long)NUMERO);
	factorizar(NUMERO);
	return 0;
}

int factorizar(long x){
	for (long i=2; i<LIMITE_SUPERIOR_PRIMOS; i++){
	if(x%i==0){
		printf("%ld es factor\n",i);
		x=x/i;
		printf("buscando factores de %ld\n",x);
		}
	}
	return 0;
}
