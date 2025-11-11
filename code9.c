#include <stdio.h>

#define SIZE 7

int hash(int key) {
    return key % SIZE;
}

void insert(int table[], int key) {
    int index = hash(key);
    int start = index;

    while (table[index] != -1) {
        index = (index + 1) % SIZE;
        if (index == start) {
            printf("Hash table is full. Cannot insert %d\n", key);
            return;
        }
    }
    table[index] = key;
}

void display(int table[]) {
    printf("\nFinal Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (table[i] != -1)
            printf("Slot %d: %d\n", i, table[i]);
        else
            printf("Slot %d: NULL\n", i);
    }
}

int main() {
    int table[SIZE];
    int n, key;

    for (int i = 0; i < SIZE; i++)
        table[i] = -1;

    printf("Enter number of elements to insert: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(table, key);
    }

    display(table);
    return 0;
}