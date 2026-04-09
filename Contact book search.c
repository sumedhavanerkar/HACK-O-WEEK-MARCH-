#include <stdio.h>
#include <string.h>

#define MAX 100

struct Contact {
    char name[50];
    char phone[15];
};

// Sort contacts alphabetically
void sortContacts(struct Contact c[], int n) {
    struct Contact temp;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(strcmp(c[i].name, c[j].name) > 0) {
                temp = c[i];
                c[i] = c[j];
                c[j] = temp;
            }
        }
    }
}

// Binary search
int binarySearch(struct Contact c[], int n, char target[]) {
    int low = 0, high = n - 1;

    while(low <= high) {
        int mid = (low + high) / 2;
        int res = strcmp(c[mid].name, target);

        if(res == 0)
            return mid;
        else if(res < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    struct Contact contacts[MAX] = {
        {"Rahul", "9876543210"},
        {"Amit", "9123456780"},
        {"Sneha", "9988776655"},
        {"Kiran", "9012345678"}
    };

    int n = 4;

    // Sort contacts
    sortContacts(contacts, n);

    // Display sorted contacts
    printf("=========== CONTACT BOOK ===========\n");
    printf("       Sorted Contact List\n");
    printf("------------------------------------\n");

    for(int i = 0; i < n; i++) {
        printf("%d. %-8s : %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }

    printf("------------------------------------\n");

    // Search input
    char searchName[50];
    printf("\nEnter name to search: ");
    scanf("%s", searchName);

    int index = binarySearch(contacts, n, searchName);

    // Display result
    printf("\n=========== SEARCH RESULT ===========\n");

    if(index != -1) {
        printf("Contact Found!\n");
        printf("------------------------------------\n");
        printf("Name  : %s\n", contacts[index].name);
        printf("Phone : %s\n", contacts[index].phone);
    } else {
        printf("Contact Not Found!\n");
        printf("Please check the spelling.\n");
    }

    printf("\n------------------------------------\n");

    return 0;
}