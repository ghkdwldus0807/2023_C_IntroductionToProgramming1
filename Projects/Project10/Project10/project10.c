//2110189 È²Áö¿¬

#include <stdio.h>
#define Tax1 0.15
#define Tax2 0.20
#define Tax3 0.25

#define Break1 300
#define Break2 450

#define Base1 (Tax1 * Break1)
#define Base2 (Base1 + (Tax2 * (Break2 - Break1)))

#define payrate 10

int main(void) {
	double grosspay;
	double netpay;
	double hour;
	double netpay_final;

	printf("Enter the hours worked. \n");
	scanf_s("%lf", &hour);

	if (hour <= 40) {
		grosspay = hour * payrate;
	} else if (hour > 40) {
		grosspay = (hour - 40) * payrate * 1.5 + 40 * payrate;

	}

	if (grosspay <= Break1)
		netpay = Tax1 * grosspay;
	else if (grosspay <= Break2)
		netpay = Base1 + (Tax2 * (grosspay - Break1));
	else
		netpay = Base2 + (Tax3 * (grosspay - Break2));

	netpay_final = grosspay - netpay;

	printf("Your gross pay is $%.1f , and netpay is  $%.1f. \n",grosspay,netpay_final);

	return 0;
}
