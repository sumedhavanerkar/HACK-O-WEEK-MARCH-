#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct PrintJob {
    int id;
    char name[50];
    int pages;
};

struct Queue {
    struct PrintJob jobs[MAX];
    int front, rear;
};

void init(struct Queue *q) {
    q->front = q->rear = -1;
}

int isEmpty(struct Queue *q) {
    return q->front == -1;
}

int isFull(struct Queue *q) {
    return q->rear == MAX - 1;
}

void enqueue(struct Queue *q, struct PrintJob job) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }

    if (isEmpty(q))
        q->front = 0;

    q->jobs[++q->rear] = job;
    printf("Job added to queue!\n");
}

void dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("No jobs in queue.\n");
        return;
    }

    struct PrintJob job = q->jobs[q->front];
    printf("\nProcessing Job...\n");
    printf("ID: %d\nName: %s\nPages: %d\n", job.id, job.name, job.pages);

    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
}

void display(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("\n--- Print Queue (FIFO) ---\n");
    for (int i = q->front; i <= q->rear; i++) {
        printf("\nID: %d\nName: %s\nPages: %d\n",
               q->jobs[i].id,
               q->jobs[i].name,
               q->jobs[i].pages);
    }
}

int main() {
    struct Queue q;
    struct PrintJob job;
    int choice;

    init(&q);

    while (1) {
        printf("\n===== Print Queue System =====\n");
        printf("1. Add Print Job\n");
        printf("2. Process Print Job\n");
        printf("3. View Queue\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter Job ID: ");
                scanf("%d", &job.id);
                getchar();

                printf("Enter Document Name: ");
                fgets(job.name, 50, stdin);
                job.name[strcspn(job.name, "\n")] = 0;

                printf("Enter Number of Pages: ");
                scanf("%d", &job.pages);

                enqueue(&q, job);
                break;

            case 2:
                dequeue(&q);
                break;

            case 3:
                display(&q);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}