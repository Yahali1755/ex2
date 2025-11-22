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
    int positiveNumber;
    int summaryOfGoldenCorns = 0;
    unsigned int numberOfDucks;
    int eachDuckNumberByBits = 0;
    int duckSaidWhichNumber;
    int exponent;
    int numberToPower;
    int poweredNumber;
    int ducksInDuckParade;
    int ducksPerLine;
    int repeatedDigitNumber;
    int temporaryNumber;
    int currentlyExaminedDigit;
    
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
                printf("please enter a positive number:\n");

                do {
                    scanf("%d", &positiveNumber);

                    if (positiveNumber <= 0 ) {
                        printf("Invalid number, please try again\n");
                    } 
                } while (positiveNumber <= 0);


                while (positiveNumber > 0) {
                     // Count lsb's with the value of 1
                    if ((positiveNumber & 1) == 1) {
                        summaryOfGoldenCorns++;
                    }

                    // Shift the number right untill it is 0 so there are no bits left to count
                    positiveNumber >>= 1;
                }

                printf("Ducky earns %d corns\n", summaryOfGoldenCorns);

                summaryOfGoldenCorns = 0;

                break;
            // TASK 2: The Memory Game
            case 2:
                printf("please enter the number of ducks:\n");

                do {
                    scanf("%u", &numberOfDucks);

                    if (numberOfDucks <= 0) {
                        printf("Invalid number, please try again\n");
                    }
                } while (numberOfDucks <= 0);

                printf("you entered %d ducks\n", numberOfDucks);

                for (unsigned int i = 1; i <= numberOfDucks; i++) {
                    do {
                        printf("duck %d do QUAK? 1 for yes, 0 for no\n", i);

                        scanf("%d", &duckSaidWhichNumber);

                        // Check valid input
                        if (duckSaidWhichNumber == 1 || duckSaidWhichNumber == 0) {
                            eachDuckNumberByBits <<= 1;

                            // Add the number the duck said as bit then left shift to store the next bit
                            if (duckSaidWhichNumber == 1) {
                                eachDuckNumberByBits = eachDuckNumberByBits | 1;
                            }
                        } else {
                            printf("Invalid number, please try again\n");
                        }
                    } while (duckSaidWhichNumber != 1 && duckSaidWhichNumber != 0);
                };

                for (unsigned int i = 1; i <= numberOfDucks; i++) {
                    // shift to the bit that represents the duck number and bitmask 1 to check its value
                    if ((eachDuckNumberByBits >> (numberOfDucks - i)) & 1) {
                        printf("duck number %d do Quak\n", i);
                    } else {
                        printf("duck number %d do Sh...\n", i);
                    }
                }

                eachDuckNumberByBits = 0;
                
                break;
            // TASK 3: Professor Pat's Power Calculation
            case 3:
                printf("please enter the number\n");
                
                do {
                    scanf("%d", &numberToPower);

                    if (numberToPower < 0) {
                        printf("Invalid number, please try again\n");
                    }
                } while (numberToPower < 0);

                printf("please enter the exponent\n");

                do {
                    scanf("%d", &exponent);

                    if (exponent < 0) {
                        printf("Invalid number, please try again\n");
                    }
                } while (exponent < 0);

                poweredNumber = numberToPower;

                if (exponent != 0) {
                    for (int i = 0; i < exponent - 1; i++) {
                        // multiply the number by itself, exponent - 1 times to get the power
                        poweredNumber *= numberToPower;
                    }

                    printf("your power is: %d\n", poweredNumber);
                } else {
                    printf("your power is: 1\n");
                }

                break;
            // TASK 4: The Duck Parade
            case 4:
                printf("please enter number of ducks:\n");

                do {
                    scanf("%d", &ducksInDuckParade);

                    if (ducksInDuckParade <= 0) {
                        printf("Invalid number, please try again\n");
                    }
                } while (ducksInDuckParade <= 0);

                do {
                    // Print up to 10 ducks per line
                    ducksPerLine = (ducksInDuckParade >= 10) ? 10 : ducksInDuckParade;

                    for (int i = 1; i <= ducksPerLine; i++) {
                        // Print first line of what the ducks consist of
                        printf("   _\t\t");
                    }

                    printf("\n");

                    for (int i = 1; i <= ducksPerLine; i++) {
                        // Print second line of what the ducks consist of
                        printf("__(o)>\t\t");
                    }
                    
                    printf("\n");

                    for (int i = 1; i <= ducksPerLine; i++) {
                        // Print second line of what the ducks consist of
                        printf("\\___)\t\t");
                    }

                    // remove printed ducks
                    ducksInDuckParade -= 10;

                    printf("\n");
                } while (ducksInDuckParade > 0);

                break;
            // TASK 5: The Mystery of the Repeated Digits
            case 5:
                printf("please enter number\n");

                do {
                    scanf("%d", &repeatedDigitNumber);

                    if (repeatedDigitNumber <= 0) {
                        printf("Invalid number, please try again\n");
                    }
                } while (repeatedDigitNumber <= 0);

                while (repeatedDigitNumber > 0) {
                    // Examine the rightmost digit
                    currentlyExaminedDigit = repeatedDigitNumber % 10;
                    temporaryNumber = repeatedDigitNumber / 10;

                    // Compare currently examined digit with each digit with the input number
                    while (temporaryNumber > 0) {
                        if (currentlyExaminedDigit == temporaryNumber % 10) {
                            printf("%d appears more than once!\n", currentlyExaminedDigit);

                            break;
                        }

                        // Get rid of the unit's digit by dividing by 10
                        temporaryNumber /= 10;
                    }

                    repeatedDigitNumber /= 10;
                }

                break;
            // TASK 6: EXIT
            case 6:
                printf("Good night! See you at the pond tomorrow.");

                break;
            default:
                printf("Invalid option, please try again\n");
        }
    } while (numberOfOption != exitKeywordNumber);
    
    // dont forget through all the necessary parts to validate invalid input.

    return 0;
}
