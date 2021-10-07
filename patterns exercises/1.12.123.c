#include <stdio.h>

int main()
{
    for(int i = 1; i < 6; ++i)
    {
        for(int n = 1; n < i; ++n)
        {
            printf("%d ", n);
        }
        printf("\n");
    }

    return 0;
}