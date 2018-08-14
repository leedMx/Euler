//Maximum Path Sum, Project Euler problem 18
/*By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

3
7 4
2 4 6
8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom of the triangle below:

[saved into text file to be passed as stin]

NOTE: As there are only 16384 routes, it is possible to solve this problem by trying every route. However, Problem 67, is the same challenge with a triangle containing one-hundred rows; it cannot be solved by brute force, and requires a clever method! ;o) */

#include <stdio.h>
#define GRID_SIZE 15
#define VERBOSE 1

int populateLine(int);
int readNumber();
int printLineContent(int);
int calculateMaxSumForLine(int);
int highestPossibility(int,int);

int grid[GRID_SIZE][GRID_SIZE];

int main(){

	for (int i=0; i<GRID_SIZE ; i++){
		populateLine(i);
		if(VERBOSE)printLineContent(i);
	}	
	
	for (int i=(GRID_SIZE-2);i>=0;i--){
		calculateMaxSumForLine(i);
		if(VERBOSE)printLineContent(i);
	}
	
	printf("highest route value: %d\n",grid[0][0]);
	return 0;
}

int readNumber(){
	int input=0,number[2],digit=0;

	while ((input!=EOF)&&(input!='\n')&&(input!=32)){
		input=getchar();
		if ((input>='0')&&(input<='9')){
			number[digit]=input-'0';
//			printf ("%d ",number[digit]);
			digit++;
		}
	}

	return (number[0]*10)+number[1];
}

int populateLine(int lineNumber){
		for(int i=0;i<=lineNumber;i++)
			grid[lineNumber][i]=readNumber();
	return 0;
}

int printLineContent(int lineNumber){
	for (int i=0; i<GRID_SIZE ; i++)
		if (grid[lineNumber][i]!=0)
			printf ("%d\t ",grid[lineNumber][i]);
		
	printf("\n");
	return 0;	
}

int calculateMaxSumForLine(int x){
	for(int i=0;i<=x;i++)
			grid[x][i]+=highestPossibility(x,i);
	return 0;
}

int highestPossibility(int x,int y){
	int a=grid[x+1][y];
	int b=grid[x+1][y+1];
	if (a>b)
		return a;
	return b;
}

