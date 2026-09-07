#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *last = NULL;
void insertBeginning(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;

    if (last == NULL) {
        newNode->next = newNode;
        last = newNode;
    } else {
        newNode->next = last->next;
        last->next = newNode;
    }

    printf("%d inserted at beginning.\n", value);
}

void insertEnd(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;

    if (last == NULL) {
        newNode->next = newNode;
        last = newNode;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }

    printf("%d inserted at end.\n", value);
}

void deleteBeginning() {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = last->next;

    if (last == temp) {
        last = NULL;
    } else {
        last->next = temp->next;
    }

    printf("%d deleted from beginning.\n", temp->data);
    free(temp);
}

void deleteEnd() {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = last->next;

    if (last == temp) {
        printf("%d deleted from end.\n", last->data);
        free(last);
        last = NULL;
        return;
    }

    while (temp->next != last) {
        temp = temp->next;
    }

    printf("%d deleted from end.\n", last->data);

    temp->next = last->next;
    free(last);
    last = temp;
}

void display() {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = last->next;

    printf("Circular Linked List: ");

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);

    printf("(back to first node)\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n----- Circular Linked List -----\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertBeginning(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;

            case 3:
                deleteBeginning();
                break;

            case 4:
                deleteEnd();
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Program ended.\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}