#include <stdio.h>
#include <stdlib.h>

/* Function Declarations */
void evaluate();
void push(char);
char pop();
int prec(char);

/* Global Variables */
char infix[30], postfix[30], stack[30];
int top = -1;

/* Main Function */
void main()
{
    printf("\nEnter the valid infix expression: ");
    scanf("%s", infix);

    evaluate();

    printf("\nThe entered infix expression is:\n%s\n", infix);
    printf("\nThe corresponding postfix expression is:\n%s\n", postfix);
}

/* Function to Convert Infix to Postfix */
void evaluate()
{
    int i = 0, j = 0;
    char symb, temp;

    push('#');

    for (i = 0; infix[i] != '\0'; i++)
    {
        symb = infix[i];

        switch (symb)
        {
        case '(':
            push(symb);
            break;

        case ')':
            temp = pop();
            while (temp != '(')
            {
                postfix[j++] = temp;
                temp = pop();
            }
            break;

        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '^':
        case '$':
            while (prec(stack[top]) >= prec(symb))
            {
                postfix[j++] = pop();
            }
            push(symb);
            break;

        default:
            postfix[j++] = symb;
        }
    }

    while (top > 0)
        postfix[j++] = pop();

    postfix[j] = '\0';
}

/* Push Operation */
void push(char item)
{
    stack[++top] = item;
}

/* Pop Operation */
char pop()
{
    return stack[top--];
}

/* Precedence Function */
int prec(char symb)
{
    switch (symb)
    {
    case '#': return -1;
    case '(':
    case ')': return 0;
    case '+':
    case '-': return 1;
    case '*':
    case '/':
    case '%': return 2;
    case '^':
    case '$': return 3;
    }
    return 0;
}
