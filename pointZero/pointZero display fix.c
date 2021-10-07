#include<stdio.h>
#include<math.h>

// int main()
// {
//     const int stop = 6; //how many row in my tables and how long is a row
    
//     int n = 1;

//     for(int n = 1; n < stop; + n) //each iteration of this for will create a new row
//     {
//         for(int i = 1; i < stop; ++i) //first table
//         {
//             printf("%d", n++);
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
//         n -= stop - 2; //we start from a different value (-2 because I used strict conditions)
//     }

//     return 0;
// }


int main()
{
    const int startingNumber = 1;
    const int stop = 6; //-1 = how many row in my tables and how long is a row

    for(int n = startingNumber; n < stop; ++n) //each iteration of this for will create a new row
    {
        for(int i = 1; i < stop; ++i) //first table     //last number of a row == firstNumberOfThisRow + stop - 2
        {                                               //first number of the last row == firstNumberOfTheFirstRow + stop - 2
            int numberToPrint = n + i - 1;
            int lenghtiestNumber = 4;  //it need to be preinitialized //any single digit number could have done the trick

            if((int)log10(startingNumber) + 1 > (int)log10(startingNumber + stop - 2 + stop - 2) + 1)  //I should really do a method for this simple calculus
            {
                lenghtiestNumber = startingNumber;
            }
            else
            {
                lenghtiestNumber = startingNumber + stop - 2 + stop - 2;
            }
            
            int numberToPrintLenght = (int)log10(numberToPrint) + 1;
            do
            {
                if(i != 1)
                    printf("-");
                
                ++numberToPrintLenght;
            } while (numberToPrintLenght < (int)log10(lenghtiestNumber) + 1);
            

            printf("%d", numberToPrint);                    //the last number printed will be (stop-1)*2-1
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