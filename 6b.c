#include <stdio.h>
#include <stdlib.h>

#define MAX 5

char cq[MAX];
int front = -1, rear = -1;

void Insert(char item) {
    if ((rear + 1) % MAX == front) {
        printf("\n--Circular Queue Overflow--\n");
    } else {
        if (front == -1) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX;
        }
        cq[rear] = item;
        printf("\nInserted element: %c\n", item);
    }
}

void delete() {
    if (front == -1) {
        printf("\n--Circular Queue Underflow--\n");
    } else {
        char item = cq[front];
        printf("\nDeleted element: %c\n", item);
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }
}

void display() {
    if (front == -1) {
        printf("\nCircular Queue is Empty\n");
    } else {
        printf("\nCircular Queue contents are:\n");
        int i = front;
        while (i != rear) {
            printf("%c ", cq[i]);
            i = (i + 1) % MAX;
        }
        printf("%c ", cq[rear]);
        printf("\n");
    }
}

int main() {
    int ch;
    char item;

    while (1) {
        printf("\n--Main Menu--");
        printf("\n1. Insertion and Overflow Demo");
        printf("\n2. Deletion and Underflow Demo");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter Your Choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\nEnter the element to be inserted: ");
                scanf(" %c", &item);
                Insert(item);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nPlease enter a valid choice\n");
        }
    }

    return 0;
}

