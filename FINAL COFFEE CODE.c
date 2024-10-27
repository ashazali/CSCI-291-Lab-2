#include <stdio.h>                 // Include standard input-output header
#include <stdbool.h>               // Include boolean type header
#include <stdlib.h>                // Include standard library header
#include <time.h>                  // Include time header for rand()

// Constants for coffee recipes and thresholds

#define ESPRESSO_BEANS 8          // Beans required for espresso
#define ESPRESSO_WATER 30         // Water required for espresso
#define CAPPUCCINO_BEANS 8        // Beans required for cappuccino
#define CAPPUCCINO_WATER 30       // Water required for cappuccino
#define CAPPUCCINO_MILK 7         // Milk required for cappuccino
#define MOCHA_BEANS 8             // Beans required for mocha
#define MOCHA_WATER 39            // Water required for mocha
#define MOCHA_MILK 160            // Milk required for mocha
#define MOCHA_SYRUP 30            // Syrup required for mocha
#define LOW_BEANS_THRESHOLD 10     // Threshold for low beans alert
#define LOW_WATER_THRESHOLD 50     // Threshold for low water alert
#define LOW_MILK_THRESHOLD 100     // Threshold for low milk alert
#define LOW_SYRUP_THRESHOLD 30      // Threshold for low syrup alert
#define ADMIN_PASSWORD 1234        // Using an integer for admin password

// Initial quantities in the machine

float total_amt = 0.0;            // Total sales amount
int AVAILABLE_BEANS = 400;        // Initial available coffee beans
int AVAILABLE_WATER = 600;        // Initial available water
int AVAILABLE_MILK = 500;         // Initial available milk
int AVAILABLE_SYRUP = 700;        // Initial available syrup
int ESPRESSO_SOLD = 0;            // Counter for sold espressos
int CAPPUCCINO_SOLD = 0;          // Counter for sold cappuccinos
int MOCHA_SOLD = 0;               // Counter for sold mochas
float ESPRESSO_PRICE = 3.50;      // Price of espresso
float CAPPUCCINO_PRICE = 4.50;    // Price of cappuccino
float MOCHA_PRICE = 5.50;         // Price of mocha

// Check if there are enough ingredients for a coffee

bool availablecoffees(int BEANS, int WATER, int MILK, int SYRUP) {
    return AVAILABLE_BEANS >= BEANS && AVAILABLE_WATER >= WATER &&  // Check beans and water availability
           AVAILABLE_MILK >= MILK && AVAILABLE_SYRUP >= SYRUP;    // Check milk and syrup availability
}

// Use ingredients from the available stock

void usedingredients(int BEANS, int WATER, int MILK, int SYRUP) {
    AVAILABLE_BEANS -= BEANS;     // Deduct beans from available stock
    AVAILABLE_WATER -= WATER;     // Deduct water from available stock
    AVAILABLE_MILK -= MILK;       // Deduct milk from available stock
    AVAILABLE_SYRUP -= SYRUP;     // Deduct syrup from available stock
}

// Check and report low quantities of ingredients

void checkingforlowquantities() {
    if (AVAILABLE_BEANS <= LOW_BEANS_THRESHOLD)   // Check if beans are low
        printf("More beans needed.\n");
    if (AVAILABLE_WATER <= LOW_WATER_THRESHOLD)   // Check if water is low
        printf("More water needed.\n");
    if (AVAILABLE_MILK <= LOW_MILK_THRESHOLD)     // Check if milk is low
        printf("More milk needed.\n");
    if (AVAILABLE_SYRUP <= LOW_SYRUP_THRESHOLD)    // Check if syrup is low
        printf("More syrup needed.\n");
}

// Replenish ingredients when they are low

void replenishIngredients() {
    int ADDBEANS, ADDWATER, ADDMILK, ADDSYRUP;   // Variables for added quantities

    while (AVAILABLE_BEANS < LOW_BEANS_THRESHOLD) { // Loop until beans are sufficient
        printf("Low beans, please replenish. Enter the number of beans added: \n");
        scanf("%d", &ADDBEANS);                   // Input amount of beans added
        AVAILABLE_BEANS += ADDBEANS;              // Update available beans
        printf(AVAILABLE_BEANS >= LOW_BEANS_THRESHOLD ? "Restocked.\n" : "Still insufficient. Add more.\n"); // Report status
    }

    while (AVAILABLE_WATER < LOW_WATER_THRESHOLD) { // Loop until water is sufficient
        printf("Low water, please replenish. Enter water added: \n");
        scanf("%d", &ADDWATER);                    // Input amount of water added
        AVAILABLE_WATER += ADDWATER;               // Update available water
        printf(AVAILABLE_WATER >= LOW_WATER_THRESHOLD ? "Restocked.\n" : "Still insufficient. Add more.\n"); // Report status
    }

    while (AVAILABLE_MILK < LOW_MILK_THRESHOLD) { // Loop until milk is sufficient
        printf("Low milk, please replenish. Enter milk added: \n");
        scanf("%d", &ADDMILK);                     // Input amount of milk added
        AVAILABLE_MILK += ADDMILK;                 // Update available milk
        printf(AVAILABLE_MILK >= LOW_MILK_THRESHOLD ? "Restocked.\n" : "Still insufficient. Add more.\n"); // Report status
    }

    while (AVAILABLE_SYRUP < LOW_SYRUP_THRESHOLD) { // Loop until syrup is sufficient
        printf("Low syrup. Please add. Enter syrup added: \n");
        scanf("%d", &ADDSYRUP);                    // Input amount of syrup added
        AVAILABLE_SYRUP += ADDSYRUP;               // Update available syrup
        printf(AVAILABLE_SYRUP >= LOW_SYRUP_THRESHOLD ? "Restocked.\n" : "Still insufficient. Add more.\n"); // Report status
    }
}

// Display total sales and quantities

void total_sales() {
    printf("Total sales amount - %.2f \n", total_amt); // Display total sales amount
    printf("Coffee beans - %d \n", AVAILABLE_BEANS);   // Display available beans
    printf("Water - %d \n", AVAILABLE_WATER);           // Display available water
    printf("Milk - %d \n", AVAILABLE_MILK);             // Display available milk
    printf("Syrup - %d \n", AVAILABLE_SYRUP);           // Display available syrup
    printf("Total money earned: %.2f \n", total_amt);   // Display total money earned
    printf("Total Espressos sold: %d \n", ESPRESSO_SOLD); // Display total espressos sold
    printf("Total Cappuccinos sold: %d \n", CAPPUCCINO_SOLD); // Display total cappuccinos sold
    printf("Total Mochas sold: %d \n", MOCHA_SOLD);     // Display total mochas sold
    
    int restart;  // Variable to control reset action
    printf("Do you want to reset the total sales amount? (1 for Yes, 0 for No): \n");
    scanf("%d", &restart);   // Input for reset action
    if (restart) {           // If user chooses to reset
        total_amt = 0;      // Reset total sales amount to 0
        printf("Total sales amount has been reset to 0 AED.\n"); // Confirmation message
    }
}

// Change the price of coffee items

void changeCoffeePrice() {
    int ans;                   // Variable for user choice
    float NEWESPRESSOPRICE, NEWCAPPUCCINOPRICE, NEWMOCHAPRICE; // Variables for new prices

    printf("Coffee prices: \n");
    printf("1. Espresso - %.2f AED \n", ESPRESSO_PRICE); // Display current espresso price
    printf("2. Cappuccino - %.2f AED \n", CAPPUCCINO_PRICE); // Display current cappuccino price
    printf("3. Mocha - %.2f AED \n", MOCHA_PRICE);       // Display current mocha price
    printf("0. Exit \n");                                 // Exit option
    printf("Which coffee price do you want to change? (1/2/3/0): \n");
    scanf("%d", &ans);                                   // Input for coffee price change choice

    switch(ans) {                                       // Switch based on user choice
        case 1:
            printf("Enter new espresso price: \n");    // Prompt for new espresso price
            scanf("%f", &NEWESPRESSOPRICE);            // Input new espresso price
            ESPRESSO_PRICE = NEWESPRESSOPRICE;         // Update espresso price
            break;
        case 2:
            printf("Enter new cappuccino price: \n");  // Prompt for new cappuccino price
            scanf("%f", &NEWCAPPUCCINOPRICE);          // Input new cappuccino price
            CAPPUCCINO_PRICE = NEWCAPPUCCINOPRICE;     // Update cappuccino price
            break;
        case 3:
            printf("Enter new mocha price: \n");       // Prompt for new mocha price
            scanf("%f", &NEWMOCHAPRICE);                // Input new mocha price
            MOCHA_PRICE = NEWMOCHAPRICE;                // Update mocha price
            break;
        case 0:
            printf("Exiting \n");                       // Exit message
            return;                                     // Exit function
        default:
            printf("Invalid choice\n");                 // Handle invalid choice
    }
}

// Admin mode functionality

int admin_mode() {
    int password;                                 // Variable for admin password input
    printf("Enter the admin password: \n");
    scanf("%d", &password);                       // Input admin password

    // Check the password
    if (password != ADMIN_PASSWORD) {             // Validate password
        printf("Incorrect password. Access denied.\n"); // Access denied message
        return 0;                                 // Exit function
    }

    int ans;                                      // Variable for user choice in admin mode
    while (true) {                                // Loop for admin mode options
        printf("\n Admin Mode \n ");
        printf("1. Display quantities and total sale amount \n"); // Option to display quantities
        printf("2. Replenish ingredients in the machine \n");      // Option to replenish ingredients
        printf("3. Change coffee price \n");                       // Option to change coffee prices
        printf("0. Exit Admin Mode \n");                           // Exit option
        printf("Enter your choice (1/2/3/0): \n");
        scanf("%d", &ans);                                        // Input for admin choice

        switch(ans) {                                         // Switch based on user choice
            case 1:
                total_sales();                                 // Call to display total sales
                break;
            case 2:
                replenishIngredients();                         // Call to replenish ingredients
                break;
            case 3:
                changeCoffeePrice();                           // Call to change coffee prices
                break;
            case 0:
                printf("Exiting admin mode.\n");              // Exit message
                return 0;                                      // Exit function
            default:
                printf("Invalid choice.\n");                  // Handle invalid choice
        }
    }    
}

// Apply a random discount to the coffee price

void applyRandomDiscount(float *price) {
    // Generate a random discount percentage between 0 and 20
    int discountPercentage = rand() % 21;                  // Generate random discount percentage
    float discountAmount = (*price * discountPercentage) / 100; // Calculate discount amount
    *price -= discountAmount;                                // Deduct discount from price

    printf("A random discount of %d%% has been applied! New price: %.2f AED\n", discountPercentage, *price); // Display new price
}

// Order coffee functionality

void order_coffee() {
    int option;                                          // Variable for coffee choice
    float price;                                        // Variable for price
    float payment = 0;                                  // Variable for total payment
    float coins;                                        // Variable for inserted coin value

    while (true) {                                      // Loop for ordering process
        // Display available coffee options
        if (availablecoffees(ESPRESSO_BEANS, ESPRESSO_WATER, 0, 0)) // Check availability of espresso
            printf("1. Espresso - %.2f AED\n", ESPRESSO_PRICE); // Display espresso option
        else
            printf("Espresso temporarily unavailable.\n"); // Unavailability message
        
        if (availablecoffees(CAPPUCCINO_BEANS, CAPPUCCINO_WATER, CAPPUCCINO_MILK, 0)) // Check availability of cappuccino
            printf("2. Cappuccino - %.2f AED \n", CAPPUCCINO_PRICE); // Display cappuccino option
        else
            printf("Cappuccino temporarily unavailable.\n"); // Unavailability message
        
        if (availablecoffees(MOCHA_BEANS, MOCHA_WATER, MOCHA_MILK, MOCHA_SYRUP)) // Check availability of mocha
            printf("3. Mocha - %.2f AED\n", MOCHA_PRICE); // Display mocha option
        else 
            printf("Mocha temporarily unavailable.\n"); // Unavailability message

        printf("0. Exit \n");                          // Exit option
        printf("Enter your choice (1/2/3/0): ");      // Prompt for coffee choice
        scanf("%d", &option);                          // Input coffee choice
        
        if (option == 0) return;                       // Exit the order process

        switch (option) {                              // Switch based on user choice
            case 1:
                if (!availablecoffees(ESPRESSO_BEANS, ESPRESSO_WATER, 0, 0)) { // Check availability
                    printf("Sorry, unavailable Espresso. Returning back...\n"); // Unavailability message
                    continue;                          // Retry order
                }
                price = ESPRESSO_PRICE;               // Set price for espresso
                break;
            case 2:
                if (!availablecoffees(CAPPUCCINO_BEANS, CAPPUCCINO_WATER, CAPPUCCINO_MILK, 0)) { // Check availability
                    printf("Sorry, unavailable Cappuccino. Returning back...\n"); // Unavailability message
                    continue;                          // Retry order
                }
                price = CAPPUCCINO_PRICE;              // Set price for cappuccino
                break;
            case 3:
                if (!availablecoffees(MOCHA_BEANS, MOCHA_WATER, MOCHA_MILK, MOCHA_SYRUP)) { // Check availability
                    printf("Sorry, unavailable Mocha. Returning back...\n"); // Unavailability message
                    continue;                          // Retry order
                }
                price = MOCHA_PRICE;                   // Set price for mocha
                break;
            default:
                printf("Invalid choice. Try again.\n"); // Handle invalid choice
                continue;                              // Retry order
        }

        // Apply random discount
        applyRandomDiscount(&price);                   // Apply discount to price

        printf("You selected: ");                      // Confirmation of selection
        switch(option) {                               // Switch based on coffee choice
            case 1: printf("Espresso"); break;        // Confirm espresso selection
            case 2: printf("Cappuccino"); break;      // Confirm cappuccino selection
            case 3: printf("Mocha"); break;           // Confirm mocha selection
        }
        printf(" Price: %.2f AED\n", price);          // Display final price
        printf("Confirm your selection (1 for Yes, 0 for No): "); // Prompt for confirmation
        int confirm;                                   // Variable for confirmation input
        scanf("%d", &confirm);                         // Input confirmation choice
        if (!confirm) continue;                        // Re-enter the order if not confirmed

        // Handle payment
        while (payment < price) {                     // Loop until total payment is sufficient
            printf("Insert coins (0.25, 0.5, or 1 AED). Remaining: %.2f AED\n", price - payment); // Prompt for coin insertion
            scanf("%f", &coins);                       // Input coin value  
            if (coins != 0.25 && coins != 0.5 && coins != 1) { // Validate coin value
                printf("Invalid coin. Please insert 0.25, 0.5, or 1 AED.\n"); // Error message
                continue;                              // Retry payment
            }
            payment += coins;                          // Add inserted coin to total payment  
        }

        // Update sold quantities
        switch (option) {                              // Switch based on coffee choice
            case 1: ESPRESSO_SOLD += 1; break;        // Increment espresso sold counter
            case 2: CAPPUCCINO_SOLD += 1; break;      // Increment cappuccino sold counter
            case 3: MOCHA_SOLD += 1; break;            // Increment mocha sold counter
        }

        // Use ingredients based on the coffee ordered
        switch (option) {                              // Switch based on coffee choice
            case 1:
                usedingredients(ESPRESSO_BEANS, ESPRESSO_WATER, 0, 0); // Use ingredients for espresso
                break;
            case 2:
                usedingredients(CAPPUCCINO_BEANS, CAPPUCCINO_WATER, CAPPUCCINO_MILK, 0); // Use ingredients for cappuccino
                break;
            case 3: 
                usedingredients(MOCHA_BEANS, MOCHA_WATER, MOCHA_MILK, MOCHA_SYRUP); // Use ingredients for mocha
                break;
        }
        
        total_amt += price;                          // Update total sales amount
        printf("\nEnjoy your ");                     // Message before serving
        switch (option) {                             // Switch based on coffee choice
            case 1: printf("Espresso"); break;      // Confirm espresso served
            case 2: printf("Cappuccino"); break;    // Confirm cappuccino served
            case 3: printf("Mocha"); break;         // Confirm mocha served
        }
        printf("!\n");
        printf("Price: %.2f AED\n", price);          // Display price
        printf("You paid: %.2f AED\n", payment);     // Display payment made
        
        checkingforlowquantities();                   // Check for low ingredients
        printf("\nDo you want to place another order? (1 for Yes, 0 for No): "); // Prompt for another order
        scanf("%d", &confirm);                        // Input for additional order
        if (!confirm) return;                        // Exit if the user does not want to order again
        payment = 0.0;                               // Reset payment for the next order
    }
}

int main() {
    int choice;                                   // Variable for main menu choice  
    srand(time(NULL));                            // Seed the random number generator for discounts

    while (1) {                                   // Infinite loop for the main menu
        // Main menu for user interaction
        printf("\nCoffee Machine\n");              // Display coffee machine title
        printf("1. Order a coffee\n");             // Option to order coffee
        printf("2. Admin mode\n");                 // Option for admin access
        printf("3. Exit\n");                       // Option to exit the program
        printf("Enter your choice (1/2/3): ");    // Prompt for choice
        scanf("%d", &choice);                      // Input user choice
        
        switch (choice) {                          // Switch based on user choice
            case 1:
                order_coffee();                    // Call to order coffee
                break;
            case 2:
                admin_mode();                      // Enter admin mode for managing the machine
                break;
            case 3:
                printf("Exiting Machine...\n");   // Exit message
                return 0;                          // Exit the program
            default:
                printf("Invalid choice. Please try again.\n"); // Handle invalid choice
        }
    }
    return 0;                                      // End of main function
}
