#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Stack {
    char urls[MAX][100];
    int top;
};

void init(struct Stack *s) {
    s->top = -1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

int isFull(struct Stack *s) {
    return s->top == MAX - 1;
}

void push(struct Stack *s, char url[]) {
    if (isFull(s)) {
        printf("Stack Overflow!\n");
        return;
    }
    strcpy(s->urls[++s->top], url);
}

void pop(struct Stack *s, char url[]) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        strcpy(url, "");
        return;
    }
    strcpy(url, s->urls[s->top--]);
}

void displayStack(struct Stack *s) {
    if (isEmpty(s)) {
        printf("(empty)\n");
        return;
    }
    for (int i = s->top; i >= 0; i--) {
        printf("%s\n", s->urls[i]);
    }
}

int main() {
    struct Stack backStack, forwardStack;
    char current[100] = "Home";
    char url[100];
    int choice;

    init(&backStack);
    init(&forwardStack);

    while (1) {
        printf("\n===== Browser Navigation =====\n");
        printf("1. Visit New URL\n");
        printf("2. Back\n");
        printf("3. Forward\n");
        printf("4. Show Current Page\n");
        printf("5. Show History\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter URL: ");
                fgets(url, 100, stdin);
                url[strcspn(url, "\n")] = 0;

                if (strcmp(current, url) != 0) {
                    push(&backStack, current);
                    strcpy(current, url);
                    init(&forwardStack); // clear forward history
                } else {
                    printf("Already on this page!\n");
                }
                break;

            case 2:
                if (!isEmpty(&backStack)) {
                    push(&forwardStack, current);
                    pop(&backStack, current);
                } else {
                    printf("No pages to go back.\n");
                }
                break;

            case 3:
                if (!isEmpty(&forwardStack)) {
                    push(&backStack, current);
                    pop(&forwardStack, current);
                } else {
                    printf("No pages to go forward.\n");
                }
                break;

            case 4:
                printf("Current Page: %s\n", current);
                break;

            case 5:
                printf("\n--- Back History ---\n");
                displayStack(&backStack);

                printf("\n--- Current Page ---\n%s\n", current);

                printf("\n--- Forward History ---\n");
                displayStack(&forwardStack);
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}