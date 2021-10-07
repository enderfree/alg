#include <stdio.h>

int main()
{
    for(int i = 1; i < 6; ++i)
    {
        for(int n = 0; n < i; ++n)
        {
            printf("%d ", i + n);
        }
        printf("\n");
    }

    return 0;
}