/******************************************************************************************************************
    420AP1AS, F2020
    mmk @ lasallecollege
    Arrays - notes and exercises
    v 1.0

    An array is a data-structure that holds multiple variables of the same type.
    This following is an array that holds some integers values
    _____________________________________________________________________________________
        10  |   54  |   80  |   90  |   30  |  25  |    5    |    3    | 50     |   51   |
    ________|_______|_______|_______|_______|______|_________|_________|________|________|
    
    The array has the following attributes:
        name: like any variable, you need to give the array a name
        size: how many elements do you want to store in the array? 
        data-type: the type of elements you will be storing in the array (char, float, int, string...)

    And like any variable, you need to declare the array, so that space in memory is reserved for it. 
    Use the attributes above to declare the array like so: 

    the D E C L A R A T I O N    ------>>>  data-type array-name [ size ]  <<<-------
                                                int numbers [10]
    
    This declaration reads: numbers is an array of integers and of size 10 (ie. it can hold 10 elements).
    But after the declaration, the array is empty*.  

    ________________________________________________________________________________________
            |       |       |       |       |      |         |        |        |        |
    ________|_______|_______|_______|_______|______|_________|________|________|________|___
    
    In the case of a variable, we do one of the following:
    int a;      // this is a declaration that will later be followed by an assignment
    int a = 1;  // this is a simultaneous declaration and initialization

    We can do the same for the arrays! 

    int numbers[10];    // this is a simple declaration
    int numbers[10] = {10, 54, 80, 90, 30, 25, 5, 3, 50, 51} // and this is a simultaneous declaration and initialization. 
    int numbers[] = {10, 54, 80, 90, 30, 25, 5, 3, 50, 51}   // this is also valid. You don't really need to keep the size between []
                                                             // It is determined by the number of elements between { }

    -------------------->>> Once you declare the size of the array, you CANNOT change it! <<<--------------------------------------
    
    
    the I N D E X 

    The 10 elements of the array are akin to 10 variables.
    In order to access them, you need to know their position in the array. 
    This is known as the "index". If the array size = n, then: 
        The first element is stored at index 0, and
        The last element is stored at index n-1.
    
    ________________________________________________________________________________________
            |       |       |       |       |      |         |        |        |        |
    ________|_______|_______|_______|_______|______|_________|________|________|________|___
        0       1       2       3       4       5       6       7          8        9   <<<----- the indexes

    
    Consider every slot in the array as a variable. Here, there are 10. 
    Typically, we access and manipulate variables with the names we give them.
    You may ask: but what are the names of these variables?? The ones in the array... Well, simply: 
    
    numbers[0]
    numbers[1]
    numbers[2]
    numbers[3]
    numbers[4]
    numbers[5]
    numbers[6]
    numbers[7]
    numbers[8]
    numbers[9]

    You use the array name and follow it by the position you're interested in between square brackets.
    Imagine you're headed home. You live at: 
    123 sunshine street     <==> array name, numbers. But that's not enough. Now, you need the apt. 
    Apt 13                  <==> index. This now tells you which position you are accessing in the array
    
    Anything related to access and assignment that you can do with a single variable, you can do here: 

    num = 1; 
    numbers[0] = 1; 

    num = num + 1; 
    numbers[1] = numbers[1] +1; 

    printf("%d", num);
    printf("%d", numbers[2]);

    scanf("%d", &num);
    scanf("%d", &numbers[3]);
    
    and so on ...

    ITERATING OVER THE ARRAY 

    Remember the for loops and all those patterns..? 

    for (int index=0; index < size; index++){
        
        // do whatever you want with array_name[index]
        // give it a try! 
        // this iterates over index/location 0 all the way to index/location n-1
        // your index serves as an iterator... 
    }

    Remember with loops, we use the iterator as a counter. 
    For example, print "hello world" 5 times. The iterator can run from 0 to 4, 1 to 5, 100, to 104, ... it doesn't matter. 
    All that matters is that the loop runs 5 times.

    But in loops, we have also used the iterator for its value... 
    Recall the example where we iterated from 1500-2700 and printed nums divisble by 5 and 7. 
    In that case, we used the iterator's value : i = 1500, 1505, 1510, 1515, ... 2700.

    We can do the same with arrays! 

    Sometimes the value of the INDEX (0 to n-1) won't matter. See spreadsheet with grades example. 
    In the example of the array numbers above, we have no use for the value of the index. 
    
    On the other hand, say I want to store the height of a 4 years old toddler at every one of his/her birthdays.
    Instead of storing this info in 5 variables, you store it in an array: float height[5];
    And you use the index of the array, to represent the year... See spreadsheet with height example.

    Birth: 51.5cm       -->> height[0] = 51.5
    1st bday: 74cm      -->> height[1] = 74
    2nd bday: 86cm      -->> height[2] = 86
    3rd bday: 95cm      -->> height[3] = 95
    4th bday: 100cm     -->> height[4] = 100
  
    ________________________________________________________
        51.5    |   74    |    86   |   95    |  100     |
    ____________|_________|_________|_________|__________|__
        0       1       2       3       4   

    for (int i=0; i<5; i++){        // looping to take info in and fill the array
        printf("How tall was the child at year %d?", i);
        scanf("%f", &height[i]);
    }

    printf("Thank you! Please verify the following information:\n ");

    for (int i=0; i<5; i++){    // looping to print out the values in the array. same construct as above... just different body!
        printf("At year %d, the child was %fcm tall!\n", i, height[i]);
    } // i is the index and height[i] is the value stored in the array height at that index.
 

*********************************************************************************************************/

/*  
    Exercise 1. 
    A program prompts the user to enter students' grades, which it subsequently stores in an array. 
    The program needs to ask the user how many students are there in class in order to create the array.
    Once this is done, the program will compute and printout the following:
    class average, 
    max grade, and
    min grade

*/

int main()
{
    int classSize = 0; //in case of a failiure to catch the answer
    
    printf("How many student is there in this class? ");
    scanf("%d", &classSize);
    printf("\n");

    int grades[classSize];
    int gradeAvarage = 0;
    int maxGrade = 0;
    int minGrade = 100;

    for(int i = 0; i < classSize; ++i)
    {
        printf("\nStudent %d grade: ", i);
        scanf("%d", &grades[i]);

        gradeAvarage += grades[i];
        
        if(grades[i] > maxGrade)
        {
            maxGrade = grades[i];
        }

        if(grades[i] < minGrade)
        {
            minGrade = grades[i];
        }
    }

    gradeAvarage /= classSize;
    printf("\n\nClass avarage: %d\nMax grade: %d\nMin grade: %d", gradeAvarage, maxGrade, minGrade);

    return 0;
}

/*
    Exercise 2.
    Write a program that reads characters in an array A and copies them into an array B, such that
    the characters in array B are in reverse order. 
    Display the content of both arrays. 
*/

int main()
{
    char A[4] = {'C', 'H', 'A', 'R'};
    char B[4]; //A && B would have the same variable for their size

    for(int i = 3; i >= 0; --i) //3 is my last index (well thechnically I think that index 4 exist but contain an end value)
    {
        B[3-i] = A[i]; 
    }

    printf("A B\n\n");

    for (int i = 0; i < 4; ++i)
    {
        printf("%c %c\n", A[i], B[i]);
    }

    return 0;
    
}

/*
    Exercise 3. 
    Declare and initialize an array num[10] of type int, such that the value at index i is i+1. 
    Then, write code to replace the values in the array with their square. 
    
*/

int main()
{
    int num[10];
    for(int i = 0; i < 10; ++i)
    {
        num[i] = i + 1;
    }
    for(int i = 0; i < 10; ++i)
    {
        num[i] *= num[i];
    }

    return 0;
}

/*
    Exercise 4. 
    Write a program that merges two sorted arrays into one, discarding duplicates. 
    You will need to create a third array that can hold the elements of both arrays.
*/

int main()
{
    int sortedArray1[5] = {0, 1, 2, 3, 4};
    int sortedArray2[5] = {5, 6, 7, 8, 9};

    int combinedSize = sizeof(sortedArray1)/sizeof(int) + sizeof(sortedArray2)/sizeof(int)
    int combinedArrays[combinedSize];

    int combinedArraysIndex = 0;
    for(int i = 0; i < sizeof(sortedArray1)/sizeof(int); ++i)
    {
        bool alreadyThere = 0;
        for(int j = 0; j < combinedArraysIndex; ++j)
        {
            if(combinedArrays[j] == sortedArray1[i]) //lets just hope that this will compare values, not references
            {
                alreadyThere = 1;
                break;
            }
        }

        if(!alreadyThere)
        {
            combinedArrays[combinedArrayIndex] = sortedArray1[i];
        }

        ++combinedArrayIndex;
    }
    for(int i = 0; i < sizeof(sortedArray2)/sizeof(int); ++i)
    {
        bool alreadyThere = 0;
        for(int j = 0; j < combinedArraysIndex; ++j)
        {
            if(combinedArrays[j] == sortedArray2[i]) //we wont learn methods before object programming right? //bool LooksForIfNumberIsAlreadyInArray(int number, int Array[])
            {
                alreadyThere = 1;
                break;
            }
        }

        if(!alreadyThere)
        {
            combinedArrays[combinedArrayIndex] = sortedArray2[i];
        }

        ++combinedArrayIndex;
    }

    return 0;
}

/*
    Exercise 5. 
    Given an array of integers, in which elements are duplicated a number of times, create a parallel array
    frequency, that uses the index value to store the frequency of occurrence of a number in the previous array. 

    E.g.    in the following array there are 2 x 5s, 3 x 8s, 2 x 4s, 1 x 9 and 1 x 7.
    ________________________________________________________________________________________
        5    |   5    |   4    |  7     |   8    |  8    |   8      |    4    |  9      | 
    _________|________|________|________|________|_______|__________|_________|_________|_
        0        1        2        3        4        5       6           7         8 

    The expected output should be an array named frequency. You must determine its size. 
    This is what it should look like.
    ________________________________________________________________________________________
             |   2    |   2    |   1    |        |       |          |         |         | 
    _________|________|________|________|________|_______|__________|_________|_________|_
        0        1         2       3       4       5       6       7          8        9    
*/

int main()
{
    int array[9] = {5, 5, 4, 7, 8, 8, 8, 4, 9};
    int frequancy[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; //the size of this array must not be == to the size of the one it will scan but it's highest value + 1

    printf("The array: [");

    for(int i = 0; i < 9; ++i)
    {
        printf("%d", array[i]);
        if(i != 8) //8 will be the last value of i that will paas by this line
        {
            printf(", ");
        }
        else
        {
            printf("]\n");
        }
        
        ++frequancy[array[i]];
    }

    printf("contains: \n");

    for(int i = 0; i < 10; ++i)
    {
        printf("%d %d\n", frequancy[i], i);
    }

    return 0;
}

/*
    Exercises 32-36, 38, 42, 54, 58 @ https://www.w3resource.com/c-programming-exercises/array/index.php
*/