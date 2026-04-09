#include <stdio.h>
#include <string.h>

#define MAX 100

struct Stack {
    char actions[MAX][100];
    int top;
};

// Initialize stack
void init(struct Stack *s) {
    s->top = -1;
}

// Push
void push(struct Stack *s, char action[]) {
    if (s->top < MAX - 1) {
        strcpy(s->actions[++s->top], action);
    }
}

// Pop
char* pop(struct Stack *s) {
    if (s->top >= 0) {
        return s->actions[s->top--];
    }
    return NULL;
}

// Display
void display(struct Stack *s) {
    printf("\n=========== CURRENT TASKS ===========\n");

    if (s->top == -1) {
        printf("No actions available\n");
    } else {
        for (int i = 0; i <= s->top; i++) {
            printf("%d. %s\n", i + 1, s->actions[i]);
        }
    }

    printf("====================================\n");
}

int main() {
    struct Stack undoStack, redoStack;
    init(&undoStack);
    init(&redoStack);

    int choice;
    char action[100];

    while (1) {
        printf("\n====================================\n");
        printf("        TASK MANAGER SYSTEM\n");
        printf("====================================\n");
        printf("1. Add Action\n");
        printf("2. Undo\n");
        printf("3. Redo\n");
        printf("4. Show Tasks\n");
        printf("5. Exit\n");
        printf("====================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear buffer

        switch (choice) {
            case 1:
                printf("Enter action: ");
                fgets(action, 100, stdin);
                action[strcspn(action, "\n")] = 0;

                push(&undoStack, action);
                init(&redoStack); // clear redo

                printf("Action added successfully!\n");
                break;

            case 2: {
                char *last = pop(&undoStack);
                if (last) {
                    push(&redoStack, last);
                    printf("Undo: %s\n", last);
                } else {
                    printf("Nothing to undo!\n");
                }
                break;
            }

            case 3: {
                char *redo = pop(&redoStack);
                if (redo) {
                    push(&undoStack, redo);
                    printf("Redo: %s\n", redo);
                } else {
                    printf("Nothing to redo!\n");
                }
                break;
            }

            case 4:
                display(&undoStack);
                break;

            case 5:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}