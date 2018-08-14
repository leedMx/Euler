//Longest Collatz Problem
/*The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:
13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1

It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.*/

#include <stdio.h>
#define HIGHEST_POSSIBLE_N 1000000

int startSequenceFor(unsigned int);

unsigned int longest=0;

int main(){
	int prospect;
	for (unsigned int n=2; n<=HIGHEST_POSSIBLE_N ; n++){
		prospect=startSequenceFor(n);
		if (longest<prospect){
			longest=prospect;
			printf("%d terms for %d\n",prospect,n);
		}
	}
	return 0;
}

int startSequenceFor(unsigned int n){
	int count=1;
//	printf ("%d ->",n);
	while (n!=1){
//	printf ("%d ->",n);
		if (n%2==0)
			n=n/2;
		else
			n=(3*n)+1;
		count++;
	}
//	printf("1\n");
	return count;
}
