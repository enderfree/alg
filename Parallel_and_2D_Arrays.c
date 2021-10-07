/******************************************************************************************************************
    420AP1AS, F2020
    mmk @ lasallecollege
    PARALLEL ARRAYS, Leveraging the INDEXES, and 2-Dimensional ARRAYS  - notes and exercises
    v 1.0

    PARALLEL ARRAYS - INTRO

    Parallel arrays are 2 or more arrays of the same size that allow us to store related information
    across the arrays. The catch is to store related information across the same index. 

    Let's assume we want to store student grades. 

    Abrar
    Barbara
    Bilet
    David
    Darryl
    --------------
    Diego M.
    Diego S.
    Dinh
    Hanen
    Massimo
    Sarah
    Yucheng
    Yuji
    Yuri
    Yushuo

    Arrays names and grades will store names of students and their respective grades. 
    I.e., names[i] will store a student's name, and grades[i] will store this particular's student's grade. 

    Darryl's name is stored in names[4] and his grade will be stored in the parallel array grades, 
    at the same index, 4, grades[4]. 

    names
    ________________________________________________________________
        Ab|Barb | Bil | Dav  | Darl | Diego M |Diego S  ...|  Sarah|          
    ______|_____|_____|______|______|_________|____________|________
        0    1     2      3     4       5                       n-1

    grades
    ___________________________________________________________________
        87  |76    |65    | 95    | 85    |   90 |  ......    |89         
    ________|______|______|_______|_______|______|____________|____
        0      1      2        3      4      5                   n-1

    
    SIN
    ___________________________________________________________________
        870 |760   |651   | 950   | 852   |      |  ......    |891         
    ________|______|______|_______|_______|______|____________|____
        0      1      2        3      4                         n-1


    In order to find Sarah's grade, we need to find where Sarah and her actual grade live (index)
    So we iterate over names looking for Sarah, and once we've found her, we retrieve her grade 
    from grades using the same index. 

    //finding Sarah's grade
    for (int i=0; i<n; i++){
        if(strcmp(names[i],"Sarah")){  // this compares strings names[i] and Sarah, returns 1 if equal, 0 otherwise
            printf("Sarah's grade is %d", grades[i]);
        }
    }

    // another question could be: retrieve the students whose sin no. starts with 8
    // now, you iterate through SIN checking each if sin[i] starts with 8
    // if the answer is yes, retrieve the names of the students from array names using those indexes

    
    PARALLEL ARRAYS FOR FREQUENCY COUNTS 

    Sometimes, we are intersted in counting frequency.
    What is the frequency of letters that appear in the following words? 
    occurrence, def.: the presence of the letter
    frequency of occurrence, def.: how many times is it present? 

    An example to count frequency of letters. 
    Use an array to store the alphabet

    alphabet
    _______________________________________________     which character is held at index 9
        A    | B  | C | D  |E  | F |  G | H |  I| Z |   char x = alphabet[9] 
    _________|____|___|____|___|___|____|___|___|___|   return x 
        0       1   2   3    4   5   6    7   8 ..25       

    Say we are looking to store the frequency of the letters in the name Diego
    
        
    letter: freq                
    D: 1            printf("%c is the %d letter in the alphabet and occurs %d time(s)", alphabet[8], i+1, frequencia[8])
    I: 1            --->>     I is the 9th letter of the alphabet and occurs 1 time(s)
    E: 1            
    G: 1            printf("%c is the %d letter in the alphabet and occurs %d time(s)", alphabet[9], i, frequencia[9])
    O: 1            -->> but if I choose to start my frequency array at index 1... then ^^^
    
    frequencia de los letras (of letters in Diego's name)
    _______________________________________________ 
             |    |   |  1 | 1 |   |    | 1 |   |  1|     <<<--- store the frequency
    _________|____|___|____|___|___|____|___|___|___|
        0       1   2   3    4            ...     9       <<<--- use the index to represent the letter


    Another example
    pneumoultramicroscopcilicovulcanoconiotico
    supercalifragilisticexpialidocious    

    
    S:3     A:3     T:1
    U:2     L:3     X:1
    P:2     O:2     D:1
    E:2     I:7   
    R:2     F:1
    C:3     G:1

    alphabet
    ____________________________________________ 
        A    | B  | C | D  |E  | F |  G | H | Z |
    _________|____|___|____|___|___|____|___|___|
        0       1   2   3    4            ... 25       

    frequency
    ________________________________________________________________________
        |   |        |        |        |      |         |        |         |  <<<--- fill in freq here
    ____|___|________|________|________|______|_________|________|_________|
      0   1     2       3       4          5                        25        <<<--- index here


    LEVERAGING THE INDEX AS VALUE/INFORMATION (ALPHABET LETTER FREQUENCY)

    Sometimes, we can skip the parallell array step and leverage the index directly. 
    
    -   A   B   C   D   E   F   G   H   I   J   K   L   M   N   O   P   Q   R   S   T   U   V   W   X   Y   Z
    0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26

    This is an example of using an iterator for its value, not just for looping.
    no: 1500- 2700 
    output: no that were divisible by 5 and 7
    for (int i=1500; i<=2700; i=i+5)
        if i%7 ==0
            printf("%d", i);

    M I S S I S S I P P I 

    M: 1    count_m
    I: 4    count_i
    S: 4    count_s
    P: 2    count_p
    ________________________________________________________________________________________
             |        |    4   |        |        |   1   |      2   |    4    |         | 
    _________|________|________|________|________|_______|__________|_________|_________|___
        0       1....      9        .....           13 ....   16  ...   19....      26     
                A....      I        .....           M  ....   P   ...   S ....      Z  


    LEVERAGING THE INDEX (GRADE DISTRIBUTION)
    Here's another example of index leveraging

    ________________________________________________________________________________________
        75   |   55   |   84   |  78    |   88   |  83   |   98     |    94   |  99     |  grades
    _________|________|________|________|________|_______|__________|_________|_________|_
        0        1        2        3        4        5       6           7         8 

    how many students have < 60         x1
                            60-69       0
                            70-79       x2
                            80-89       x3
                            90-100      x3
    ___________________________________________________________________________________________
        1    |        |        |        |        |       |          |    2    |    3    |  3|   distribution
    _________|________|________|________|________|_______|__________|_________|_________|___|__
        0        1        2        3        4        5       6           7         8      9     <<< --- Range of grades

    Create an array of size 10 and store in index i the number of grades that appear in range i0-i9. 
    Or store in 0 the number of grades that are less than 60, signaling failing.

    // switch example with range (only on ints and char)
    // iterating over array grades
    // for every grade = grades[i]
    switch(grade){
        case  0 ... 59: distribution[0]++; break; 
        case 60 ... 69: distribution[6]++; break;
        case 70 ... 79: distribution[7]++; break;
        case 80 ... 89: distribution[8]++; break;
        case 90 ... 100: distribution[9]++; break;
        default: printf("Invalid grade entry!\n");     
    }

    LEVERAGING THE INDEX (DECK OF CARDS)
    
    Parallel arrays & 2-D arrays

    Let's play Poker! This is a 52-cards deck.
              _______________________________________________________________
    Hearts    |  ACE 2   3   4   5   6   7   8   9   10  Jack   Queen   King |  
    Diamond   |  ACE 2   3   4   5   6   7   8   9   10  Jack   Queen   King |  
    Clubs     |  ACE 2   3   4   5   6   7   8   9   10  Jack   Queen   King |  
    Spade     |  ACE 2   3   4   5   6   7   8   9   10  Jack   Queen   King |  
              |______________________________________________________________|


    How do I store a hand of 5 cards? 
        
    2 of Hearts 
    Ace of Spades  
    7 of Clubs     
    King of Hearts  
    7 of Diamonds  

    Well, I could create an array and use its value to match the cards, such that:
    Index - Card
    0 - Joker
    1 - ace
    2 - 2 
    .
    .
    .
    10 - 10
    11 - Jack
    12 - Queen
    13 - King       

    You have different options:
    Use the 0 for the joke (although we dont have jokers in poker, but in case we play a diff game)
    Use the 0 for the king, followed by 1 for the ace, and finish at 12 for the queen
    Use the 0 for the 1, and do a little adjustment when you are searching/printing.... not my fav.

    You really want to keep your code as simple and adjustable. 
    So, let's store the ace at index 1, the king at index 13, and the rest in between. 
    
    my hand
    ___________________________________________________________________________________________________
            |    1   |    1   |        |        |       |      |  2 |     |      |    |   |      |   1  | 
    ________|________|________|________|________|_______|______|____|_____|______|____|___|______|______|
        0        1        2        3        4        5      6    7     8     9     10   11   12    13 <<<--- index represents cards

    Ok! now, I have my hand stored, but I have no idea which families these numbers/images belong to. 

    This is where parallel arrays can come in handy. 
    I can create one array for every suit. And in that array, I can store the information. 

    ___________________________________________________________________________________________________
            |        |        |        |        |       |      |  1 |     |      |    |   |      |     | diamond
    ________|________|________|________|________|_______|______|____|_____|______|____|___|______|_____|
        0        1        2        3        4        5      6    7     8     9     10   11   12    13 <<<--- index represents cards

    ___________________________________________________________________________________________________
            |    1   |        |        |        |       |      |    |     |      |    |   |      |      | spade
    ________|________|________|________|________|_______|______|____|_____|______|____|___|______|______|
        0        1        2        3        4        5      6    7     8     9     10   11   12    13 <<<--- index represents cards

    ___________________________________________________________________________________________________
            |        |        |        |        |       |      | 1  |     |      |    |   |      |     | clubs
    ________|________|________|________|________|_______|______|____|_____|______|____|___|______|_____|
        0        1        2        3        4        5      6    7     8     9     10   11   12    13 <<<--- index represents cards

    ___________________________________________________________________________________________________
            |        |    1   |        |        |       |      |    |     |      |    |   |      |   1  | hearts
    ________|________|________|________|________|_______|______|____|_____|______|____|___|______|______|
        0        1        2        3        4        5      6    7     8     9     10   11   12    13 <<<--- index represents cards

     
    If you are comfortable handling one data structure (courtesy of S. Fauteux) you could use one array!! 
    
    ______________________________________________________________________ 
        1 2 | 3   13| 1 2 3 | 12 13  | 1 2 3  | 12 13 | 1 2  |   12 13|    mydeck (52 cards)
    ________|_______|_______|________|________|_______|______|________|__  size = 52
        0  ... 12      13  ...  25      26 ....   38     39 ...... 51  <<<<---- suits are stored sequentially
                                                                        Hearts   index/13 = 0, for 0<=i<=12        
                                                                        Diamonds index/13 = 1, for 13<=i<=25
                                                                        Clubs    index/13 = 2, for 26<=i<=38
                                                                        Spade    index/13 = 3, for 39<=i<=51
    
    Here, you use the index to indicate the suit. And you store the value of the card directly in the array. 

    If you store the cards in order, then:

    2 of Hearts <<<-- index 1                       
    Ace of Spades <<<--- index 39                       
    7 of Clubs    <<<--- index 32                       
    King of Hearts <<<--- index 12                      
    7 of Diamonds <<<---- index 19                          
    
    Now, to store your hand, you can use one array. 
    In *this* array, the index is not being used for its value. It's simply there to hold 5 element (cards).
    

    ____________________________________________        
        1   |   39  |   32  |  12    |  19    |  my hand
    ________|_______|_______|________|________|_    <<<---- find the index of that card and store it here
        0       1       2       3        4

    
    The values in the array are the indexes of array mydeck! 
    
    for (int i=0; i<5; i++){ 
        mydeck[i] <<--- the value of the card is stored at index i in array mydeck
        myhand[i]/3 <<<--- the suit can be obtained by dividing myhand[i] (which is the index in my deck) by 13
        switch(myhand[i]/13){ <<<--- and switching on the result!
            case 0: hearts; break; 
            case 1: diamonds; break;
            case 2: clubs; break;
            case 3: spade; break;
            default: something's off; 
        }
    }

    
    2-D arrays
    
    Store information in a tabulated format! Everything that we've seen for arrays applies with one added [].
    We still need the size (n) and we still start with index 0 and go to index n-1
    
    Simple array decalaration:  type + name + [size];    (size: number of elements in the array)
    
    2-D  array declaration:     type + name + [rows][cols]; <<<--- always rows first, then columns.  
                                                                   
                                int my_hand[4][14] <<<---- YES! I have 4 rows and 14 cols.
                
                                int my_hand[14][4] <<<---- YES! But now I have 14 rows and 4 columns. 

    I can also initialize the values in the array like so: 
    
    2D array declaration & Initialization: 

    int numbers[2][2] = {{1,2}, {3,4}}; <<<--- notice the nested {}, these represent the values in rows 0, 1, 2, ...
    int numbers[2][2] = {1, 2, 3, 4};   <<<--- or I can do without the nested {}, and the 2D array will fill up one row at a time. 
    
    Without specifying the size: 

    int numbers[][] = {1, 2, 3, 4};     <<<--- I can have the same initialization without specifying the size. 
    int numbers[][] = {{1,2}, {3,4}};   

         _______
        | 1 | 2 |
        |___|___|
        | 3 | 4 |
        |___|___|

    
    Now, coming back to the poker example. 
    I can grab all the parallel arrays and put them in one 2D-array:
    - the row will represent the suit, and 
    - the columns will represent the cards
    
    Much like 
    
    my_hand

          __0____1_____2___3____4____5_____6______7_____8_____9____10____11____12_____13___
        0|__0__|____|_____|___|____|_____|_____|__1__|_____|_____|_____|____|______|_______ (diamonds)
        1|__0__|____|__1__|___|____|_____|_____|_____|_____|_____|_____|____|______|____1__ (hearts)
        2|__0__|_1__|_____|___|____|_____|_____|_____|_____|_____|_____|____|______|_______ (spades)
        3|__0__|____|_____|___|____|_____|_____|__1__|_____|_____|_____|____|______|_______ (clubs)

    

    for (int i=0; i<=3; i++)
        for (int j=0; j<=13; j++)
            printf("%d", my_hand[i][j])
            if (my_hand[i][j] == 1)
                printf("a %d of ", j)
                switch(i){
                    case 0: printf("diamonds"); break;
                    case 1: printf("hearts");   break;
                    case 2: printf("spades");   break;
                    case 3: printf("clubs");    break;
                    default: printf("something's off!");
                }

    Say, for some unconventional reason, you happened to be iterating over the columns, then the rows, 
    when you need to access the slot, you still need to access in a [row][column] order:

    for (int j=0; j<=13; j++)       <<<--- notice iterating over columns
        for (int i=0; i<=3; i++)    <<<--- notice iterating over the rows
            my_hand[i][j]           <<<--- notice access [row][columns]

    
    In the above 2D-array, we had the following representation: 

    // row: 0 for Diamonds
    // row: 1 for Hearts
    // row: 2 for Spades
    // row: 3 for Clubs

    for access or assignment:    my_hand[row-index][col-index]

    2 of Hearts     if this was a single array: hearts[2]=1, in a 4x14 array: my_hand[1][2]=1;
    Ace of Spades   my_hand[2][1]=1
    7 of Clubs      my_hand[3][7]=1
    King of Hearts  my_hand[1][13]=1
    7 of Diamonds   my_hand[0][7]=1

    Queen of Spade      my_hands[2][12]=1
    King of Diamonds    my_hands[0][13]=1
    Ace of Clubs        my_hand[3][1]=1
    5 of Hearts         my_hand[1][5]=1
    4 of Clubs          my_hand[3][4]=1

    int x = my_hand[i][j] 

    If I return the 5 of Hearts to the deck, 
        my_hand[1][5]=0
    
    What if my I had a double deck? 
        my_hand[1][5]--; or:
        my_hand[1][5]= my_hand[1][5]-1; 


    for (int j=0; j<=13; j++)
        for (int i=0; i<=3; i++)
            my_hand[i][j]


    Get rid of the 2 of Hearts
    my_hand[2][1]--;    // double deck
    my_hand[2][1]=0;    // single deck

    for(int i=0; i<4; i++)
    for(int row=0; row<4; row++)
    for(int r=0; r<4; r++)
    
    for(int i=0; i<4; i++)  // iterates over the row
        for (int j=0; j<=13; j++)   // iterates over the col
        //for (int j=1; j<=13; j++) // start at j=1 bc. this col isn't holding anything
            if(my_hand[i][j]>0)
            //if(my_hand[i][j]>=1)
            //if(my_hand[i][j]==1) // only for one deck!
                //printf("%d", my_hand[i][j]) // will print everything
                printf("%d of %d", j, i);

*********************************************************************************************************/


/*
Exercise 1
Prompt the user for two integers m and n, and return an nxm grid where the value in the (i,j) position 
is computed as follows: i+mj. 
Below is an example of a 5x6 grid

0   5   10  15  20  25
1   6   11  16  21  26
2   7   12  17  22  27
3   8   13  18  23  28
4   9   14  15  24  29

*/

int m;
int n;

printf("Please give us an int: ");
scanf("%d", &m);
printf("\nPlease give us another int: ");
scanf("%d", &n);

int nxm[5][6];
for(int i = 0; i < 5; ++i)
{
    for(int j = 0; j < 6; ++i)
    {
        nxm[i][j] = i+m*j;
    }
}

/*
Exercise 2
Prompt the user to enter a number n. The examples below hold for n=6. 
a/ Use a 2D array to print the following pattern up to line n 

1
2 2
3 3 3
4 4 4 4 
5 5 5 5 5
6 6 6 6 6 6 

*/

int n;
printf("How far should we print? (int): ");
scanf("%d", &n);
printf("\n");

int pattern[n][n];

for(int i = 0; i < n; ++i)
{
    for(int j = 0; j < i + 1; ++j)
    {
        pattern[i][j] = i + 1;
        printf("%d", pattern[i][j]);
    }

    printf("\n");
}

/*
b/ Use 2D array to print n lines in the following pattern. 

x
x x
x x x
x x x x
x x x x x
x x x x x x

*/

int n = 5;
char pattern[n][n];

for(int i = 0; i < n; ++i)
{
    for(int j = 0; j < i + 1; ++j)
    {
        pattern[i][j] = 'x';
        printf("%c ", pattern[i][j]);
    }

    printf("\n");
}

/*
Exercise 3 
Ask the user to type in 9 numbers in 3 rows of 3 numbers each. Your job is to: 
a/ read the numbers in a two-dimensional array, 
b/ compute the sum of each row and each column, and 
c/ output the array as well as the row and column sums in the following format: 
        
        ARRAY:      ROW SUM
        1   2   3       6
        3   3   3       9
        3   2   1       6
COLUMN SUMS:
        7   7   7
*/

int array[3][3];

printf("Populate the 3x3 array.\n");
for(int i = 0; i < 3; ++i)
{
    for(int j = 0; j < 3; ++j)
    {
        printf("\nColumn%d row%d: ", i + 1, j + 1);
        scanf("%d", &array[i][j]);
    }
}

int col1Sum = 0;
int col2Sum = 0;
int col3Sum = 0;

printf("Array:      Row Sum:\n");
for(int i = 0; i < 3; ++i)
{
    int rowSum = 0;
    for(int j = 0; j < 3; ++j)
    {
        printf("%d ", array[i][j]);
        rowSum += array[i][j];

        switch (i)
        {
            case 0: col1Sum += array[i][j]; break;
            case 1: col2Sum += array[i][j]; break;
            case 2: col3Sum += array[i][j]; break;
            default: printf("Switch out of range (did i got bigger?)");
        }
    }
    printf("      %d\n", rowSum);
}

printf("Column Sum: \n %d %d %d", col1Sum, col2Sum, col3Sum);

/*
Exercise 4
Write a program that allows a user to play tic tac toe. The program should ask for moves 
alternating between player X and player O (alternatively, the second player can be the computer). 
The program displays the game positions as follows: 

        1   2   3
        4   5   6
        7   8   9

The players enter their moves by entering the position number. After each move, the program displays
the changed board. A sample configuration would be: 

        X   X   O
        4   5   6
        O   8   9

The game ends when:
a/ a player has 3 Xs or 3 Os spanning across the board, horizontally, vertically, or diagonally, or
b/ there are no moves that can be made 

*/
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

void DisplayGameBoard(char gameBoard[5][5])
{
    printf("\n\n");
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            printf("%c", gameBoard[i][j]);
        }
        printf("\n");
    }
}

void TurnPosToPosXY(int pos, int* posX, int* posY)
{
    switch (pos)
    {
        case 1: *posX = 0; *posY = 0; break;
        case 2: *posX = 2; *posY = 0; break;
        case 3: *posX = 4; *posY = 0; break;
        case 4: *posX = 0; *posY = 2; break;
        case 5: *posX = 2; *posY = 2; break;
        case 6: *posX = 4; *posY = 2; break;
        case 7: *posX = 0; *posY = 4; break;
        case 8: *posX = 2; *posY = 4; break;
        case 9: *posX = 4; *posY = 4; break;
        default: printf("Problem with the switch in MakeBotMove();");
    }
}

int MakeBotMove(char gameBoard[5][5])
{
    int pos;
    int posX; 
    int posY; 

    do
    {
        pos = rand() % 8 + 1;
        TurnPosToPosXY(pos, &posX, &posY);
    }
    while(gameBoard[posY][posX] == 'X' || gameBoard[posY][posX] == 'O'); 

    return pos;
}

bool CheckIfGameIsFinish(char gameBoard[5][5])
{
    bool isGameWon = 0;
    bool isGameTie = 0;
    
    //Horizontal Lines
    for (int i = 0; i < 5; i += 2)
    {
        if(gameBoard[i][0] == gameBoard[i][2])
        {
            if(gameBoard[i][2] == gameBoard[i][4])
            {
                isGameWon = 1; break;
            }
        }
    }

    if(!isGameWon)
    {
        //Vertical Lines
        for (int i = 0; i < 5; i += 2)
        {
            if(gameBoard[0][i] == gameBoard[2][i])
            {
                if(gameBoard[2][i] == gameBoard[4][i])
                {
                    isGameWon = 1; break;
                }
            }
        }
    }
    
    if(!isGameWon)
    {
        //Diadonal lines
        if((gameBoard[0][0] == gameBoard[2][2] && gameBoard[2][2] == gameBoard[4][4]) || (gameBoard[0][4] == gameBoard[2][2] && gameBoard[2][2] == gameBoard[4][0]))
        {
            isGameWon = 1;
        }
    }

    bool isBoardFull = 1;
    if(!isGameWon)
    {
        for (int x = 0; x < 5; x += 2)
        {
            for(int y = 0; y < 5; y += 2)
            {
                if(gameBoard[x][y] != 'X' && gameBoard[x][y] != 'O')
                {
                    isBoardFull = 0; 
                    break;
                }
            }

            if(!isBoardFull) break;
        }
    }

    if(isGameWon)
    {
        printf("\n\nWell played!\n");
        return 1;
    }

    if(!isGameWon && isBoardFull)
    {
        printf("\n\nTie!\n");
        return 1;
    }

    return 0;
}

void ManageTurns(bool isSoloGame, bool isPlayer1Turn, char gameBoard[5][5], char player1Char)
{
    do{
        int move;
        char charToPlace;
        int posX;
        int posY;

        do{ 
            if(isPlayer1Turn)
            {
                if(isSoloGame)
                {
                    printf("\n\nYour turn!");
                }
                else
                {
                    printf("\n\nPlayer1 turn: ");
                }
                scanf("%d", &move);
                charToPlace = player1Char;
            }
            else
            {
                if(isSoloGame)
                {
                    printf("\n\nMy turn!");
                    move = MakeBotMove(gameBoard);
                }
                else
                {
                    printf("\n\nPlayer2 turn: ");
                    scanf("%d", &move);
                }

                if(player1Char == 'X')
                {
                    charToPlace = 'O';
                }
                else
                {
                    charToPlace = 'X';
                }
            }

            if(move > 0 && move < 10)
            {
                TurnPosToPosXY(move, &posX, &posY);
            }
        } while (move < 1 || move > 9 || gameBoard[posY][posX] == 'X' || gameBoard[posY][posX] == 'O');

        gameBoard[posY][posX] = charToPlace;

        if(isPlayer1Turn)
        {
            isPlayer1Turn = 0;
        }
        else
        {
            isPlayer1Turn = 1;
        }
        DisplayGameBoard(gameBoard);
    }while (!CheckIfGameIsFinish(gameBoard));
}

void StartGame(bool isSoloGame/*, int difficulty*/) //I might add a dificulty option later
{
    char player1Char;
    do
    {
        printf("\n\nChoose your character:\nDo you want to play as X or O?\n");
        scanf(" %c", &player1Char); 
        
        player1Char = toupper(player1Char);
    }
    while (player1Char != 'X' && player1Char != 'O');

    char gameBoard[5][5] = {
        {'1','|','2','|','3'},
        {'-','+','-','+','-'},
        {'4','|','5','|','6'},
        {'-','+','-','+','-'},
        {'7','|','8','|','9'}
    };

    DisplayGameBoard(gameBoard);
    printf("(type the number of the posistion you want to place your character when it is your turn to make your move)");

    bool isPlayer1Turn = 0;

    if(player1Char == 'O')
    {
        isPlayer1Turn = 1;
    }

    ManageTurns(isSoloGame, isPlayer1Turn, gameBoard, player1Char);
}

void GenerateOptionsMenu()
{
    printf("No options were implemented yet\n");
}

bool GenerateMainMenu()
{
    printf("TicTacToe! (type the number to select an option)\n\n1. Solo\n2. Multiplayer\n3. Options\n4. Exit\n\n");

    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
        case 1: StartGame(1); break;
        case 2: StartGame(0); break;
        case 3: GenerateOptionsMenu(); break;
        case 4: printf("\n\nbye bye!"); return 1;
        default: printf("\n\nGG but you'll have better luck whit an option from the menu\n\n");
    }

    return 0;
}

int main()
{
    bool closeProgram = 0;
    do
    {
        closeProgram = GenerateMainMenu();
    }
    while(!closeProgram);
    
    return 0;
}

/*
Exercise 5

Write a program to assign passenger seats in an airplane. Assume a small airplane with seats numbered as
follows:

1 A B   C D
2 A B   C D
3 A B   C D
4 A B   C D
5 A B   C D
6 A B   C D
7 A B   C D   

The program should display the seat pattern, marking with an 'X' the seats already assigned. For example,
after seats 1A, 2B, and 4C are taken, the display should look like:

1 X X   C D
2 A B   C D
3 A B   C D
4 A B   X D
5 A B   C D
6 A B   C D
7 A B   C D   

After displaying the seats available, the program prompts for the seats desired, the user types in a seat,
and then a display of available seats is updated. This continues until all seats are filled or until the user 
signals that the program should end. If the user types in a seat that is already assigned, the program should
say that the seat is occupied and ask for another choice. 
*/