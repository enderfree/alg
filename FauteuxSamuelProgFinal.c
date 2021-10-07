#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

struct Smartphone
{
    char brand[15];
    char nameAndOrModel[20];
    int screenSize[2];
    int memory;
    int cameraResolution; 
    float prices[3]; 
    int nbInStock;
};

struct Smartphone smartphones[50];
int k = 0; //k keeps the number of items that were inserted in smartphones but why the heck is it called k?

bool CheckIfUserWantToContinue(char yesNoQuestion[])
{
    char choice;

    do{
        printf("\n\n%s (y for yes, n for no)\n", yesNoQuestion);
        scanf(" %c", &choice);
    }while(!(tolower(choice) == 'y' || tolower(choice) == 'n'));

    if(choice == 'y')
    {
        return 1;
    }
    return 0;
}

void PopulateInventory()
{
    char doYouWantToContinue[] = "Insert another product?";
    do{
        printf("\n\nBrand: ");
        scanf("%s", smartphones[k].brand);
        printf("\nName and/or model: "); //this make me feel like it should be two field but the instructions make me doubt this
        scanf("%s", smartphones[k].nameAndOrModel);

        printf("\nScreen width (in inches): ");
        scanf(" %d", &smartphones[k].screenSize[0]); //the space before the %d is mendatory (it get rid of trailling ints)
        printf("\nScreen height (in inches): ");
        scanf("%d", &smartphones[k].screenSize[1]);

        printf("\nMemory (in G): "); //phone memory is always a clean Gigabyte number
        scanf("%d", &smartphones[k].memory);
        printf("\nCamera resolution: "); //camera resolution tend to be represented by the width only, idk why
        scanf("%d", &smartphones[k].cameraResolution);
        printf("\nNumber in stock: ");
        scanf("%d", &smartphones[k].nbInStock);

        printf("\n\nPrices: \nNo plan: "); 
        scanf("%f", &smartphones[k].prices[0]);
        printf("\nOne year plan: ");
        scanf("%f", &smartphones[k].prices[1]);
        printf("\nTwo years plan: ");
        scanf("%f", &smartphones[k].prices[2]);

        ++k;
    }while (CheckIfUserWantToContinue(doYouWantToContinue));
}

void DisplayInventoryEntry(int smartphoneIndex)
{
    printf("\n\nBrand: %s\nName and/or model: %s\nScreen size: %dX%d\nMemory: %dG\nCamera resolution: %dp\nNumber in stock: %d\n\nPrices: \nNo plan: $%.2f\nOne year plan: $%.2f\nTwo years plan: $%.2f\n", smartphones[smartphoneIndex].brand, smartphones[smartphoneIndex].nameAndOrModel, smartphones[smartphoneIndex].screenSize[0], smartphones[smartphoneIndex].screenSize[1], smartphones[smartphoneIndex].memory, smartphones[smartphoneIndex].cameraResolution, smartphones[smartphoneIndex].nbInStock, smartphones[smartphoneIndex].prices[0], smartphones[smartphoneIndex].prices[1], smartphones[smartphoneIndex].prices[2]);
}

void Searchbybrand(char brand[15])
{
    bool found = 0;

    for (int i = 0; i < k; ++i)
    {
        if(strcmp(smartphones[i].brand, brand) == 0)
        {
            found = 1;
            DisplayInventoryEntry(i);
        }
    }
    
    if(!found)
    {
        printf("Sorry, Mr. User, we are out of %s phones", brand);
    }
}

void ProcessPurchase(int i)
{
    if(smartphones[i].nbInStock > 0)
    {
        char confirmPurchase[] = "Please type Y to confirm your purchase: ";
        int choice;
        do{
            printf("\n\nDo you want: \n 1. No plan for $%.2f\n 2. One year plan for $%.2f\n 3. Two year plan for $%.2f\n(Select the number to make your choice)\n", smartphones[i].prices[0], smartphones[i].prices[1], smartphones[i].prices[2]);
            scanf("%d", &choice);
        }while(choice < 1 || choice > 3);
        printf("\nThis will cost $%.2f", smartphones[i].prices[choice-1]);

        if(!CheckIfUserWantToContinue(confirmPurchase))
        {
            return;
        }
        --smartphones[i].nbInStock;
        printf("\n\nCongratulations! You now own the new %s %s", smartphones[i].brand, smartphones[i].nameAndOrModel);
    }
    else
    {
        printf("\n\nSorry, we have 0 %s %s in stock!", smartphones[i].brand, smartphones[i].nameAndOrModel);
    }
}

bool SearchByModel(char model[], int* searchedModelIndex)
{
    *searchedModelIndex = 0;
    bool found = 0;
    for (int i = 0; i < k; ++i)
    {
        if(strcmp(model, smartphones[i].nameAndOrModel) == 0)
        {
            found = 1;
            *searchedModelIndex = i;
            break;
        }
    }
    return found;
}

void BuyAnItem()
{
    char buySomeMore[] = "Do you want to purchase another item? ";
    do{
        char desiredModel[15];
        int desiredModelIndex;
        printf("\n\nPlease type the name of the disired model: ");
        scanf("%s", desiredModel);
        if(!SearchByModel(desiredModel, &desiredModelIndex))
        {
            printf("\n\nSorry we didn't find that model in our inventory");
        }
        else
        {
            ProcessPurchase(desiredModelIndex);
        }
    }while(CheckIfUserWantToContinue(buySomeMore));
}

void ReturnPhone()
{
    char returnSomeMore[] = "Do you want to return another item? ";
    do{
        char desiredModel[15];
        int desiredModelIndex;
        printf("\n\nPlease type the name of the model you want to return: ");
        scanf("%s", desiredModel);
        if(!SearchByModel(desiredModel, &desiredModelIndex))
        {
            printf("\n\nSorry we can't accept this return.");
        }
        else
        {
            ++smartphones[desiredModelIndex].nbInStock;
            printf("\n\nReturn completed, here's your money!");
        }
    }while(CheckIfUserWantToContinue(returnSomeMore));
}

bool Exit(bool keepGoing)
{
    if(keepGoing)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

bool GenerateMainMenu()
{
    printf("Type the number to select an option\n\n1. Populate inventory\n2. Display all items of a brand\n3. Buy an item\n4. Return an Item\n5. Display inventory content\n6. Exit the system\n\n");

    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:  PopulateInventory(); break;
        case 2: ;
            char searchForAnotherBrand[] = "Search for another brand? ";
            do{
                char brand[15];
                printf("Which brand are you looking for? ");
                scanf("%s", brand);
                Searchbybrand(brand);
            }while(CheckIfUserWantToContinue(searchForAnotherBrand)); //the guide lines start to be very bothersome, I preferred my own naming convetion and my while was out of the case
            break;
        case 3:  BuyAnItem(); break;
        case 4: ReturnPhone(); break;
        case 5: 
            for (int i = 0; i < k; ++i)
            {
                DisplayInventoryEntry(i);
            }
            break;
        case 6: return Exit(0);
        default: printf("\n\nUnknown option\n\n");
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