/*3) Develop a menu driven Program in C for the following operations on STACK of Integers (Array Implementation of Stack with maximum size MAX)
a. Push an Element on to Stack
b. Pop an Element from Stack
c. Demonstrate how Stack can be used to check Palindrome
d. Demonstrate Overflow and Underflow situations on Stack
e. Display the status of Stack
f. Exit
Support the program with appropriate functions for each of the above operations.*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100

// Structure to represent a stack
struct Stack {
    int items[MAX];
    int top;
};

// Function to initialize stack
void initializeStack(struct Stack *s) {
    s->top = -1;
}

// Function to check if stack is full
bool isFull(struct Stack *s) {
    return s->top == MAX - 1;
}

// Function to check if stack is empty
bool isEmpty(struct Stack *s) {
    return s->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow!\n");
    } else {
        s->items[++(s->top)] = value;
        printf("Element %d pushed to stack.\n", value);
    }
}

// Function to pop an element from the stack
int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        return -1;
    } else {
        printf("Element %d popped from stack.\n", s->items[s->top]);
        return s->items[(s->top)--];
    }
}

// Function to check if a string is a palindrome
bool isPalindrome(char *str) {
    struct Stack s;
    initializeStack(&s);
    
    int len = strlen(str);
    int i;
    
    // Push half of the characters onto the stack
    for (i = 0; i < len / 2; i++) {
        push(&s, str[i]);
    }
    
    // Check if the string is palindrome
    for (i = (len + 1) / 2; i < len; i++) {
        if (str[i] != pop(&s)) {
            return false;
        }
    }
    
    return true;
}

// Function to display the status of the stack
void displayStack(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
    } else if (isFull(s)) {
        printf("Stack is full.\n");
    } else {
        printf("Stack contains %d elements.\n", s->top + 1);
        printf("Top element: %d\n", s->items[s->top]);
    }
}

int main() {
    struct Stack s;
    initializeStack(&s);

    int choice, element;
    char str[MAX];

    do {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Check Palindrome\n");
        printf("4. Display Stack Status\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &element);
                push(&s, element);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                printf("Enter a string: ");
                scanf("%s", str);
                if (isPalindrome(str)) {
                    printf("The string is a palindrome.\n");
                } else {
                    printf("The string is not a palindrome.\n");
                }
                break;
            case 4:
                displayStack(&s);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid choice.\n");
        }
    } while (choice != 5);

    return 0;
}
