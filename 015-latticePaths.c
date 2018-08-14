//Lattice Paths, Euler Project problem 15
/*
Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.

How many such routes are there through a 20×20 grid?
*/

#include <stdio.h>
#define GRID 20 

 
int main(){
	unsigned long long solutions=1;
	for (int i=1; i<=GRID ; i++){
		solutions=solutions*((GRID+i)/i);
		printf("%lld\n",solutions);
	}
	return 0;
}

