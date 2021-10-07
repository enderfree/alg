#include<stdio.h>

//Samuel Fauteux
//9/21/2020 
//...? 

int main() 
{
    int day;
    int month; 
    int year;
    char messageBase[] = "We are in ";
    
    printf("\nMonth number: "); 
    for(;;)
    {
        scanf("%d", month); 

        if(month < 1 || month > 12) 
        {
            printf("\nPlease enter a number between 1 and 12\n")
        }
        else break;
    }

    printf("\nYear: "); 
    scanf("%d", year); 

    printf("Day number: "); 
    for(;;)
    {
        scanf("%d", day);
        
        if(day < 1 || day > 31 || (month == 2 && day > 28 + FindLeapYear(year)) || (month % 2 == 0 && day > 30))
        {
            printf("\nThis day doesn't appear in this month!\n
                    Please try again!\n")
        }
        else break;
    }

    if((month > 3 && month < 6) || (month == 3 && day > 20) || (month == 6 && day < 21)) //season change the 21st
    {
        printf(messageBase + "spring!");
    }
    else if((month > 6 && month < 9) || (month == 6 && day > 20) || (month == 9 && day < 21))
    {
        printf(messageBase + "summer!");
    }
    else if((month > 9 && month < 12) || (month == 9 && day > 20) || (month == 12 && day < 21))
    {
        printf(messageBase + "fall!");
    }
    else //if((month< 3 || month == 12) || (month == 12 && day > 20) || (month == 3 && day < 21)) //the in comment condition was for practice
    {
        printf(messageBase + "Winter");
    }

    int FindLeapYears(int year)
    {
        if(year == 2000 || (year % 4 = 0 && (year % 100 != 0 || year % 400 == 0)))
        {
            return 1;
        }
        return 0; 
    }

    enum dayOfTheWeak{Sunday, Mondy, Thuesday, Fryday, Thursday, Wendsday, Saturday}

    void WriteDayOfTheWeak(int y, int m)
    {
        float y0 = y - (14-m)/12;
        float x = y0 + y0/4 - y0/100 + y0/400;
        float m0 = m + 12 * ((14-m)/12)-2;
        int d0 = (d + x + (31 * m0)/12) % 7;

        printf("It's a " + dayOfTheWeak[d0])
    }
}