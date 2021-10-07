#include <stdio.h>

int main()
{
    for(int i = 5; i > 0; --i)
    {
        for(int n = 6 - i; n > 0 ; --n) //I should assing 5 to a new constant StartingValue
        {
            printf("%d ", n);
        }
        printf("\n");
    }

    return 0;
}