//Combinatorics Selections, Euler Project Problem 53
/*
There are exactly ten ways of selecting three from five, 12345:

123, 124, 125, 134, 135, 145, 234, 235, 245, and 345

In combinatorics, we use the notation, 5_C_3 = 10.

In general,
n_C_r = n!/(r!(n−r)!)

,where r ≤ n, n! = n×(n−1)×...×3×2×1, and 0! = 1.

It is not until n = 23, that a value exceeds one-million: 23_C_10 = 1144066.
How many, not necessarily distinct, values of  nCr, for 1 ≤ n ≤ 100, are greater than one-million? */

#include <stdio.h>
#define print(ref) printf(#ref" = %d\n",ref);
#define TARGET 1000000

int countInPascalTriangleRow(int);

int main(){
	int solution = 0;
	
	for (int row = 23; row <= 100 ;	row ++)
		solution += countInPascalTriangleRow(row);

	print(solution)

	return 0;
}

int countInPascalTriangleRow(int row){
	int belowTarget = 1, termsInRow = row+1, c = 1;

	for (int n = row, k = 1 ; k <= row ; k++, n--){
		c *= n;
		c /= k;
		if ( c > TARGET ) break;
		belowTarget++;
	}

	return termsInRow-(2*belowTarget);
}
