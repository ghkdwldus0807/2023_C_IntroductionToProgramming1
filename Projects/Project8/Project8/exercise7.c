//21101989 È²Áö¿¬

#include <stdio.h>

int main(void) {

	double account = 1000000;
	int years = 0; 

	while (account > 0) {
		account -= 100000;
		account = account * 1.08;
		years++;
	}

	printf("It takes %d years", years);


	return 0;
}