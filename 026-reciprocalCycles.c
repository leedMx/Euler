//Reciprocal Cycles, Euler Project Problem 26
/*
A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:

    1/2	= 	0.5
    1/3	= 	0.(3)
    1/4	= 	0.25
    1/5	= 	0.2
    1/6	= 	0.1(6)
    1/7	= 	0.(142857)
    1/8	= 	0.125
    1/9	= 	0.(1)
	1/10= 	0.1 

Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.
Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.*/

#include <stdio.h>
#define ARRAY_SIZE 1000
#define HIGHEST_NUMBER 1000

int divideOneBy(int);
int clearArray(int*);
int isInArray(int,int*);


int main(){
	int cycle;
	int highestCycle=0;
	int highestCycleNumber=0;
	

	for (int i=2; i<=HIGHEST_NUMBER ; i++){
		cycle=divideOneBy(i);
		if (cycle>highestCycle){
			highestCycle=cycle;
			highestCycleNumber=i;
		}
	}

	printf("%d has the largest cycle with %d digits\n",highestCycleNumber,highestCycle);
	return 0;
}

int divideOneBy(int divisor){
	int dividend=10;
	int digits=0;
	int remainders[ARRAY_SIZE];
	
//	printf("1/%d = \t0.",divisor);

	for(int i=0; i<ARRAY_SIZE; i++){
//		printf("%d",dividend/divisor);
		dividend=dividend%divisor;
		if (dividend==0){
//			printf("\n");
			break;
		}
		if (isInArray(dividend,remainders)){
//			printf("...\n");
			break;
		}
		remainders[i]=dividend;
		while(divisor>dividend){
			dividend*=10;
			digits++;
		}
	}
	clearArray(remainders);
	return digits;
}

int isInArray(int value, int*array){
	for (int i=0; i<ARRAY_SIZE ; i++){
		if(value==array[i])
			return 1;
	}
	return 0;
}

int clearArray(int*array){
	for (int i=0; i<ARRAY_SIZE ; i++){
		array[i]=0;
	}
	return 0;
}
