//Number Spiral Diagonals, Euler Project problem 28
/*Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:

21 22 23 24 25
20  7  8  9 10
19  6  1  2 11
18  5  4  3 12
17 16 15 14 13

It can be verified that the sum of the numbers on the diagonals is 101.

What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?*/

#include <stdio.h>
#define TARGET_SIZE 1001

int sumCornersForThisLevel(int);

int main(){
	int sum=1;
	int lastLevel=(TARGET_SIZE+1)/2;

	for(int i=2; i<=lastLevel ; i++)
		sum+=sumCornersForThisLevel(i);		
	
	printf("sum= %d\n",sum);
	return 0;
}

int sumCornersForThisLevel(int level){
	int levelSize=(2*level)-1;
	int differenceBetweenCorners= 2*(level-1);
	int upperRightCorner= levelSize*levelSize;
	int upperLeftCorner= upperRightCorner-differenceBetweenCorners;
	int lowerLeftCorner= upperLeftCorner-differenceBetweenCorners;
	int lowerRightCorner= lowerLeftCorner-differenceBetweenCorners;
	int sum=upperRightCorner+upperLeftCorner+lowerLeftCorner+lowerRightCorner;
	return sum;
}

