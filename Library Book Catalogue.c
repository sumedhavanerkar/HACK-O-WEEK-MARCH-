#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Book {
    int id;
    char title[50];
    char author[50];
};

struct Book library[MAX];
int count = 0;

void addBook() {
    if (count >= MAX) {
        printf("Library is full!\n");
        return;
    }

    printf("Enter Book ID: ");
    scanf("%d", &library[count].id);

    printf("Enter Title: ");
    getchar();
    fgets(library[count].title, 50, stdin);
    library[count].title[strcspn(library[count].title, "\n")] = 0;

    printf("Enter Author: ");
    fgets(library[count].author, 50, stdin);
    library[count].author[strcspn(library[count].author, "\n")] = 0;

    count++;
    printf("Book added successfully!\n");
}

void displayBooks() {
    if (count == 0) {
        printf("No books in library.\n");
        return;
    }

    printf("\nLibrary Catalogue:\n");
    for (int i = 0; i < count; i++) {
        printf("\nID: %d\nTitle: %s\nAuthor: %s\n",
               library[i].id,
               library[i].title,
               library[i].author);
    }
}

void searchBook() {
    int id, found = 0;
    printf("Enter Book ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (library[i].id == id) {
            printf("\nBook Found:\n");
            printf("ID: %d\nTitle: %s\nAuthor: %s\n",
                   library[i].id,
                   library[i].title,
                   library[i].author);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }
}

void deleteBook() {
    int id, found = 0;
    printf("Enter Book ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (library[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                library[j] = library[j + 1];
            }
            count--;
            printf("Book deleted successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Library Menu ---\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Delete Book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: deleteBook(); break;
            case 5: exit(0);
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}