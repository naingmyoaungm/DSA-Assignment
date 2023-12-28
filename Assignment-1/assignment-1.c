//
// Created by ASUS on 12/5/2023.
//

#include "stdio.h"

int main(){

    int i=0;
    int space1=0;
    int space2=0;
    int star=0;
    int row1=10;
    int row2=10;

    printf("This is testing2!\n");

    for(i=0; i < row1; i++){

        for( space1=0; space1<=row1-i; space1++){
            printf(" ");
        }
        for(star=0; star<i*2-1; star++){
            printf("*");
        }
        for(space2=0; space2<row2*2-i*2; space2++){
            printf(" ");
        }
        for(star=0; star<i*2-1; star++){
            printf("*");
        }
        printf("\n");

    }

}