#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Item {
    int id;
    char name[50];
    float price;
    int quantity;
};

struct Item cart[MAX];
int count = 0;

void addItem() {
    if (count >= MAX) {
        printf("Cart is full!\n");
        return;
    }

    printf("Enter Item ID: ");
    scanf("%d", &cart[count].id);

    printf("Enter Item Name: ");
    getchar();
    fgets(cart[count].name, 50, stdin);
    cart[count].name[strcspn(cart[count].name, "\n")] = 0;

    printf("Enter Price: ");
    scanf("%f", &cart[count].price);

    printf("Enter Quantity: ");
    scanf("%d", &cart[count].quantity);

    count++;
    printf("Item added to cart!\n");
}

void displayCart() {
    if (count == 0) {
        printf("Cart is empty.\n");
        return;
    }

    float total = 0;
    printf("\n--- Shopping Cart ---\n");

    for (int i = 0; i < count; i++) {
        float itemTotal = cart[i].price * cart[i].quantity;
        total += itemTotal;

        printf("\nID: %d\nName: %s\nPrice: %.2f\nQuantity: %d\nTotal: %.2f\n",
               cart[i].id,
               cart[i].name,
               cart[i].price,
               cart[i].quantity,
               itemTotal);
    }

    printf("\nGrand Total: %.2f\n", total);
}

void removeItem() {
    int id, found = 0;
    printf("Enter Item ID to remove: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (cart[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                cart[j] = cart[j + 1];
            }
            count--;
            printf("Item removed successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Item not found.\n");
    }
}

void updateQuantity() {
    int id, found = 0;
    printf("Enter Item ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (cart[i].id == id) {
            printf("Enter new quantity: ");
            scanf("%d", &cart[i].quantity);
            printf("Quantity updated!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Item not found.\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Shopping Cart Menu ---\n");
        printf("1. Add Item\n");
        printf("2. View Cart\n");
        printf("3. Remove Item\n");
        printf("4. Update Quantity\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addItem(); break;
            case 2: displayCart(); break;
            case 3: removeItem(); break;
            case 4: updateQuantity(); break;
            case 5: exit(0);
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}