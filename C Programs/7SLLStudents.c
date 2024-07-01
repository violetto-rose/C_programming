/*7. Develop a menu driven Program in C for the following operations on Singly Linked List (SLL) of Student Data with the fields: USN, Name, Programme, Sem, PhNo
a. Create a SLL of N Students Data by using front insertion.
b. Display the status of SLL and count the number of nodes in it
c. Perform Insertion / Deletion at End of SLL
d. Perform Insertion / Deletion at Front of SLL(Demonstration of stack)
e. Exit*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int usn;
    char name[20];
    char branch[20];
    int semester;
    char phone[20];
} STUDENT;

typedef struct node {
    STUDENT data;
    struct node *next;
} NODE;

NODE* getnode(STUDENT item) {
    NODE *x = (NODE*)malloc(sizeof(NODE));
    if (x == NULL) {
        printf("Out of memory\n");
        exit(EXIT_FAILURE);
    }
    x->data = item;
    x->next = NULL;
    return x;
}

NODE* insert_front(STUDENT item, NODE *first) {
    NODE *temp = getnode(item);
    temp->next = first;
    return temp;
}

NODE* insert_rear(STUDENT item, NODE *first) {
    NODE *temp = getnode(item);
    if (first == NULL)
        return temp;
    NODE *cur = first;
    while (cur->next != NULL)
        cur = cur->next;
    cur->next = temp;
    return first;
}

NODE* delete_front(NODE *first) {
    if (first == NULL) {
        printf("Student list is empty\n");
        return NULL;
    }
    printf("Deleted student record: USN=%d\n", first->data.usn);
    NODE *temp = first->next;
    free(first);
    return temp;
}

NODE* delete_rear(NODE *first) {
    if (first == NULL) {
        printf("Student list is empty\n");
        return NULL;
    }
    if (first->next == NULL) {
        printf("Deleted student record: USN=%d\n", first->data.usn);
        free(first);
        return NULL;
    }
    NODE *cur = first, *prev = NULL;
    while (cur->next != NULL) {
        prev = cur;
        cur = cur->next;
    }
    printf("Deleted student record: USN=%d\n", cur->data.usn);
    free(cur);
    prev->next = NULL;
    return first;
}

void display(NODE *first) {
    int count = 0;
    if (first == NULL) {
        printf("Student list is empty\n");
        return;
    }
    NODE *cur = first;
    while (cur != NULL) {
        printf("%d\t%s\t%s\t%d\t%s\n", cur->data.usn, cur->data.name, cur->data.branch, cur->data.semester, cur->data.phone);
        cur = cur->next;
        count++;
    }
    printf("Number of students = %d\n", count);
}

int main() {
    NODE *first = NULL;
    int choice;
    STUDENT item;

    for (;;) {
        printf("\n1.Insert front\n2.Insert rear\n3.Delete front\n4.Delete rear\n5.Display\n6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter student details:\n");
                printf("USN: "); scanf("%d", &item.usn);
                printf("Name: "); scanf("%s", item.name);
                printf("Branch: "); scanf("%s", item.branch);
                printf("Semester: "); scanf("%d", &item.semester);
                printf("Phone: "); scanf("%s", item.phone);
                first = insert_front(item, first);
                break;

            case 2:
                printf("Enter student details:\n");
                printf("USN: "); scanf("%d", &item.usn);
                printf("Name: "); scanf("%s", item.name);
                printf("Branch: "); scanf("%s", item.branch);
                printf("Semester: "); scanf("%d", &item.semester);
                printf("Phone: "); scanf("%s", item.phone);
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

            case 6:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}