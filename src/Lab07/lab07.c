#include <stdio.h>
#include <stdarg.h>

unsigned int NumOfValid(int quan, ...);

int main()
{
    unsigned int quantity_of_numbers = 20;
    unsigned int res = NumOfValid(quantity_of_numbers, 594, 55, 3, 55, 639, 1, 3, 4, 2548, 1234, 525, 783, 375, 54, 852, 2589, 542, 468, 156, 279);
    printf("Number: %d\n", res);

    return 0;
}

unsigned int NumOfValid(int quan, ...)
{
    quan--;

    unsigned int num = 0;

    va_list marker;
    va_start(marker, quan);

    for (int i = 0, tmp_1 = va_arg(marker, int), tmp_2; i < quan; i++)
    {
        if (tmp_1 < (tmp_2 = va_arg(marker, int)))
            num++;
        tmp_1 = tmp_2;
    }

    va_end(marker);

    return num;
}