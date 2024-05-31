#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<iostream>
using namespace std;
struct Node
{
    char data;
    struct Node *next;
} *top = 0;

void Push(char x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if (t == 0)
        printf("stack is full");

    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

char Pop()
{
    struct Node *t;
    char x = -1;
    if (top == 0)
        printf("stack is empty\n");
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

int IsOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == '(' || x == ')')
        return 0;
    return 1;
}

int OutStackPre(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x=='/')
        return 3;
    else if (x == '^')
        return 6;
    else if (x == '(')
        return 7;
    else if (x == ')')
        return 0;
    else
        return -1;
}

int InStackPre(char x)
{
    if (x == '+' || x == '-')
        return 2;
    else if (x == '*' || x=='/')
        return 4;
    else if (x == '^')
        return 5;
    else if (x == '(')
        return 0;
    else
        return -1;
}
char *InfixToPostfix(const char *infix)
{
    int i, j;
    i = j = 0;
    char *postfix;
    int len = strlen(infix);
    postfix = (char *)malloc(sizeof(char) * len + 2);

    while (infix[i] != '\0')
    {

        if (IsOperand(infix[i]))
            postfix[j++] = infix[i++];

        else
        {

            if (OutStackPre(infix[i]) > InStackPre(top->data)){
                Push(infix[i++]);}

            else if (OutStackPre(infix[i]) < InStackPre(top->data))
                postfix[j++] = Pop();
            else
            {
                Pop();
                i++;
            }
        }
    }
    while (top != 0)
        postfix[j++] = Pop();

    postfix[j] = '\0';

    return postfix;
}

int main()
{
    char *infix = "((a+b)*c)-d^e^f";
    char *postfix;
    Push('#');
    postfix = InfixToPostfix(infix);
    printf("%s",postfix);
    return 0;
}
