#include<stdio.h>

int main()
{
    printf("Please give us a positive integer. \n");
    int givenInteger;
    scanf("%d", givenInteger); 
    
    if(givenInteger == 0 || givenInteger == 1)
    {
        printf("\n0 and 1 arn't consider as prime number"); 
        break;
    }

    i = 2; //prime number can only be divide by 1 and themselves so I am looking between those value
    while(i < givenInteger)
    {
        if(givenInteger % i == 0)
        {
            printf("\n" + givenInteger + " is a prime number!");
            break;
        }
    }

    printf("\n" + givenInteger + " in not a prime number. ")
}