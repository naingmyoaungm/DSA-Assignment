//
// Created by ASUS on 12/15/2023.
//

#include "stdio.h"

int addition(int num1, int num2);
int subtraction(int num1, int num2);
int multiplication(int num1, int num2);
int division(int num1, int num2);

int main(){

    int plus = addition(20,10);
    int minus = subtraction(30,10);
    int multi = multiplication(30, 10);
    int divi = division(40, 20);

    printf("Addition %d \n",plus);
    printf("Subtraction %d \n",minus);
    printf("Multiplication %d \n",multi);
    printf("Division %d \n",divi);

    return 0;
}

int addition(int num1, int num2){

    int total = num1+num2;
    return total;
}

int subtraction(int num1, int num2){

    int total = num1-num2;
    return total;
}

int multiplication(int num1, int num2){

    int total = num1 * num2;
    return total;
}

int division(int num1, int num2){

    int total = num1 / num2;
    return total;
}