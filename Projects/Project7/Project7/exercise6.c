//21101989 È²Áö¿¬

#include <stdio.h>


int main() {

	double nowon = 100;
	double seoultech = 100;
	int years = 0;

	while (nowon >= seoultech) {

		nowon += 10;
		seoultech +=seoultech * 0.05;
		years++;


	}

	printf("It takes %d years \n", years);
	printf("Nowon Bank's investment is %.2f \n", nowon);
	printf("SeoulTech Bank's investment is %.2f \n", seoultech);

	return 0;
}
