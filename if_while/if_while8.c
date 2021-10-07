#include<stdio.h>
#include <stdlib.h>

int main()
{
    int hiddenNumber = rand() % 8 + 1; //rand() generate a random number between 0 and 1 so % the number that we want will give a nmber between 0 and itself
    int guess = 0; 
    int numberOfTries = 0;

    printf("Guess which number I am thinking of~ (between 1 and 9) \n");

    while (guess != hiddenNumber)
    {
        ++numberOfTries;
        if(numberOfTries != 1;)
        {
            printf("\nNo, that's not it~\n");
        }
        scanf("%d", &guess);
    }

    printf("\nAww, you got it, it took you " + numberOfTries + "tries~");
}