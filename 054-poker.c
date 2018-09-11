//Poker, Project Euler Problem 54
/*
In the card game poker, a hand consists of five cards and are ranked, from lowest to highest, in the following way:

High Card: Highest value card.
One Pair: Two cards of the same value.
Two Pairs: Two different pairs.
Three of a Kind: Three cards of the same value.
Straight: All cards are consecutive values.
Flush: All cards of the same suit.
Full House: Three of a kind and a pair.
Four of a Kind: Four cards of the same value.
Straight Flush: All cards are consecutive values of same suit.
Royal Flush: Ten, Jack, Queen, King, Ace, in same suit.

The cards are valued in the order:
2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace.

If two players have the same ranked hands then the rank made up of the highest value wins; for example, a pair of eights beats a pair of fives (see example 1 below). But if two ranks tie, for example, both players have a pair of queens, then highest cards in each hand are compared (see example 4 below); if the highest cards tie then the next highest cards are compared, and so on.

Consider the following five hands dealt to two players:
Hand	Player 1 	Player 2 		Winner
1	5H 5C 6S 7S KD	2C 3S 8S 8D TD	Player 2
2 	5D 8C 9S JS AC	2C 5C 7D 8S QH	Player 1
3	2D 9C AS AH AC	3D 6D 7D TD QD	Player 2
4 	4D 6S 9H QH QC	3D 6D 7H QD QS	Player 1
5	2H 2D 4C 4D 4S	3C 3D 3S 9S 9D	Player 1

The file, poker.txt, contains one-thousand random hands dealt to two players. Each line of the file contains ten cards (separated by a single space): the first five are Player 1's cards and the last five are Player 2's cards. You can assume that all hands are valid (no invalid characters or repeated cards), each player's hand is in no specific order, and in each hand there is a clear winner.

How many hands does Player 1 win? */

#include <stdio.h>
#define print(ref) printf(#ref" = %d\n",ref);
#define prints(ref) printf(#ref" = %s\n",ref);

#define CLUBS 15
#define DIAMONDS 16
#define HEARTS 17
#define SPADES 18
#define HAND_VALUE 19
#define TIE_BREAKER 20
#define HAND_SIZE 21

#define TWO_PAIRS 3

int valueHand(int*);
int highestCard(int*,int);
int hasPair(int*,int);
int hasThree(int*);
int hasStraight(int*,int);
int hasFlush(int*);
int hasFour(int*);

int playerOneWins(int*,int*);

int readHand(int*,FILE*);
int readCard(char*,FILE*);
int countNumber(char*,int*);
int countSuite(char*,int*);
int clearHand(int*);
//int printHand(int*);


int main(){
	FILE *data = fopen("054-poker.txt","r");
	
	int solution = 0;
	int handA[HAND_SIZE] = {0};
	int handB[HAND_SIZE] = {0};


	while( readHand(handA,data) != EOF ){
		readHand(handB,data);

//		printHand(handA);
//		printHand(handB);

		valueHand(handA);
		valueHand(handB);

//		print(playerOneWins(handA,handB));
		solution += playerOneWins(handA,handB);

		clearHand(handA);
		clearHand(handB);
	}
	
	print(solution);

	return 0;
}

int valueHand(int* hand){
	int high = highestCard(hand,14);
	int flush = hasFlush(hand);
	int straight = hasStraight(hand,high);
	int four = hasFour(hand);
	int three = hasThree(hand);
	int pair = hasPair(hand,14);
	
	int royalFlush = (straight == 14) && flush;
	int straightFlush = flush && straight;
	int full = three && pair;
	int twoPairs = pair && hasPair(hand,pair-1);

	if ( royalFlush ){
		hand[HAND_VALUE] = 10;
		return 0;
	}

	if ( straightFlush ){
		hand[HAND_VALUE] = 9;
		hand[TIE_BREAKER] = straight;
		return 0;
	}

	if ( four ){
		hand[HAND_VALUE] = 8;
		hand[TIE_BREAKER] = four ; 
		return 0;
	}


	if ( full ){
		hand[HAND_VALUE] = 7;
		hand[TIE_BREAKER] = three ; 
		return 0;
	}

	if ( flush ){
		hand[HAND_VALUE] = 6;
		hand[TIE_BREAKER] = high ; 
		return 0;
	}

	if ( straight ){
		hand[HAND_VALUE] = 5;
		hand[TIE_BREAKER] = straight ; 
		return 0;
	}

	if ( three ){
		hand[HAND_VALUE] = 4;
		hand[TIE_BREAKER] = three ; 
		return 0;
	}

	if ( twoPairs ){
		hand[HAND_VALUE] = TWO_PAIRS;
		hand[TIE_BREAKER] = pair ; 
		return 0;
	}

	if ( pair ){
		hand[HAND_VALUE] = 2;
		hand[TIE_BREAKER] = pair ;
		return 0;
	}

	hand[HAND_VALUE] = 1;
	hand[TIE_BREAKER] = high;
	return 0;
}

int highestCard(int* hand, int boundary){
	int card = boundary;
	while ( hand[card] == 0 ){
		card--;
	}
	return card;
}

int hasPair(int* hand, int boundary){
	for (int prospect = boundary; prospect > 1 ; prospect--){
		if ( hand[prospect] == 2 ) return prospect;
	}
	return 0;
}

int hasThree(int* hand){
	for (int prospect = 14; prospect > 0 ; prospect-- ){
		if ( hand[prospect] == 3 ) return prospect;
	}
	return 0;
}

int hasStraight(int* hand, int high){
	if ( high == 14 &&
	     hand[2] == 1 &&
	     hand[3] == 1 &&
	     hand[4] == 1 &&
	     hand[5] == 1 ) return 5;

	if ( hand[high-0] == 1 &&
	     hand[high-1] == 1 &&
	     hand[high-2] == 1 &&
	     hand[high-3] == 1 &&
	     hand[high-4] == 1 ) return high;
	return 0;
}

int hasFlush(int* hand){
	if( hand[CLUBS] 	== 5 ||
	    hand[DIAMONDS]	== 5 ||
		hand[HEARTS] 	== 5 ||
		hand[SPADES] 	== 5 ) return 1;
	return 0;
}

int hasFour(int* hand){
	for (int prospect = 14; prospect > 0 ; prospect-- ){
			if ( hand[prospect] == 4 ) return prospect;
	}
	return 0;
}

int playerOneWins(int* handA,int* handB){
	int hand1 = handA[HAND_VALUE];
	int hand2 = handB[HAND_VALUE]; 
	int tie1 = handA[TIE_BREAKER];
	int tie2 = handB[TIE_BREAKER];
		
	if ( hand1 != hand2 ){
		return hand1 > hand2;
	}
	
	if ( hand1 == TWO_PAIRS && tie1 == tie2){
		tie1 = hasPair(handA, tie1-1);
		tie2 = hasPair(handB, tie2-1);
	}

	while ( tie1 == tie2){
		tie1 = highestCard(handA,tie1-1);
		tie2 = highestCard(handB,tie2-1);
	}

	return tie1 > tie2;
}

int readHand (int* hand,FILE *data){
	char card[2] = "";
	int cards = 0;
	while( cards < 5){
		if(readCard(card, data) == EOF){
			return EOF;
		}else{
			countNumber(card,hand);
			countSuite(card,hand);
			cards++;
		}
	}
//	printf("\n");
	return 0;
}

int readCard(char* card, FILE *data){
	int written = 0;
	char character;
	while ( written < 2 ){
		character = getc(data);
		if( character == EOF ) return EOF;

		while ( character == '\n' || character == 32 ){
			character = getc(data);
		}
		card[written++] = character;
	}
//	printf("%c",card[0]);
//	printf("%c",card[1]);
//	printf(" ");
	return 0;
}

int countNumber(char* card,int* hand){
	int numberValue = card[0] - '0';
	if ( card[0] == 'T') hand[10] +=1;
	if ( card[0] == 'J') hand[11] +=1;
	if ( card[0] == 'Q') hand[12] +=1;
	if ( card[0] == 'K') hand[13] +=1;
	if ( card[0] == 'A'){
		hand[14] += 1;
		hand[1] += 1;
	}
	if ( numberValue > 0 && numberValue < 10 ){
		hand[numberValue] += 1;
	}
	return 0;
}

int countSuite(char* card,int* hand){
	int suitValue = 0;
	if ( card[1] == 'C') suitValue = CLUBS;
	if ( card[1] == 'D') suitValue = DIAMONDS;
	if ( card[1] == 'H') suitValue = HEARTS;
	if ( card[1] == 'S') suitValue = SPADES;
	hand[suitValue] ++;
	return 0;
}

int clearHand(int* hand){
	for (int i = 0; i < HAND_SIZE ; i++){
		hand[i] = 0;
	}
	return 0;
}

/*
int printHand(int*hand){
	for (int i = 1; i < HAND_SIZE ; i++){
		printf("%d ",hand[i]);
	}
	printf("\n");
	return 0;
}
*/
