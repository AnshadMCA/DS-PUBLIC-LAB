#include <stdio.h>`
#define MAX 5

int queue[MAX], front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = value;
        printf("%d enqueued to queue\n", value);
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
    } else {
        printf("%d dequeued from queue\n", queue[front]);
        front++;
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Queue Elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;
    while (1) {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: 
                if (rear == MAX - 1) {
                    printf("Queue Overflow\n");
                } else {
                    printf("Enter the value to enqueue: ");
                    scanf("%d", &value);
                    enqueue(value);
                }
                break;
            case 2: 
                dequeue();
                break;
            case 3: 
                display();
                break;
            case 4: 
                return 0;
            default:
                printf("Invalid Choice!! Please enter a valid choice.\n");
        }
    }
    return 0;
}

