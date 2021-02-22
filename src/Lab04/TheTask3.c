#include<stdio.h>

int main()
{
	int m = 8;
	int k = 15;
	int n = 4;

	int temp;

	if (k > n) {
		temp = k;
		k = n;
		n = temp;
	}

	if (k > m) {
		temp = k;
		k = m;
		m = temp;
	}

	if (m > n) {
		temp = m;
		m = n;
		n = temp;
	}

	printf_s("%i < %i < %i", k, m, n);

	return 0;
}