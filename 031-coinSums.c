//Coin Sums, Project Euler problem 31
/*
In England the currency is made up of pound, £, and pence, p, and there are eight coins in general circulation:

1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).

It is possible to make £2 in the following way:

1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p

How many different ways can £2 be made using any number of coins?*/

#include <stdio.h>

int selectCoinRecursively(int,int,int*);

int combinationCount=0;

int main(){
	int choices[8]={1,2,5,10,20,50,100,200};
	selectCoinRecursively(0,200,choices);
	printf("%d\n",combinationCount);
	return 0;
}

int selectCoinRecursively(int currentSum, int previousElement,int*choices){
	int newChoice;
	
	if(currentSum>200)
		return 0;

	if(currentSum==200){
		combinationCount++;
		return 0;
	}
	else{
		for(int i=0; i<8 ; i++){
			newChoice=choices[i];
			if (newChoice<=previousElement){
				currentSum+=newChoice;
				selectCoinRecursively(currentSum,newChoice,choices);
				currentSum-=newChoice;
			}
		}
	}

	return 0;
}
