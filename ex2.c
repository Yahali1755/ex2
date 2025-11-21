/******************
Name: Yahali Mashiach
ID: 214007346
Assignment: ex2
*******************/

#include <stdio.h>

int main()
{
    int numberOfOption;
    // If the user enters 6 the program stops
    int exitKeywordNumber = 6;
    unsigned positiveNumber;
    int summaryOfGoldenCorns = 0;
    unsigned int numberOfDucks;
    int eachDuckNumberByBits = 0;
    int duckSaidWhichNumber;
    
    // MAIN MENU LOOP
    do {
        printf("Welcome to our games, please choose an option:\n"
       "1. Ducky's Unity Game\n"
       "2. The Memory Game\n"
       "3. Professor Pat's Power Calculation\n"
       "4. The Duck Parade\n"
       "5. The Mystery of the Repeated Digits\n"
       "6. Good Night Ducks\n");

        scanf("%d", &numberOfOption);
        
        switch(numberOfOption) {
            // TASK 1: Ducky's Unity Game
            case 1:
                do {
                    printf("please enter a positive number:\n");

                    scanf("%d", &positiveNumber);

                    if (positiveNumber > 0 ) {
                        while (positiveNumber > 0) {
                            // Count rightmost bits with the value of one by mod 2
                            if (positiveNumber & 1 == 1) {
                                summaryOfGoldenCorns++;
                            }

                            // Shift the number right untill it is 0 so there are no bits left to count
                            positiveNumber >>= 1;
                        }

                        printf("Ducky earns %d corns\n", summaryOfGoldenCorns);

                        summaryOfGoldenCorns = 0;
                    }
                    else {
                        printf("Invalid number, please try again\n");
                    } 
                } while (positiveNumber > 0);

                break;
            // TASK 2: The Memory Game
            case 2:
                printf("please enter the number of ducks:\n");

                do {
                    scanf("%d", &numberOfDucks);

                    if (numberOfDucks > 0) {
                        for (int i = 1; i <= numberOfDucks; i++) {
                            do {
                                printf("duck %d said QUAK? 1 for yes, 0 for no\n", i);

                                scanf("%d", &duckSaidWhichNumber);

                                // Check valid input
                                if (duckSaidWhichNumber == 1 || duckSaidWhichNumber == 0) {
                                    eachDuckNumberByBits <<= 1;

                                    // Add the number the duck said as bit then left shift to store the next bit
                                    if (duckSaidWhichNumber == 1) {
                                        eachDuckNumberByBits = eachDuckNumberByBits | 1;
                                    }
                                }
                            } while (duckSaidWhichNumber != 1 && duckSaidWhichNumber != 0);
                        };

                        for (int i = 1; i <= numberOfDucks; i++) {
                            // shift to the leftmost bit and mod 2 to check its value
                            if ((eachDuckNumberByBits >> (numberOfDucks - i)) & 1) {
                                printf("Duck number %d do Quak\n", i);
                            } else {
                                printf("Duck number %d do Sh...\n", i);
                            }
                        }

                        eachDuckNumberByBits = 0;
                    } else {
                        printf("Invalid number, please try again\n");
                    } 
                } while (numberOfDucks <= 0);
                break;
            // TASK 3: Professor Pat's Power Calculation
            case 3:
                break;
            // TASK 4: The Duck Parade
            case 4:
                break;
            // TASK 5: The Mystery of the Repeated Digits
            case 5:
                break;
            // TASK 6: EXIT
            case 6:
                printf("Good night! see you at the pond tomorrow.\n");

                break;
            default:
                printf("Invalid option, please try again\n");
        }
    } while (numberOfOption != exitKeywordNumber);
    
    // dont forget through all the necessary parts to validate invalid input.

    return 0;
}
