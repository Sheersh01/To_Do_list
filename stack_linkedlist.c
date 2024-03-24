#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
} *top = NULL;

void push(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Stack Overflow\n");
        return;
    }
    newNode->data = data;
    newNode->link = top;
    top = newNode;
    struct node* temp = top;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

void pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    int poppedData = top->data;
    struct node* temp = top;
    top = top->link;
    free(temp);
    printf("Popped Data %d\n", poppedData);
}

int main() {
    printf("Enter 0 to pop, 1 to push an element, and 2 to exit\n");
    int n;
    scanf("%d", &n);
    while (n != 2) {
        if (n == 0) {
           pop();
        }
        if (n == 1) {
            printf("Enter an element\n");
            int data;
            scanf("%d", &data);
            push(data);
        }
        printf("Enter 0 to pop, 1 to push an element, and 2 to exit\n");
        scanf("%d", &n); // Update the value of n for the next iteration
    }
    return 0;
}
