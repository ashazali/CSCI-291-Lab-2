#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define ESPRESSO_BEANS 8
#define ESPRESSO_WATER 30
#define ESPRESSO_PRICE 3.50
#define CAPPUCCINO_BEANS 8
#define CAPPUCCINO_WATER 30
#define CAPPUCCINO_MILK 70
#define CAPPUCCINO_PRICE 4.50
#define MOCHA_BEANS 8
#define MOCHA_WATER 39
#define MOCHA_MILK 160
#define MOCHA_SYRUP 30
#define MOCHA_PRICE 5.50
#define LOW_BEANS_THRESHOLD 10
#define LOW_WATER_THRESHOLD 50
#define LOW_MILK_THRESHOLD 100
#define LOW_SYRUP_THRESHOLD 30
#define ADMIN_PASSWORD 1234

//Initial quantities in the machine
float total_amt = 0.0;
int AVAILABLE_BEANS = 100;
int AVAILABLE_WATER = 500;
int AVAILABLE_MILK = 500;
int AVAILABLE_SYRUP = 200;
int ESPRESSO_SOLD = 0;
int CAPPUCCINO_SOLD = 0;    
int MOCHA_SOLD = 0;
int ADDBEANS, ADDWATER, ADDMILK, ADDSYRUP;
float ESPRESSO_PRICE = 3.50;
float CAPPUCCINO_PRICE = 4.50;
float MOCHA_PRICE = 5.50;

bool availabilitycoffee(int BEANS, int WATER, int MILK, int SYRUP) {
    return AVAILABLE_BEANS >= BEANS && AVAILABLE_WATER >= WATER && 
           AVAILABLE_MILK >= MILK && AVAILABLE_SYRUP >= SYRUP;
}

void usedingredients(int BEANS, int WATER, int MILK, int SYRUP) {
    AVAILABLE_BEANS -= BEANS;
    AVAILABLE_WATER -= WATER;
    AVAILABLE_MILK -= MILK;
    AVAILABLE_SYRUP -= SYRUP;
}

void checkingforlowquantities(){
    if (AVAILABLE_BEANS<=LOW_BEANS_THRESHOLD)
        printf("More beans needed.\n");
    if (AVAILABLE_WATER<=LOW_WATER_THRESHOLD)
        printf("More water needed.\n");
    if (AVAILABLE_MILK<=LOW_MILK_THRESHOLD)
        printf("More milk needed.\n");
    if (AVAILABLE_SYRUP<=LOW_SYRUP_THRESHOLD)
        printf("More syrup needed.\n");
}

void replenishIngredients(int ADDBEANS, int ADDWATER, int ADDMILK, int ADDSYRUP) {
    AVAILABLE_BEANS += ADDBEANS;
    AVAILABLE_WATER += ADDWATER;
    AVAILABLE_MILK += ADDMILK;
    AVAILABLE_SYRUP += ADDSYRUP;

}

void changeCoffeePrice(float NEWESPRESSOPRICE, float NEWCAPPUCCINOPRICE, float NEWMOCHAPRICE) {
    ESPRESSO_PRICE = NEWESPRESSOPRICE;
    CAPPUCCINO_PRICE = NEWCAPPUCCINOPRICE;
    MOCHA_PRICE = NEWMOCHAPRICE;

}









