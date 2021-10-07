#include<stdio.h>

int main()
{
    int numberToFactorize; 
    printf("Which integer do you want to factorize? \n"); 
    scanf("%d", numberToFactorize); 
    
    int f = numberToFactorize;
    while(f > 1)
    {
        --f;
        numberToFactorize *= f;
    }

    printf(numberToFactorize);
}