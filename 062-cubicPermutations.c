//Cubic Permutations
/*
The cube, 41063625 (345^3), can be permuted to produce two other cubes: 56623104 (384^3) and 66430125 (405^3). In fact, 41063625 is the smallest cube which has exactly three permutations of its digits which are also cube.

Find the smallest cube for which exactly five permutations of its digits are cube. */

#include <stdio.h>
#include <stdlib.h>
#define print(ref) printf(#ref" = %d\n",ref);
#define printl(ref) printf(#ref" = %ld\n",ref);
#define HASH_MODULE 10007

typedef struct {
	long data;
	int count;
	long firstCube;
	int cubeBase;
}hashedNode;

long digitsSignature(long);
void increaseCount(long);
void addToSet(long,long,int);
int setContains(long);
int hashCode(long);

hashedNode*hashSet[HASH_MODULE];

long solution;
int solutionBase;

int main(){

	hashedNode emptyNode = {0} ;
	for (int i = 0 ; i < HASH_MODULE ; i++)
		hashSet[i] = &emptyNode;
	
	long signature = 0;
	long cube = 0;
	for (long base = 1 ; !solution ; base++) {
		cube = base*base*base;
		signature = digitsSignature(cube);
		int included = setContains(signature);
		if ( included ){
			increaseCount(signature);
		}else{
			addToSet(signature,cube,base);
		}
	}

	printl(solution);
	print(solutionBase);
	return 0;
}

long digitsSignature(long number){
	int digitsArray[10] = {0};
	while (number){
		digitsArray[number%10]++;
		number /= 10;
	}
	
	long signature = 0;
	for (int i = 0 ; i < 10 ; i++){
		signature *= 10;
		signature += digitsArray[i];
	}
	return signature;
}

void addToSet(long value,long cube,int base){
	int bucket = hashCode(value);
	hashedNode *node = malloc(sizeof(hashedNode));
	//assert( node != null );

	node->data = value;
	node->count = 1;
	node->firstCube = cube;
	node->cubeBase = base;
	hashSet[bucket] = node;
}

int setContains(long value){
	int bucket = hashCode(value);
	if (hashSet[bucket]->data == value) return 1;
	return 0;	
}

void increaseCount(long value){
	int bucket = hashCode(value);
	hashSet[bucket]->count++;
	
	if (hashSet[bucket]->count == 5){
		solution = hashSet[bucket]->firstCube;
		solutionBase = hashSet[bucket]->cubeBase;
	}
}

int hashCode(long value){
	return value%HASH_MODULE;
}
