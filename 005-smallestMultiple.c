//Smallest Possible, problem 5 Project Euler
/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/
#include <stdio.h>
#define NUMBER_OF_DIGITS 20

int poblateArray();
int tryDifferentFactors();
int divideByFactor(int factor);

int prueba[NUMBER_OF_DIGITS];
int smallestMultiple=1;

int main(){

	poblateArray();
	tryDifferentFactors();
	printf("Smallest multiple= %d \n",smallestMultiple);
	return 0;
}


int tryDifferentFactors(){
	for (int i=2;i<NUMBER_OF_DIGITS;i++)
	if (divideByFactor(i)){
		smallestMultiple=smallestMultiple*i;
		i--;
		}
	return 0;
}

int divideByFactor(int factor){ 
	int isFactorOfAtLeastOne=0;
	for (int i=0;i<NUMBER_OF_DIGITS;i++)
		if ((prueba[i]%(factor))==0){
			prueba[i]=prueba[i]/(factor);
			isFactorOfAtLeastOne=1;
			}
	return isFactorOfAtLeastOne;
}

int poblateArray(){
	for (int i=0;i<NUMBER_OF_DIGITS;i++)
		prueba[i]=i+1;
	return 0;
}
