#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

// Stack implementation using array
int stack[MAX];
int top = -1;

void push(int value) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = value;
    }
}

int pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

int evaluatePostfix(char* expression) {
    int i = 0;
    char ch;
    int operand1, operand2, result;

    while (expression[i] != '\0') {
        ch = expression[i];

        if (isdigit(ch)) {
            // If the character is a digit, push it onto the stack
            push(ch - '0');
        } else {
            // If the character is an operator, pop two elements, apply the operator and push the result
            operand2 = pop();
            operand1 = pop();

            switch (ch) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Invalid operator\n");
                    return -1;
            }
            push(result);
        }
        i++;
    }
    return pop(); // The result is the only element left in the stack
}

void menu() {
    int choice;
    char expression[MAX];
    int result;

    do {
        printf("\nMenu:\n");
        printf("1. Evaluate Postfix Expression\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter postfix expression: ");
                scanf("%s", expression);
                result = evaluatePostfix(expression);
                printf("Result of postfix evaluation: %d\n", result);
                break;
            case 2:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 2);
}

int main() {
    menu();
    return 0;
}
