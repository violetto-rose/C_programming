/*4) Develop a Program in C for converting an Infix Expression to Postfix Expression. Program should support for both parenthesized and free parenthesized expressions with the operators: +, -, *, /, % (Remainder), ^ (Power) and alphanumeric operands.*/

#include <stdio.h>
#include <ctype.h>

#define SIZE 50

char stack[SIZE];
int top = -1;

void push(char elem) {
    stack[++top] = elem;
}

char pop() {
    return stack[top--];
}

int precedence(char elem) {
    switch (elem) {
        case '(':
            return 1;
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
        case '%':
            return 3;
        case '^':
            return 4;
        default:
            return 0;
    }
}

int main() {
    char infix[50], postfix[50], ch;
    int i = 0, k = 0;

    printf("\nEnter the Infix Expression: ");
    scanf("%s", infix);

    push('(');

    while ((ch = infix[i++]) != '\0') {
        if (isalnum(ch))
            postfix[k++] = ch;
        else if (ch == '(')
            push(ch);
        else if (ch == ')') {
            while (stack[top] != '(')
                postfix[k++] = pop();
            pop(); /* Remove '(' */
        } else {
            while (precedence(stack[top]) >= precedence(ch))
                postfix[k++] = pop();
            push(ch);
        }
    }

    while (stack[top] != '(') /* Pop from stack till '(' */
        postfix[k++] = pop();
    postfix[k] = '\0'; /* Make postfix a valid string */

    printf("\nGiven Infix Expression: %s\nPostfix Expression: %s\n", infix, postfix);

    return 0;
}
