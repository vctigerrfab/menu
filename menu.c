#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 10

struct MenuItem {
    char name[50];
    double price;
    int quantity; // Added the quantity field
};

void display_menu(struct MenuItem menu[], int num_items) {
    printf("Menu:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s: $%.2f\n", menu[i].name, menu[i].price);
    }
}

void take_order(struct MenuItem menu[], int num_items) {
    struct MenuItem order[MAX_ITEMS];
    int order_count = 0;

    char item[50];
    int quantity;

    while (1) {
        printf("Enter the item you want to order (or 'done' to finish): ");
        scanf("%s", item);

        if (strcmp(item, "done") == 0) {
            break;
        }

        int found = 0;
        for (int i = 0; i < num_items; i++) {
            if (strcmp(item, menu[i].name) == 0) {
                printf("How many %ss do you want to order? ", item);
                scanf("%d", &quantity);

                if (quantity <= 0) {
                    printf("Quantity must be greater than 0. Please enter a valid quantity.\n");
                } else {
                    strcpy(order[order_count].name, item);
                    order[order_count].price = menu[i].price;
                    order[order_count].quantity = quantity;
                    order_count++;
                    found = 1;
                    break;
                }
            }
        }

        if (!found) {
            printf("Invalid item. Please choose from the menu.\n");
            // Clear the input buffer to prevent infinite loop on invalid input
            while (getchar() != '\n');
        }
    }

    if (order_count > 0) {
        printf("\nOrder Summary:\n");
        double total = 0;
        for (int i = 0; i < order_count; i++) {
            printf("%s: %d\n", order[i].name, order[i].quantity);
            total += order[i].price * order[i].quantity;
        }

        printf("Total: $%.2f\n", total);
    } else {
        printf("No items ordered. Thank you for visiting!\n");
    }

    printf("Thank you for your order!\n");
}

int main() {
    // Sample menu. Replace this with your canteen's menu and prices.
    struct MenuItem menu[] = {
        { "burger", 5.00 },
        { "pizza", 8.50 },
        { "fries", 2.50 },
        { "drink", 1.50 }
    };

    int num_items = sizeof(menu) / sizeof(menu[0]);

    printf("Welcome to the canteen!\n");
    display_menu(menu, num_items);
    take_order(menu, num_items);

    return 0;
}

