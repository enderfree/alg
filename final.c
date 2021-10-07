#include <stdio.h>

int main()
{
    int n;
    printf("How far should we print? (int): ");
    scanf("%d", &n);
    printf("\n");

    int pattern[n][n];

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < i + 1; ++j)
        {
            pattern[i][j] = i + 1;
            printf("%d", pattern[i][j]);
        }

        printf("\n");
    }
}