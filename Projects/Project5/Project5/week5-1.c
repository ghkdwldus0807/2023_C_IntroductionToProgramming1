//21101989 È²Áö¿¬

#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 6031)

int main(void)
{
	int day;
	int week;
	int remainder;
	while(1){
	
		printf("Enter the number of days \n");
		scanf_s("%d", &day);
		if (day <= 0) {
			break;
		}
		else {
			week = day / 7;
			remainder = day % 7; 
			printf("'%d' days to '%d weeks, %d days \n", day, week, remainder);
		}

	}
	
	return 0;
	

}