#include<stdio.h>

//Samuel Fauteux 
//9/11/2020
//Debora thingny remake

int main() {
    int firstNote = -1; 
    int secondNote = -1; 
    int thirdNote = -1; 

    printf("What is your first note?\n");
    scanf("%d", firstNote);
    printf("\nWhat is your second note?\n");
    scanf("%d", secondNote);
    printf("\nWhat is your third note?\n");
    scanf("%d", thirdNote);

    float avg = (firstNote + secondNote + thirdNote) / 3

    if(avg < 60){printf("You failled!")}
    else{printf("You might have a future after all...")}

    return 2;
}