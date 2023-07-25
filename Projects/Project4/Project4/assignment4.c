//21101989 È²Áö¿¬

#include <stdio.h>
#define gallon_to_liters 3.785
#define mile_to_kilometers 1.609

int main(void) {

	float miles;
	float gallons;
	float mile_gallon;
	float mile_km;
	float gallon_liter;
	float result;

	printf("Enter the number of miles traveled \n");
	scanf_s("%f", &miles);
	printf("Enter the number of gallons of gasoline consumed\n");
	scanf_s("%f", &gallons);

	mile_gallon = miles / gallons;
	mile_km = miles * mile_to_kilometers;
	gallon_liter = gallons * gallon_to_liters;
	result = gallon_liter / 100;

	printf("mile per gallon is %.1f, a liters -per- 100km is %.1f \n", mile_gallon,result);
	

	return 0;

}