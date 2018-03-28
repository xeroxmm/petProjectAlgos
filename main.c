#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "sumOfNumberString/sumnumber.main.h"
#include "miniStart/main.mini.h"
#include "primeNumber/prime.main.h"

#define LATEST 1
#define MINI 2
#define PRIME 3
#define NUMBERSTRING 4

int keyFromArg(char *string){
    if(strcmp(string,"ministart") == 0)
        return MINI;

    if(strcmp(string,"primenumber") == 0)
        return PRIME;

    if(strcmp(string,"numberstring") == 0)
        return NUMBERSTRING;

    return LATEST;
}

int main(int argc, char *argv[]) {
    srand((unsigned int) time(NULL));

    if(argc > 1) {
        printf("Let the Battle Begin! %s \n", argv[1]);
    } else
        argv[1] = "";

    switch(keyFromArg(argv[1])){
        case MINI:
            mainMini(argc);
            break;
        case PRIME:
            testPrimeSuite();
            break;
        case NUMBERSTRING:
            testNumberStringMain();
            break;
        case LATEST:
        default:
            testNumberStringMain();
            break;
    }

    printf("\nPress ENTER key to Continue\n");
    getchar();
    printf("OKAY");
    return 0;
}