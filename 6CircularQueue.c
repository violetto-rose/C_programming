/*6) Develop a menu driven Program in C for the following operations on Circular QUEUE of Characters (Array Implementation of Queue with maximum size MAX)
a. insert an Element on to Circular QUEUE.
b. Delete an Element from Circular QUEUE
c. Demonstrate Overflow and Underflow situations on Circular QUEUE
d. Display the status of Circular QUEUE e. Exit Support the program with appropriate functions for each of the above operations.*/

#include <stdio.h>
#include <conio.h>
#define SIZE 5
int CQ[SIZE];
int front = -1;
int rear = -1, ch;
int IsFull();
int IsEmpty();
void insert(int);
void delete();
void display();
void main()
{
    printf("1.insert\n2.Delete\n3.Display\n4.Exit\n");
    while (1)
    {
        int ele;
        printf("Enter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            if (IsFull())
                printf("Circular Queu Overflow\n");
            else
            {
                printf("Enter the element to be inserted\n");
                scanf("%d", &ele);
                insert(ele);
            }
            break;
        case 2:
            if (IsEmpty())
                printf("Circular Queue Underflow\n");
            else
                delete();
            break;
        case 3:
            if (IsEmpty())
                printf("Circular Queue Underflow\n");
            else
                display();
            break;
        case 4:
            exit(0);
        }
    }
}
void insert(int item)
{
    if (front == -1)
        front++;
    rear = (rear + 1) % SIZE;
    CQ[rear] = item;
}
void delete()
{
    int item;
    item = CQ[front];
    printf("Deleted element is: %d", item);
    front = (front + 1) % SIZE;
}
void display()
{
    int i;
    if (front == -1)
        printf("Circular Queue is Empty\n");
    else
    {
        printf("Elements of the circular queue are..\n");
        for (i = front; i != rear;
             i = (i + 1) % SIZE)
            ;
        {
            printf("%d\t", CQ[i]);
        }
        printf("%d\n", CQ[i]);
    }
}
int IsFull()
{
    if (front == (rear + 1) % SIZE)
        return 1;
    return 0;
}
int IsEmpty()
{
    if (front == -1)
        return 1;
    else if (front == rear)
    {
        printf("Deleted element is: %d", CQ[front]);
        front = -1;
        return 1;
    }
    return 0;
}