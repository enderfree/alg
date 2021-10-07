#include<stdio.h>

int main() //the pow function already serve that purpose 
{
    int base; 
    int exponant; 

    printf("Please, give us a base: ");
    scanf("%d", base); 
    printf("\nPlease, give us the exponant: ");
    scanf("%d", exponant); 

    int i = 1;
    while (i < exponant)
    {
        base *= base;
        ++i;
    }
    
    printf(base);
}