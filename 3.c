#include <stdio.h>
#include <stdlib.h>

#define MAX 3

int stack[MAX], top = -1;

void push(int x) {
    if (top == MAX - 1)
        printf("\nStack Overflow");
    else
        stack[++top] = x;
}

int pop() {
    if (top == -1) {
        printf("\nStack Underflow");
        return -1;
    }
    return stack[top--];
}

void display() {
    if (top == -1)
        printf("\nStack is Empty");
    else {
        printf("\nStack Elements:\n");
        for (int i = top; i >= 0; i--)
            printf("| %d |\n", stack[i]);
    }
}

void palindrome() {
    int flag = 1;
    for (int i = 0; i <= top / 2; i++) {
        if (stack[i] != stack[top - i]) {
            flag = 0;
            break;
        }
    }
    if (flag)
        printf("\nStack is Palindrome");
    else
        printf("\nStack is NOT Palindrome");
}

int main() {
    int ch, x;
    while (1) {
        printf("\n\n1.Push\n2.Pop\n3.Palindrome\n4.Display\n5.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            printf("Enter element: ");
            scanf("%d", &x);
            push(x);
            break;
        case 2:
            x = pop();
            if (x != -1) printf("Popped: %d", x);
            break;
        case 3:
            palindrome();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice");
        }
    }
}
