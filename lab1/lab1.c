#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>


#define KM_TO_MILES 0.621371
#define MILES_TO_KM 1.60934
#define AREA_TRIANGLE_FACTOR 0.5

void convertDistance(){
    int choice;
    double value;


    while(1){
        printf("1 Км -> мили\n");
        printf("2 мили -> Км\n");
        printf("Выберите\n");

        if (scanf("%lf", &choice) != 1 || scanf("%lf", &choice) != 2){
            printf("Error! ");
            continue;
        }
        printf("Введите значение");
        if(scanf("%lf", &value)){

        }


    }



}