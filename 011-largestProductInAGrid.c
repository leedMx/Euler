//Largest Product In A Grid, Problem 11 in Euler Project
/*
In the 20×20 grid below, four numbers along a diagonal line have been marked in red.

 The product of these numbers is 26 × 63 × 78 × 14 = 1788696.

 What is the greatest product of four adjacent numbers in the same direction (up, down, left, right, or diagonally) in the 20×20 grid?*/

#include <stdio.h>

int populateGrid();
int printGrid();
int isHighest(long prospect);
int computeProducts(int x,int y);
int parseTwoCharsToInt(int position);
int computeLeftDiagProduct(int x,int y);
int computeDownProduct(int x,int y);
int computeRightDiagProduct(int x,int y);
int computeRightProduct(int x,int y);
int hasLeftLine(int x,int y);
int hasDownLine(int x,int y);
int hasRightLine(int x,int y);
long leftDiagProduct(int x,int y);
long downProduct(int x,int y);
long rightDiagProduct(int x,int y);
long rightProduct(int x,int y);

long maxProduct=0;
int maxPosition=0;
char* maxDirection;
int grid[20][20];
char content[]="08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08\
 49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00\
 81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65\
 52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91\
 22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80\
 24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50\
 32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70\
 67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21\
 24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72\
 21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95\
 78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92\
 16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57\
 86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58\
 19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40\
 04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66\
 88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69\
 04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36\
 20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16\
 20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54\
 01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48";

int main(){
	populateGrid();
	printGrid();
	for (int y=0;y<20;y++)
		for (int x=0;x<20;x++)
			computeProducts(x,y);
	printf("max=%ld pos=%d dir=%s\n",maxProduct,maxPosition,maxDirection);
	return 0;
}

int computeProducts(int x,int y){
	computeLeftDiagProduct(x,y);
	computeDownProduct(x,y);
	computeRightDiagProduct(x,y);
	computeRightProduct(x,y);
	return 0;
}

int computeLeftDiagProduct(int x,int y){
	if(hasLeftLine(x,y)&&hasDownLine(x,y)){
		if(isHighest(leftDiagProduct(x,y))){
			maxPosition=(y*20)+x+1;
			maxDirection="LD";}}
	return 0;
}

int computeDownProduct(int x,int y){
	if(hasDownLine(x,y)){
		if(isHighest(downProduct(x,y))){
			maxPosition=(y*20)+x+1;
			maxDirection="D";}}
	return 0;
}

int computeRightDiagProduct(int x,int y){
	if(hasRightLine(x,y)&&hasDownLine(x,y)){
		if(isHighest(rightDiagProduct(x,y))){
			maxPosition=(y*20)+x+1;
			maxDirection="RD";}}
	return 0;
}

int computeRightProduct(int x,int y){
	if(hasRightLine(x,y)){
		if(isHighest(rightProduct(x,y))){
			maxPosition=(y*20)+x+1;
			maxDirection="R";}}
	return 0;
}

int hasLeftLine(int x,int y){
	if ((x-3)<0)
		return 0;
	return 1;
}

int hasDownLine(int x,int y){
	if ((y+3)>=20)
		return 0;
	return 1;
}

int hasRightLine(int x,int y){
	if ((x+3)>=20)
		return 0;
	return 1;
}

long leftDiagProduct(int x,int y){
	long product=1;
	for (int i=0;i<4;i++)
	product=product*(grid[x-i][y+i]);
	return product;
}


long downProduct(int x,int y){
	long product=1;
	for (int i=0;i<4;i++)
	product=product*(grid[x][y+i]);
	return product;
}


long rightDiagProduct(int x,int y){
	long product=1;
	for (int i=0;i<4;i++)
	product=product*(grid[x+i][y+i]);
	return product;
}

long rightProduct(int x,int y){
	long product=1;
	for (int i=0;i<4;i++)
	product=product*(grid[x+i][y]);
	return product;
}

int isHighest(long prospect){
	if(prospect>maxProduct)
		maxProduct=prospect;
	return 1;
}

int populateGrid(){
	int i=0;
	for (int y=0;y<20;y++)
		for (int x=0;x<20;x++){
			grid[x][y]=parseTwoCharsToInt(i);
			i+=3;}
	return 0;
}

int parseTwoCharsToInt(int position){
	int a=(((int)content[position])-'0')*10;
	int b=((int)content[position+1])-'0';
	return a+b;
}

int printGrid(){
	for(int y=0;y<20;y++){
		for (int x=0;x<20;x++){
			printf("[%02d] ",grid[x][y]);}
		printf("\n");}
	return 0;
}
