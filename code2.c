#include <stdio.h>
#include <string.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
    printf("%d pushed to stack\n", value);
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    printf("%d popped from stack\n", stack[top--]);
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack contents:\n");
    for (int i = top; i >= 0; i--)
        printf("%d\n", stack[i]);
}

void checkPalindrome() {
    char str[MAX], rev[MAX];
    int i, j;

    printf("Enter a string to check palindrome: ");
    scanf("%s", str);

    top = -1;
    for (i = 0; str[i] != '\0'; i++)
        push(str[i]);

    for (i = 0; str[i] != '\0'; i++)
        rev[i] = stack[top--];
    rev[i] = '\0';

    if (strcmp(str, rev) == 0)
        printf("Palindrome\n");
    else
        printf("Not a palindrome\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push an Element on to Stack\n");
        printf("2. Pop an Element from Stack\n");
        printf("3. Check Palindrome using Stack\n");
        printf("4. Demonstrate Overflow and Underflow\n");
        printf("5. Display Stack\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                checkPalindrome();
                break;
            case 4:
                top = MAX - 1;
                push(999); 
                top = -1;
                pop();     
                break;
            case 5:
                display();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}