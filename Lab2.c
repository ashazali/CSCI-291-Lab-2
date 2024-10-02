#include <stdio.h>
#include <math>

#define ESPRESSO_BEANS 8
#define ESPRESSO_WATER 30
#define ESPRESSO_PRICE 3.50
#define CAPPUCCINO_BEANS 8
#define CAPPUCCINO_WATER 30
#define CAPPUCCINO_MILK 70
#define CAPPUCCINO_PRICE 4.5
#define MOCHA_BEANS 8
#define MOCHA_WATER 39
#define MOCHA_MILK 160
#define MOCHA_CHOCOLATESYRUP 30
#define MOCHA_PRICE 5.5
#define LOW_BEANS_THRESHOLD 10
#define LOW_WATER_THRESHOLD 50
#define LOW_MILK_THRESHOLD 100
#define LOW_SYRUP_THRESHOLD 20
#define ADMIN_PASSWORD 1234

//Initial quantities in the machine
int available_beans = 100;
int available_water = 500;
int available_milk = 500;
int available_syrup = 200;
double total_amount = 0.0;

void display_menu();
void make_coffee(int choice);
void check_ingredients();
void admin_menu();
void refill_ingredients();




