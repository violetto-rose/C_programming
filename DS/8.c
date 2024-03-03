#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Enode {
    char ssn[15];
    char name[20];
    char dept[5];
    char designation[10];
    int salary;
    long long int phno;
    struct Enode *left;
    struct Enode *right;
};

void create(char s[], char n[], char dpt[], char des[], int sal, long long int p) {
    struct Enode *temp;
    temp = (struct Enode *)malloc(sizeof(struct Enode));
    strcpy(temp->ssn, s);
    strcpy(temp->name, n);
    strcpy(temp->dept, dpt);
    strcpy(temp->designation, des);
    temp->salary = sal;
    temp->phno = p;
    temp->left = NULL;
    temp->right = NULL;
    if (head == NULL) head = tail = temp;
    else {
        tail->right = temp;
        temp->left = tail;
        tail = temp;
    }
}

void display() {
    struct Enode *temp;
    temp = head;
    printf("Employee Details \n");
    while (temp != NULL) {
        printf("\n%s\n%s\n%s\n%s\n%d\n%lld\n", temp->ssn, temp->name, temp->dept, temp->designation, temp->salary, temp->phno);
        temp = temp->right;
    }
}

void ins_beg(char s[], char n[], char dpt[], char des[], int sal, long long int p) {
    struct Enode *temp;
    temp = (struct Enode *)malloc(sizeof(struct Enode));
    strcpy(temp->ssn, s);
    strcpy(temp->name, n);
    strcpy(temp->dept, dpt);
    strcpy(temp->designation, des);
    temp->salary = sal;
    temp->phno = p;
    temp->right = head;
    head->left = temp;
    head = temp;
    temp->left = NULL;
}

void ins_end(char s[], char n[], char dpt[], char des[], int sal, long long int p) {
    struct Enode *temp;
    temp = (struct Enode *)malloc(sizeof(struct Enode));
    strcpy(temp->ssn, s);
    strcpy(temp->name, n);
    strcpy(temp->dept, dpt);
    strcpy(temp->designation, des);
    temp->salary = sal;
    temp->phno = p;
    tail->right = temp;
    temp->left = tail;
    temp->right = NULL;
    tail = temp;
}

void del_beg() {
    struct Enode *temp;
    temp = head->right;
    free(head);
    head = temp;
    head->left = NULL;
}

void del_end() {
    struct Enode *temp;
    temp = tail->left;
    free(tail);
    tail = temp;
    tail->right = NULL;
}

struct Enode *head = NULL, *tail = NULL;

int main() {
    int choice;
    char s[15], n[20], dpt[5], des[10];
    int sal;
    long long int p;
    printf("1.Create\n2.Display\n3.Insert at beginning\n4.Insert at End\n5.Delete at beginning\n6.Delete at End\n7.Exit\n");
    while (1) {
        printf("\nEnter your choice\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the required data(Emp no, Name, Dept, Designation, Salary, Phone)\n");
                scanf("%s%s%s%s%d%lld", s, n, dpt, des, &sal, &p);
                create(s, n, dpt, des, sal, p);
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Enter the required data(Emp no, Name, Dept, Designation, Salary, Phone)\n");
                scanf("%s%s%s%s%d%lld", s, n, dpt, des, &sal, &p);
                ins_beg(s, n, dpt, des, sal, p);
                break;
            case 4:
                printf("Enter the required data(Emp no, Name, Dept, Designation, Salary, Phone)\n");
                scanf("%s%s%s%s%d%lld", s, n, dpt, des, &sal, &p);
                ins_end(s, n, dpt, des, sal, p);
                break;
            case 5:
                del_beg();
                break;
            case 6:
                del_end();
                break;
            case 7:
                exit(0);
        }
    }
    return 0;
}
