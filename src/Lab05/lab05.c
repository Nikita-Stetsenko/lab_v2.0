#include<stdio.h>

int main()
{
    int x, y;

    printf("Enter the first number: ");
    scanf_s("%d", &x);
    printf("Enter the second number: ");
    scanf_s("%d", &y);

    while (x != y) {
        if (x > y) {
            x = x - y;
        }
        else {
            y = y - x;
        }
    }

    printf("NOD = ");
    printf("%d\n", x);

    return 0;
}