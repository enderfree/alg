#include<stdio.h>

int main()
{
    int var; 
    int numberOfOdd = 0;
    int numberOfEven = 0;
    int sumOfOdd = 0;
    int sumOfEven = 0;

    char yesOrNo;
    do{
        printf("Do you want to enter an integer? (Y 0r N)\n"); 
        scanf("%c", &yesOrNo); 

        if(yesOrNo != 'N')
        {
            printf("\n\nPlease enter it here: ");
            scanf("%d", &var); 

            if(var % 2 = 1)
            {
                ++numberOfOdd; 
                sumOfOdd += var;
            }
            else
            {
                ++numberOfEven;
                sumOfEven += var;
            }
        }
    }while(yesOrNo != 'N')

    print("\n\nNumber of odd integers = " + numberOfOdd + 
            "\nNumber of even integers = " + numberOfEven + 
            "\nSumm of those odd numbers = " + sumOfOdd + 
            "\nSumm of those even numbers = " + sumOfEven);
}