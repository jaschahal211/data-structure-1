#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Function prototypes
void push(char);
char pop();
int getPriority(char);
int isOperator(char);
void infixToPostfix(char[], char[]);
void prefixToPostfix(char[], char[]);
int evaluatePostfix(char[]);

int main() {
    int choice;
    char expression[MAX], result[MAX];

    while (1) {
        printf("\nMENU:\n");
        printf("1. Infix to Postfix\n");
        printf("2. Prefix to Postfix\n");
        printf("3. Postfix Evaluation\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // To capture the newline character after integer input

        switch (choice) {
            case 1:
                printf("Enter Infix Expression: ");
                fgets(expression, sizeof(expression), stdin);
                expression[strcspn(expression, "\n")] = '\0';  // Remove newline character
                infixToPostfix(expression, result);
                printf("Postfix Expression: %s\n", result);
                break;

            case 2:
                printf("Enter Prefix Expression: ");
                fgets(expression, sizeof(expression), stdin);
                expression[strcspn(expression, "\n")] = '\0';  // Remove newline character
                prefixToPostfix(expression, result);
                printf("Postfix Expression: %s\n", result);
                break;

            case 3:
                printf("Enter Postfix Expression: ");
                fgets(expression, sizeof(expression), stdin);
                expression[strcspn(expression, "\n")] = '\0';  // Remove newline character
                int result_val = evaluatePostfix(expression);
                printf("Postfix Evaluation Result: %d\n", result_val);
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Function to push to the stack
void push(char value) {
    if (top == MAX - 1) {
        printf("\nSTACK OVERFLOW\n");
        return;
    }
    stack[++top] = value;
}

// Function to pop from the stack
char pop() {
    if (top == -1) {
        printf("\nSTACK UNDERFLOW\n");
        return -1;
    }
    return stack[top--];
}

// Function to return the priority of operators
int getPriority(char ch) {
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '^') return 3;
    return 0;
}

// Function to check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Function to convert infix to postfix
void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char ch, temp;

    while (infix[i] != '\0') {
        ch = infix[i];

        if (isalnum(ch)) {
            postfix[j++] = ch;  // If it's an operand, add it to the result
        } else if (ch == '(') {
            push(ch);  // Push left parenthesis to the stack
        } else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();  // Pop until left parenthesis
            }
            pop();  // Pop the left parenthesis
        } else if (isOperator(ch)) {
            while (top != -1 && getPriority(stack[top]) >= getPriority(ch)) {
                postfix[j++] = pop();  // Pop operators of higher or equal precedence
            }
            push(ch);  // Push the current operator to the stack
        }
        i++;
    }

    // Pop all remaining operators from the stack
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';  // Null-terminate the postfix expression
}

// Function to convert prefix to postfix
void prefixToPostfix(char prefix[], char postfix[]) {
    int length = strlen(prefix);
    int i, j = 0;
    char ch;

    // Traverse the prefix expression from right to left
    for (i = length - 1; i >= 0; i--) {
        ch = prefix[i];

        if (isalnum(ch)) {
            postfix[j++] = ch;  // If it's an operand, add it to the result
        } else if (isOperator(ch)) {
            char op1 = pop();
            char op2 = pop();
            postfix[j++] = op2;
            postfix[j++] = op1;
            postfix[j++] = ch;
        }
    }
    postfix[j] = '\0';  // Null-terminate the postfix expression
}

// Function to evaluate a postfix expression
int evaluatePostfix(char postfix[]) {
    int i = 0, operand1, operand2, result;
    char ch;

    while (postfix[i] != '\0') {
        ch = postfix[i];

        if (isdigit(ch)) {
            push(ch - '0');  // Push the numeric value of the operand onto the stack
        } else if (isOperator(ch)) {
            operand2 = pop();
            operand1 = pop();
            switch (ch) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': result = operand1 / operand2; break;
                case '^': result = operand1 ^ operand2; break;
            }
            push(result);  // Push the result of the operation
        }
        i++;
    }
    return pop();  // The final result will be on top of the stack
}

