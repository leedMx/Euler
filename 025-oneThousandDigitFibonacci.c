//1000-Digit Fibonacci Number, Project Euler Problem 25
/*

The Fibonacci sequence is defined by the recurrence relation:
    Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
Hence the first 12 terms will be:
	    F1 = 1
	    F2 = 1
	    F3 = 2
	    F4 = 3
	    F5 = 5
	    F6 = 8
	    F7 = 13
	    F8 = 21
	    F9 = 34
	    F10 = 55
	    F11 = 89
	    F12 = 144
The 12th term, F12, is the first term to contain three digits.
What is the index of the first term in the Fibonacci sequence to contain 1000 digits?*/

#include <stdio.h>
#define TARGET_SIZE 1000

int sumNumbers(int*,int*,int*);
int shiftForFibonacci(int*,int*,int*);
int printNumber(int*);

int fibonacciIndex=2;
int resultLength=1;

int main(){
	int numberA[TARGET_SIZE]={1};
	int numberB[TARGET_SIZE]={1};
	int result[TARGET_SIZE+1]={0};
	
	while(resultLength<TARGET_SIZE){
		sumNumbers(numberA,numberB,result);
		shiftForFibonacci(numberA,numberB,result);
		fibonacciIndex++;
	}
	
	printNumber(numberB);
	printf("Term F %d contains %d digits\n",fibonacciIndex,resultLength);


	return 0;
}

int sumNumbers(int*numberA, int*numberB, int*result){
	for(int position=0; position<resultLength ; position++){
		result[position]+=numberA[position]+numberB[position];
		if (result[position]>9){
			result[position+1]+=result[position]/10;
			result[position]=result[position]%10;
			if(position==(resultLength-1)) resultLength++;
		}
	}
	return 0;
}

int shiftForFibonacci(int*numberA,int*numberB,int*result){
	for (int i=0; i<TARGET_SIZE ; i++){
		numberA[i]=numberB[i];
		numberB[i]=result[i];
		result[i]=0;
	}
	return 0;
}
	
int printNumber(int*number){
	for (int i=(resultLength-1); i>=0 ; i--)
		printf("%d",number[i]);
	printf("\n");
	return 0;
}
