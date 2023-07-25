//21101989 È²Áö¿¬

#include <stdio.h>

int main(void) {

	int num;
	int i = 1;
	int sum = 0; 

	printf("Enter the number N(positive Integer) \n");
	scanf_s("%d",&num);

	while (i <= num) {
		sum += i * i * i;
		i++;
	}
	printf("Result is %d", sum);
	return 0;
}