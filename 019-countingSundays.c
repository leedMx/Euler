//Counting sundays, Project Euler problem 19
/*
You are given the following information, but you may prefer to do some research for yourself.
    1 Jan 1900 was a Monday.
    Thirty days has September,
    April, June and November.
    All the rest have thirty-one,
    Saving February alone,
    Which has twenty-eight, rain or shine.
    And on leap years, twenty-nine.
A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.

How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?*/

#include <stdio.h>
#define INITIAL_YEAR 1900
#define INITIAL_WEEKDAY 1
#define SUNDAY 0
#define FINAL_YEAR 2000
#define VERBOSE 1

int fillWeekdaysArray();
int fillSundaysArray();
int firstSundays(int,int);
int nextWeekday(int);
int plusNWeekdays(int,int);
int countSundaysTheFirst(int);
int leapYear(int);
char* numToDay(int);
int explain();

int weekdaysArray[FINAL_YEAR-INITIAL_YEAR+1];
int sundaysArray[7];
int leapSundaysArray[7];

	int totalSundays=0;
int main(){

	fillWeekdaysArray();

	if (VERBOSE)explain();

	fillSundaysArray();

	for(int i=1901; i<=2000; i++)
		countSundaysTheFirst(i);
	
	printf("Total 'Sundays 1st' in the XX century: %d\n",totalSundays);
	return 0;
}

int countSundaysTheFirst(int year){
	int day=weekdaysArray[year-INITIAL_YEAR];
	if (leapYear(year)){
		totalSundays+=leapSundaysArray[day];
		return 0;
		}
	totalSundays+=sundaysArray[day];
	return 0;
}

int fillWeekdaysArray(){
	int weekday=INITIAL_WEEKDAY;
	weekdaysArray[0]=weekday;

	for (int i=INITIAL_YEAR+1; i<=FINAL_YEAR; i++){
		if ((i%4==1)&&(i%100!=1)){
			weekday=nextWeekday(weekday);
		}
		weekday=nextWeekday(weekday);
		weekdaysArray[i-INITIAL_YEAR]=weekday;
	}
	return 0;
}

int fillSundaysArray(){
	for (int i=0;i<7;i++)
		sundaysArray[i]=firstSundays(i,0);
	for (int i=0;i<7;i++)
		leapSundaysArray[i]=firstSundays(i,1);
	return 0;
}

int plusNWeekdays(int day,int count){
	while(count){
		day=nextWeekday(day);
		count--;
	}
	return day;
}

int nextWeekday(int weekday){
	weekday++;
	if (weekday>6)
		weekday=0;
	return weekday;
}

int firstSundays(int weekday,int isLeap){
	int months[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int day=weekday;
	int nextMonthDay;
	int	sundays=0;
	
	if (isLeap)months[1]=29;

	if((VERBOSE)&&(isLeap))printf("leaps: ");
	if(VERBOSE)printf("if the year starts on %s: ",numToDay(weekday));

	for (int i=0;i<12;i++){
		if(day==SUNDAY)
			sundays++;		
		nextMonthDay=plusNWeekdays(day,months[i]);
		day=nextMonthDay;
	}
	
	if (VERBOSE)printf("theres %d 'Sunday 1st'\n",sundays);
	return sundays;
}

int leapYear(int year){
	if (!(year%400))
		return 1;
	if ((year%4==0)&&(year%100!=0))
		return 1;
	return 0;
}

char* numToDay(int weekday){
	char* days[7]={"sunday","monday","tuesday","wednesday","thursday","friday","saturday"};
	return days[weekday];
}

int explain(){
	for(int i=0;i<6;i++)
		printf("Jan 1st of 190%d is a %s.\n",i,numToDay(weekdaysArray[i]));
	printf("(It skips a day after a leap year).\n");
	return 0;
}
