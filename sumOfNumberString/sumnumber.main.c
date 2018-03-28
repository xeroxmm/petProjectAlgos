//
// Created by marti on 28.03.2018.
//

#include <stdlib.h>
#include <stdio.h>

int getSumOfNumberString(char* theString){
    long lastNumber = 0;
    int i = 0;
    int isANumber = 1;
    int isNegative = 0;
    int sum = 0;

    char *ptr;
    char currentNumberString[100];
    while(*theString != '\0'){
        if(i == 0 && *theString == '-')
            isNegative = 1;
        else if((*theString >= '0' && *theString <= '9') && isANumber)
            currentNumberString[i] = *theString;
        else if(*theString == ' '){
            currentNumberString[i] = '\0';
            if(isANumber > 0){
                lastNumber = (int)strtol(currentNumberString, &ptr, 10);
                if(isNegative)
                    lastNumber *= -1;
            }
            sum += lastNumber;
            isANumber = 1;
            isNegative = 0;
            lastNumber = 0;
            i = -1;
        } else {
            isANumber = 0;
        }
        theString++;
        i++;
    }
    return sum;
}

void testNumberStringMain(){
    char testString[100] = "";
    int i = 0;
    int k = 1;
    int randX = 0;

    while(i < 98){
        if(k == 0) {
            k = rand() % 5 + 2; // NOLINT
            testString[i] = ' ';
        } else {
            randX = 48 + (rand() % 9 + 1); // NOLINT
            testString[i] = (char)randX;
        }
        k--;
        i++;
    }
    testString[98] = ' ';
    testString[99] = '\0';

    printf("The String: %s\n", testString);

    printf("The sum is: %d\n",getSumOfNumberString(testString));
}