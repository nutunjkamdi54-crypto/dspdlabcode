#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

int search(struct Node* root, int key) {
    if (root == NULL)
        return 0;
    if (root->data == key)
        return 1;
    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

struct Node* deleteLeaf(struct Node* root, int key) {
    if (root == NULL)
        return NULL;
    if (key < root->data)
        root->left = deleteLeaf(root->left, key);
    else if (key > root->data)
        root->right = deleteLeaf(root->right, key);
    else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } else {
            printf("Not a leaf node. Cannot delete.\n");
        }
    }
    return root;
}

int main() {
    struct Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Search an element in BST\n");
        printf("2. Insert an element in BST\n");
        printf("3. Delete leaf element in BST\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to search: ");
                scanf("%d", &value);
                if (search(root, value))
                    printf("Found\n");
                else
                    printf("NULL\n");
                break;
            case 2:
                printf("Enter element to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Inserted\n");
                break;
            case 3:
                printf("Enter leaf element to delete: ");
                scanf("%d", &value);
                root = deleteLeaf(root, value);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}