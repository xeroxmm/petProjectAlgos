//
// Created by marti on 28.03.2018.
//

#include <stdio.h>
#include "main.mini.h"

int mainMini(int argc){
    printf("Hello, its me, miniStart! %d \n",argc);

    printf("Fib Vars: %ld \n", getFibonacciNumberCalculatedWithVars( 20 ));
    printf("Fib Pointer: %ld \n", getFibonacciNumberCalculatedWithPointer( 20 ));

    littlePointerShowcase();
}
long getFibonacciNumberCalculatedWithVars(unsigned int n){
    long number = 1;
    long lastNumber = 0;
    long temp = 0;
    int i = 0;

    for(i = 0; i < n; i++){
        temp = lastNumber;
        lastNumber = number;
        number += temp;
    }

    return number + lastNumber;
}
long getFibonacciNumberCalculatedWithPointer(unsigned int n){
    long values[3] = {1,0,0};
    long* pointer = values;

    while(n--){
        *(pointer + 2) = values[1];
        values[1] = *pointer;
        pointer[0] += *(values + 2);
    }

    return values[0] + values[1];
}

void littlePointerShowcase(){
    printf("\nThe Poiner Showcase!\n\n");

    int justANumber999 = 999;
    printf("The number999! %d \n", justANumber999);

    int* addressOfVar999 = &justANumber999;
    printf("The address of number999! %p \n", addressOfVar999);

    int anotherVarOf999 = *addressOfVar999;
    printf("The anotherVarOf999! %d \n", anotherVarOf999);
    printf("The address of anotherVarOf999! %p \n", &anotherVarOf999);

    int aSecondNumber5 = 5;
    printf("The aSecondNumber5! %d \n", aSecondNumber5);


    int* addressOfVar5 = &aSecondNumber5;
    printf("The address of aSecondNumber5! %p \n", addressOfVar5);

    // break up var 5
    addressOfVar5 = &justANumber999;
    printf("The NEW address of addressOfVar5 IS NOT a new address of aSecondNumber5! %p \n", addressOfVar5);

    *(addressOfVar999) = 1;
    printf("The number999! %d \n", justANumber999);
    printf("The anotherVarOf999! %d \n", anotherVarOf999);
    printf("The aSecondNumber5! %d \n", aSecondNumber5);
    printf("The Value, that address addressOfVar5 points to! %d \n", *addressOfVar5);
}