#include <stdio.h>

int main()
{
	int num;
	int lsum = 0, rsum = 0;

	printf("Enter a 6-digit number : ");
	scanf_s("%d", &num);
	printf("\n");

	for (int i = 0, num1 = num; i < 6; i++)
	{
		if (i < 3) (lsum += num1 % 10);
		else (rsum += num1 % 10);

		num1 /= 10;
	}

	if (lsum == rsum)
	{
		printf("\n\t\t\t\t TICKET %d IS HAPPY ! ! !\n", num);
	}
	else
	{
		printf("\n\t\t\t\t TICKET %d IS UNHAPPY \n", num);
	}

	return 0;
}
