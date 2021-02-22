#include <io.h>
#include <stdio.h>
#include <string.h>
 
int main()
{
	int nbytes = 0;
	int num;
	int lsum = 0, rsum = 0;
	char name[11];
	const char msg[] = "Hello ";

	printf("Enter your name (10 ch) : ");
	gets_s(name, sizeof(name) - 1);

	_write(1, msg, sizeof(msg));
	printf("%s", name);

	puts("\nEnter a 6-digit number : ");
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