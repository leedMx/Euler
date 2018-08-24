//Integer Rigth Triangles, Project Euler Problem 39
/*
If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, there are exactly three solutions for p = 120.

{20,48,52}, {24,45,51}, {30,40,50}

For which value of p ≤ 1000, is the number of solutions maximised?*/

#include <stdio.h>
#define print(ref) printf(#ref"=%d\n",ref);

int countSolutionsForP(int);

int main(){
	int max=0,prospect=0,maxSolutionsAt=0;

	for (int i=12; i<=1000 ; i++){
		prospect=countSolutionsForP(i);
		if(prospect>max){
			maxSolutionsAt=i;
			max=prospect;
		}
	}
	
	print(maxSolutionsAt)

	return 0;
}

int countSolutionsForP(int number){
	int solutions=0;
	int a=0,b=0,c=0;

	for (a=1; a<number ; a++){
		for(b=a+1; b<number-a ; b++){
			c=number-a-b;
			if( (c > b) && ( (a*a + b*b) == c*c) ){
					solutions++;
			}
		}
	}

	return solutions;
}
