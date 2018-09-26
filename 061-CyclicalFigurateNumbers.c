//Cyclical Figurate Numbers, Euler Project Problem 61
/* 
Triangle, square, pentagonal, hexagonal, heptagonal, and octagonal numbers are all figurate (polygonal) numbers and are generated by the following formulae:
Triangle 	  	P_3,n=n(n+1)/2 	  	1, 3, 6, 10, 15, ...
Square 	  		P_4,n=n^2		  	1, 4, 9, 16, 25, ...
Pentagonal 	  	P_5,n=n(3n−1)/2	  	1, 5, 12, 22, 35, ...
Hexagonal 	  	P_6,n=n(2n−1) 	  	1, 6, 15, 28, 45, ...
Heptagonal 	  	P_7,n=n(5n−3)/2	  	1, 7, 18, 34, 55, ...
Octagonal 	  	P_8,n=n(3n−2) 	  	1, 8, 21, 40, 65, ...

The ordered set of three 4-digit numbers: 8128, 2882, 8281, has three interesting properties.
 The set is cyclic, in that the last two digits of each number is the first two digits of the next number (including the last number with the first).
 Each polygonal type: triangle (P3,127=8128), square (P4,91=8281), and pentagonal (P5,44=2882), is represented by a different number in the set.
 This is the only set of 4-digit numbers with this property.

Find the sum of the only ordered set of six cyclic 4-digit numbers for which each polygonal type: triangle, square, pentagonal, hexagonal, heptagonal, and octagonal, is represented by a different number in the set. */

#include <stdio.h>
#define print(ref) printf(#ref" = %d\n",ref);

int exploreSolutions(int*,int*,int);
void solutionFound(int*);
int isNgonal(int,int);
int isValidLink(int,int);
void markAllPoligons(int);
void markTriangle(int);
void markSquare(int);
void markPentagon(int);
void markHexagon(int);
void markHeptagon(int);
void markOctagon(int);

int validPoligons[9999][8];
int solution;

void printArray(int*array,int size){
	for(int i=0 ; i<size; i++)
		printf("%d ",array[i]);
	printf("\n");
}

void clearArray(int*array,int size){
	for (int i=0 ; i<size ; i++)
		array[i] = 0;
}

int main(){
	
	for (int n = 1; n < 140 ; n++)
		markAllPoligons(n);

	int selection[6] = {0};
	int foundPoligon[9] = {0};


	int poligon = 3;

	for (int i = 1000 ; i < 9999 && !solution ; i++){
		if ( isNgonal(i, poligon) ){
			selection[0] =  i;
			foundPoligon[poligon] = 1;
			exploreSolutions(selection, foundPoligon, 1);
		}
	}

	return 0;
}

int exploreSolutions(int*selection, int*foundPoligon, int choices ){
	if ( solution ) return 0;
	int searchSpace = ((selection[choices-1])%100)*100;

	if ( choices == 6 ){

		if ( isValidLink(selection[5],selection[0]) )
			solutionFound(selection);
	
	}else {

		for (int i = searchSpace ; i < searchSpace+100 ; i++){
			for (int poligon = 3 ; poligon <= 8 ; poligon++){
				if ( !foundPoligon[poligon] && isNgonal(i,poligon) ){
					
					selection[choices] = i;
					foundPoligon[poligon] = 1;

					exploreSolutions(selection, foundPoligon, choices+1);
					
					foundPoligon[poligon] = 0;
					selection[choices] = 0;
				}
			}
		}
	}
	return 0;
}

void solutionFound(int*array){
	for(int i = 0 ; i < 6 ; i++){
		printf("%d ", array[i]);
		solution += array[i];
	}
	printf("\n");
	print(solution);
}

int isNgonal(int number, int poligonality){
	return validPoligons[number][poligonality];
}

int isValidLink(int numberA, int numberB){
	return numberA%100 == numberB/100;
}
void markAllPoligons(int n){
	markTriangle(n);
	markSquare(n);
	markPentagon(n);
	markHexagon(n);
	markHeptagon(n);
	markOctagon(n);
}

void markTriangle(int n){
	int triangle = (int)( n *( (n+1)/2.0 ) );
	if ( 999 < triangle && triangle < 10000)
		validPoligons[triangle][3] = triangle;
}

void markSquare(int n){
	int square = n*n;
	if ( 999 < square && square < 10000 )
		validPoligons[square][4] =  square;
}

void markPentagon(int n){
	int pentagon = (int)( n * ( (3*n-1)/2.0 ) );
	if ( 999 < pentagon && pentagon < 10000 )
		validPoligons[pentagon][5] =  pentagon;
}

void markHexagon(int n){
	int hexagon = n * (2*n-1);
	if ( 999 < hexagon && hexagon < 10000 )
		validPoligons[hexagon][6] =  hexagon;
}

void markHeptagon(int n){
	int heptagon = (int)( n*( (5*n-3)/2.0) );
	if ( 999 < heptagon && heptagon < 10000 )
		validPoligons[heptagon][7] =  heptagon;
}

void markOctagon(int n){
	int octagon = n * ( 3*n-2 );
	if ( 999 < octagon && octagon < 10000 )
		validPoligons[octagon][8] =  octagon;
}