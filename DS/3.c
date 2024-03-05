#include <stdio.h>
#include <stdbool.h>

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

// Function to check if stack elements form a palindrome
bool isPalindrome(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return false;
    }
    
    int temp[MAX];
    int i = 0;
    while (!isEmpty(s)) {
        temp[i++] = pop(s);
    }

    for (int j = 0; j < i / 2; j++) {
        if (temp[j] != temp[i - j - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    struct Stack s;
    initializeStack(&s);

    int choice, element;

    do {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Check if palindrome\n");
        printf("4. Exit\n");
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
                if (isPalindrome(&s)) {
                    printf("Stack elements form a palindrome.\n");
                } else {
                    printf("Stack elements do not form a palindrome.\n");
                }
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid choice.\n");
        }
    } while (choice != 4);

    return 0;
}