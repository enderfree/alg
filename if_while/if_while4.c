#include<stdio.h>

int maint()
{
    const int startingMultiplicator = 1; 
    const int endingMultiplicator = 12; 
    
    int chosenValue; //the value for what we will print the multiplication table

    printf("Which interger do you whant to multiply? "); 
    scanf("%d", chosenValue); 

    printf("\n
            \n
            Multiplication table of " + chosenValue + " from " + startingMultiplicator + " to " + endingMultiplicator); 
    
    int i = startingMultiplicator;
    while (i <= endingMultiplicator)
    {
        printf("\n" + 
                i + " X " + chosenValue + " = " + i*chosenValue); 
        ++i;
    }
}