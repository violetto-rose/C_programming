/*5) Develop a Program in C for the following Stack Applications for evaluation of Suffix expression with single digit operands and operators: +, -, *, /, %, ^.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 20

struct stack {
    int top;
    float str[MAX];
} s; // stack

char postfix[MAX]; // postfix

void push(float x) {
    if (s.top == MAX - 1) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    else {
        s.top++;
        s.str[s.top] = x;
    }
}

float pop() {
    if (s.top == -1) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    else {
        float temp = s.str[s.top];
        s.top--;
        return temp;
    }
}

float operate(float op1, float op2, char a) {
    switch (a) {
        case '+':
            return op2 + op1;
        case '-':
            return op2 - op1;
        case '*':
            return op2 * op1;
        case '/':
            return op2 / op1;
        case '^':
            return pow(op2, op1);
        default:
            printf("Invalid operator\n");
            exit(EXIT_FAILURE);
    }
}

int isoperand(char x) {
    return (x >= '0' && x <= '9');
}

int main() {
    int i = 0;
    printf("Enter Expression: ");
    scanf("%s", postfix);
    float ans, op1, op2;
    
    // Initialize the stack
    s.top = -1;

    while (postfix[i] != '\0') {
        if (isoperand(postfix[i]))
            push((float)(postfix[i] - '0')); // Convert char to float
        else {
            op1 = pop();
            op2 = pop();
            ans = operate(op1, op2, postfix[i]);
            push(ans);
            printf("%f %c %f = %f\n", op2, postfix[i], op1, ans);
        }
        i++;
    }
    printf("Result: %f\n", s.str[s.top]);
    return 0;
}
