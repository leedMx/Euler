//Non-Abundant Sums, Project Euler problem 23
/*
A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.*/

#include <stdio.h>

#define MAX 20162
#define ABUNDANTS_NEEDED 5000 

int populateAbundantArray();
int sumDivisors(int);
int populateNumberArray();
int discardAbundantSums();
int sumNumbers();

int abundantArray[ABUNDANTS_NEEDED];
int numberArray[MAX];
int abundants;

int main(){
	printf("%d abundants found below %d\n",abundants=populateAbundantArray(),MAX);
	populateNumberArray();
	discardAbundantSums();
	printf("Result:%d\n",sumNumbers());
	return 0;
}

int populateAbundantArray(){
	int position=0;
	
	for (int n=12 ; n<=MAX ; n++){
		if (sumDivisors(n)>n){
			abundantArray[position++]=n;
		}
	}
	return position;
}

int sumDivisors(int number){
	int sum=1;

	for (int i=2; (i*i)<=number ; i++){
		if ((number%i)==0){
			if (number/i==i) sum+=i;
			else sum+= i + (number/i);
		}
	}
	return sum;
}

int populateNumberArray(){
	for (int i=0 ; i<MAX ; i++)
		numberArray[i]=i;
	return 0;
}

int discardAbundantSums(){
	int sum;
	for (int i=0; i< abundants; i++){
		for (int j=i; j< abundants ; j++){
			sum=abundantArray[i]+abundantArray[j];
			if (sum>MAX) break;
			numberArray[sum]=0;
		}
	}
	return 0;
}

int sumNumbers(){
	int sum=0;
	for (int i=0 ; i<MAX ; i++){
		sum+=numberArray[i];
	}
	return sum;
}

