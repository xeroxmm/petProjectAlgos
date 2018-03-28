//
// Created by marti on 28.03.2018.
//

#include <stdio.h>
#include <stdlib.h>
#include "prime.main.h";

void testPrimeSuite(){
    int i = 25;
    int randomNumber = 0;
    while(i--){
        randomNumber = rand() % 200; // NOLINT
        if(testPrime( randomNumber ))
            printf("%d is a prime\n", randomNumber);
        else
            printf("NOPE1 %d is NOT a prime\n", randomNumber);
    }
}
int testPrime(int number ){
    if(number <= 1)
        return 0;
    else if(number <= 3)
        return 1;
    else if(!(number % 2) || !(number % 3))
        return 0;

    int i = 5;
    while( i*i <= number ){
        if(!(number % i) || !(number % (i + 2)))
            return 0;
        i += 6;
    }
    return 1;
}