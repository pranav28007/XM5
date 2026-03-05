#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void inorder(struct node* root) {

    struct node* stack[100];
    int top = -1;
    struct node* current = root;

    while (current != NULL || top != -1) {

        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];
        printf("%d ", current->data);

        current = current->right;
    }
}

int main() {

    int n, i, val;
    struct node* nodes[100];

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter node values:\n");

    for(i = 0; i < n; i++) {
        scanf("%d", &val);
        nodes[i] = createNode(val);
    }

    /* Creating simple binary tree structure */

    for(i = 0; i < n; i++) {

        int left = 2*i + 1;
        int right = 2*i + 2;

        if(left < n)
            nodes[i]->left = nodes[left];

        if(right < n)
            nodes[i]->right = nodes[right];
    }

    printf("Inorder Traversal: ");
    inorder(nodes[0]);

    return 0;
}

