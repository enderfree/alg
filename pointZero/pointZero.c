#include<stdio.h>

// int main()
// {
//     const int stop = 6; //how many row in my tables and how long is a row
    
//     int startingNumber = 1;

//     for(int n = 1; n < stop; ++n) //each iteration of this for will create a new row
//     {
//         for(int i = 1; i < stop; ++i) //first table
//         {
//             printf("%d", startingNumber++);
//         }
        
//         printf("        "); //to separates the two tables

//         for(int point = n; point > 1; --point) //place the points
//         {
//             printf(".");
//         }

//         for(int zero = 0; zero < stop - n; ++zero) //place the zeros
//         {
//             printf("0");
//         }

//         printf("\n"); //change row before going back to the initial for
//         startingNumber -= stop - 2; //we start from a different value (-2 because I used strict conditions)
//     }

//     return 0;
// }


int main()
{
    const int stop = 6; //-1 = how many row in my tables and how long is a row

    for(int n = 1; n < stop; ++n) //each iteration of this for will create a new row
    {
        for(int i = 1; i < stop; ++i) //first table
        {
            printf("%d", n + i - 1);
        }
        
        printf("        "); //to separates the two tables

        for(int point = n; point > 1; --point) //place the points
        {
            printf(".");
        }

        for(int zero = 0; zero < stop - n; ++zero) //place the zeros
        {
            printf("0");
        }

        printf("\n"); //change row before going back to the initial for
    }

    return 0;
}