#include <stdio.h>
#define MAX 100

char queue[MAX];
int front = -1, rear = -1;

void insert(char ch) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    queue[++rear] = ch;
    printf("Inserted '%c' into queue\n", ch);
}

void delete() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return;
    }
    printf("Deleted '%c' from queue\n", queue[front++]);
    if (front > rear)
        front = rear = -1;
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue contents:\n");
    for (int i = front; i <= rear; i++)
        printf("%c ", queue[i]);
    printf("\n");
}

void demonstrateOverflowUnderflow() {
    rear = MAX - 1;
    insert('X'); 
    front = rear = -1;
    delete();    
}

int main() {
    int choice;
    char ch;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert an Element on to QUEUE\n");
        printf("2. Delete an Element from QUEUE\n");
        printf("3. Demonstrate Overflow and Underflow\n");
        printf("4. Display the status of QUEUE\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter character to insert: ");
                scanf(" %c", &ch);
                insert(ch);
                break;
            case 2:
                delete();
                break;
            case 3:
                demonstrateOverflowUnderflow();
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}