#include <stdio.h>

int main()
{
    const int stop = 6; //-1 = how many row in my tables and how long is a row
    //n is const firstNumber in later versions //n = firstNumber since we don't modify const

    for(int n = 1; n < stop; ++n) //each iteration of this for will create a new row
    {
        for(int i = 1; i < stop; ++i) //first table
        {
            printf("%d", n + i - 1); //this looks weird if you don't look at the display
        }
        
        printf("        "); //to separates the two tables

        for(int point = n; point > 1; --point) //place the points
        {
            printf(".");
        }

        for(int zero = 0; zero<stop-n; ++zero) //place the zeros
        {
            printf("0"); 
        }

        printf("\n"); //change row before going back to the initial for
    }

    return 0;
}   //iteration 1, n = 1, n < 6 is t, exec 18 to 35; ++n; n = 2;
    //iteration 2, n = 2, n < 6 is t, exec 18 to 35; ++n; n = 3;
    //iteration 3, n = 