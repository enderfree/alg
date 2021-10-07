#include <stdio.h>

int main()
{
    for(int i = 1; i < 6; ++i)
    {
        for(int n = 5; n > 5 - i; --n) //I should assing 5 to a new constant StartingValue
        {
            printf("%d ", n);
        }
        printf("\n");
    }

    return 0;
}