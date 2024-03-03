/*7. Develop a menu driven Program in C for the following operations on Singly Linked List (SLL) of Student Data with the fields: USN, Name, Programme, Sem, PhNo
a. Create a SLL of N Students Data by using front insertion.
b. Display the status of SLL and count the number of nodes in it
c. Perform Insertion / Deletion at End of SLL
d. Perform Insertion / Deletion at Front of SLL(Demonstration of stack)
e. Exit*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    int usn;
    char name[20];
    char branch[20];
    int semester;
    char phone[20];
}
STUDENT;
struct node
{
    int usn;
    char name[20];
    char branch[20];
    int semester;
    char phone[20];
    struct node *link;
};
typedef struct node *NODE;
NODE getnode()
{
    NODE x;
    x = (NODE)malloc(sizeof(struct node));
    if (x == NULL)
    {
        printf("Out of memory\n");
        exit(0);
    }
    return x;
}
NODE insert_front(STUDENT item, NODE first)
{
    NODE temp;
    temp = getnode();
    temp->usn = item.usn;
    strcpy(temp->name, item.name);
    strcpy(temp->branch, item.branch);
    temp->semester = item.semester;
    strcpy(temp->phone, item.phone);
    temp->link = NULL;
    if (first == NULL)
        return temp;
    temp->link = first;
    return temp;
}
NODE insert_rear(STUDENT item, NODE first)
{
    NODE temp, cur;
    temp = getnode();
    temp->usn = item.usn;
    strcpy(temp->name, item.name);
    strcpy(temp->branch, item.branch);
    temp->semester = item.semester;
    strcpy(temp->phone, item.phone);
    temp->link = NULL;
    if (first == NULL)
        return temp;
    cur = first;
    while (cur->link != NULL)
    {
        cur = cur->link;
    }
    cur->link = temp;
    return first;
}
NODE delete_front(NODE first)
{
    NODE temp;
    if (first == NULL)
    {
        printf("Student list is empty\n");
        return NULL;
    }
    temp = first;
    temp = temp->link;
    printf("Delete student record : USN=%d\n", first->usn);
    free(first); 
    return temp;
}
NODE delete_rear(NODE first)
{
    NODE cur, prev;
    if (first == NULL)
    {
        printf("Student list is empty cannot delete\n");
        return first;
    }
    if (first->link == NULL)
    {
        printf("Delete student record : USN=%d\n", first->usn);
        free(first);
        return NULL;
    }
    prev = NULL;
    cur = first;
    while (cur->link != NULL)
    {
        prev = cur;
        cur = cur->link;
    }
    printf("Delete student record:USN=%d\n", cur->usn);
    free(cur);
    prev->link = NULL;
    return first;
}
void display(NODE first)
{
    NODE cur;
    int count = 0;
    if (first == NULL)
    {
        printf("Student list is empty\n");
        return;
    }
    cur = first;
    while (cur != NULL)
    {
        printf("%d\t%s\t%s\t%d\t%s\t\n", cur->usn, cur->name, cur->branch, cur->semester, cur->phone);
        cur = cur->link;
        count++;
    }
    printf("Number of students=%d\n", count);
}
void main()
{
    NODE first;
    int choice;
    STUDENT item;
    first = NULL;
    for (;;)
    {
        printf("1.Insert front\n2.Insert rear\n3.Delete front\n4.Delete rear\n5.Display\n6.Exit\n");
        printf("Enter the choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("USN :\n");
            scanf("%d", &item.usn);
            printf("Name :\n");
            scanf("%s", item.name);
            printf("Branch :\n");
            scanf("%s", item.branch);
            printf("Semester:\n");
            scanf("%d", &item.semester);
            printf("Phone :\n");
            scanf("%s", item.phone);
            first = insert_front(item, first);
            break;
        case 2:
            printf("USN :\n");
            scanf("%d", &item.usn);
            printf("Name :\n");
            scanf("%s", item.name);
            printf("Branch :\n");
            scanf("%s", item.branch);
            printf("Semester:\n");
            scanf("%d", &item.semester);
            printf("Phone :\n");
            scanf("%s", item.phone);
            first = insert_rear(item, first);
            break;
        case 3:
            first = delete_front(first);
            break;
        case 4:
            first = delete_rear(first);
            break;
        case 5:
            display(first);
            break;
        default:
            exit(0);
        }
    }
}