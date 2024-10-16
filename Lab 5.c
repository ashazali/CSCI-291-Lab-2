#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define ESPRESSO_BEANS 8
#define ESPRESSO_WATER 30

#define CAPPUCCINO_BEANS 8
#define CAPPUCCINO_WATER 30
#define CAPPUCCINO_MILK 7

#define MOCHA_BEANS 8
#define MOCHA_WATER 39
#define MOCHA_MILK 160
#define MOCHA_SYRUP 30

#define LOW_BEANS_THRESHOLD 10
#define LOW_WATER_THRESHOLD 50
#define LOW_MILK_THRESHOLD 100
#define LOW_SYRUP_THRESHOLD 30
#define ADMIN_PASSWORD "1234"

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

void replenishIngredients() {
    int ADDBEANS,ADDWATER,ADDMILK,ADDSYRUP;
    printf("enter beans amount: ");
    scanf("%d",ADDBEANS);
    AVAILABLE_BEANS += ADDBEANS;
    printf("total amount of beans %d",AVAILABLE_BEANS);
    
    printf("enter water amount: ");
    scanf("%d",ADDWATER);
    AVAILABLE_WATER += ADDWATER;
    printf("total amount of water %d",AVAILABLE_WATER);

    printf("enter milk amount: ");
    scanf("%d",ADDMILK);
    AVAILABLE_MILK += ADDMILK;
    printf("total amount of milk %d",AVAILABLE_MILK);

    printf("enter water amount: ");
    scanf("%d",ADDSYRUP);
    AVAILABLE_SYRUP += ADDSYRUP;
    printf("total amount of syrup %d",AVAILABLE_SYRUP);

}

int changeCoffeePrice() {
    int ans;
    float NEWESPRESSOPRICE, NEWCAPPUCCINOPRICE, NEWMOCHAPRICE;
    printf("Coffee prices:");
    printf("1. Espresso - %f \n ", ESPRESSO_PRICE);
    printf("2.Cappuccino - %f \n ", CAPPUCCINO_PRICE);
    printf("3. Mocha - %f \n", MOCHA_PRICE);
    printf("0. Exit \n");
    printf("Which coffee price do you want to change 1/2/3/0? \n");
    scanf("%d",&ans);
    switch(ans){
    case 1:
        printf("Enter new espresso price: \n");
        scanf("%f",&NEWESPRESSOPRICE);
        ESPRESSO_PRICE=NEWESPRESSOPRICE;
        break;
    case 2:
        printf("Enter new capuccino price: \n");
        scanf("%f",&NEWCAPPUCCINOPRICE);
        CAPPUCCINO_PRICE=NEWCAPPUCCINOPRICE;
        break;
    case 3:
        printf("Enter new mocha price: \n");
        scanf("%f",&NEWMOCHAPRICE);
        MOCHA_PRICE=NEWMOCHAPRICE;
        break;
    case 0:
        printf("Exiting \n");
        return 0;
    default:
    printf("Invalid choice\n");
    }
}

int admin_mode(){
    char password[4];
    printf("Enter the admin password: \n");
    scanf("%s",password);
    if (strcmp(password,ADMIN_PASSWORD)!=0){
        printf("Incorrect. Try Again. \n");
        printf("Enter the admin password: ");
        scanf("%s",password);
        if (strcmp(password,ADMIN_PASSWORD)!=0){
            printf("Incorrect. Try Again. \n");
            printf("Enter the admin password: ");
            scanf("%s",password);
            if (strcmp(password,ADMIN_PASSWORD)!=0){
                printf("blocked\n");
                return 0;
            }
            return 0;
        }
    }


    int ans;
    while (true){
        printf("\n Admin Mode \n ");
        printf("1. Display the quantity of each ingredient in the machine and the total sale amount \n ");
        printf("2. Replenish ingredients in the machine \n");
        printf("3. Change coffee price \n");
        printf("0. Exit the Admin Mode function \n ");
        printf("Enter your choice 1/2/3/0 \n");
        scanf("%d",&ans);
        switch(ans){
        case 1:
            printf("coffeebeans -%d \n",AVAILABLE_BEANS);
            printf("water -%d \n",AVAILABLE_WATER);
            printf("milk -%d\n",AVAILABLE_MILK);
            printf("syrup -%d \n",AVAILABLE_SYRUP);
            totalsales();
            break;
        case 2:
            replenishIngredients();
            break;
        case 3:
            changeCoffeePrice();
            break;
        case 0:
            printf("exiting admin mode");
            return 0;
        default:
            printf("invalid");
        }
    }    
}

int totalsales(){
    printf("coffeebeans -%d \n",AVAILABLE_BEANS);
    printf("water -%d \n",AVAILABLE_WATER);
    printf("milk -%d\n",AVAILABLE_MILK);
    printf("syrup -%d \n",AVAILABLE_SYRUP);
    printf("Total sales amount - %f \n", total_amt);
}

int order_coffee(){
    printf("...");
}

int main() {
    int choice;  
    while (1) {
        printf("\nCoffee Machine\n");
        printf("1. Order a coffee\n");
        printf("2. Admin mode\n");
        printf("3. Exit\n");
        printf("Enter your choice 1/2/3: ");
        scanf("%d", &choice);  
        switch (choice) {
            case 1:
                order_coffee();  
                break;
            case 2:
                admin_mode();    
                break;
            case 3:
                printf("Exiting Machine...Bye\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}











