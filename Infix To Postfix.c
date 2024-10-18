#include <stdio.h>
#include <string.h>
#include <conio.h>
#define MAX 100

int top = -1;
char st[MAX];


void push(char st[], char val) {
    if (top == MAX - 1)
        printf("The stack is overflow\n");
    else {
        top++;
        st[top] = val;
    }
}


char pop(char st[]) {
    if (top == -1) {
        printf("The stack is underflow\n");
        return '\0';
    } else {
        char val = st[top];
        top--;
        return val;
    }
}


int getPriority(char op) {
    if (op == '/' || op == '*' || op == '%')
        return 1;
    else if (op == '+' || op == '-')
        return 0;
    return -1;
}


void InfixtoPostfix(char source[], char target[]) {
    int i = 0, j = 0;
    char temp;
    char stack[MAX];

    while (source[i] != '\0') {

        if ((source[i] >= 'a' && source[i] <= 'z') ||
            (source[i] >= 'A' && source[i] <= 'Z')) {
            target[j++] = source[i];
        }

        else if (source[i] == '(') {
            push(stack, source[i]);
        }

        else if (source[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                target[j++] = pop(stack);
            }
            pop(stack);
        }

        else {
            while (top != -1 && getPriority(stack[top]) >= getPriority(source[i])) {
                target[j++] = pop(stack);
            }
            push(stack, source[i]);
        }
        i++;
    }
  while (top != -1) {
        target[j++] = pop(stack);
    }

    target[j] = '\0';
}

int main() {
    char infix[100], postfix[100];
    printf("Enter the infix statement: ");
    gets(infix);
    strcpy(postfix, "");
    InfixtoPostfix(infix, postfix);
    printf("The postfix statement is: ");
    puts(postfix);
    getch();
    return 0;
}
