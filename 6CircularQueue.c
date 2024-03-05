/*6) Develop a menu driven Program in C for the following operations on Circular QUEUE of Characters (Array Implementation of Queue with maximum size MAX)
a. insert an Element on to Circular QUEUE.
b. Delete an Element from Circular QUEUE
c. Demonstrate Overflow and Underflow situations on Circular QUEUE
d. Display the status of Circular QUEUE e. Exit Support the program with appropriate functions for each of the above operations.*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

char CQ[SIZE];
int front = -1, rear = -1, ele, ch;

int IsFull() { return (front == (rear + 1) % SIZE); }
int IsEmpty() { return (front == -1); }

void insert(char item)
{
    if (IsEmpty())
        front = 0;
    rear = (rear + 1) % SIZE;
    CQ[rear] = item;
}

void delete()
{
    printf("Deleted element is: %c\n", CQ[front]);
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % SIZE;
}

void display()
{
    int i;
    if (IsEmpty())
        printf("Circular Queue is Empty\n");
    else
    {
        printf("Elements of the circular queue are: ");
        for (i = front; i != rear; i = (i + 1) % SIZE)
            printf("%c ", CQ[i]);
        printf("%c\n", CQ[i]);
    }
}

int main()
{
    printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
    while (1)
    {
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            if (IsFull())
                printf("Circular Queue Overflow\n");
            else
            {
                printf("Enter the element to be inserted: ");
                scanf(" %c", &ele);
                insert(ele);
            }
            break;
        case 2:
            if (IsEmpty())
                printf("Circular Queue Underflow\n");
            else
                delete ();
            break;
        case 3:
            if (IsEmpty())
                printf("Circular Queue Underflow\n");
            else
                display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
