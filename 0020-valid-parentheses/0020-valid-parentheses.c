#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_STACK_SIZE 1<<20

typedef struct
{
    int data[MAX_STACK_SIZE];
    int top;
} stacktype;

void init(stacktype* s)
{
    s->top = -1;
}

int full(stacktype* s)
{
    return s->top == MAX_STACK_SIZE;
}

int empty(stacktype* s)
{
    return s->top == -1;
}

void push(stacktype* s, int item)
{
    if (full(s))
    {
        printf("overflow error occurred.\n");
        exit(1);
    }
    else
    {
        s->data[++(s->top)] = item;
    }
}

int pop(stacktype* s)
{
    if (empty(s))
    {
        printf("underflow error occurred.\n");
        exit(1);
    }
    else
    {
        return s->data[(s->top)--];
    }
}

bool isValid(const char* exp)
{
    stacktype s;
    init(&s);
    char ch, open_ch;
    int len = strlen(exp);

   for (int i = 0; i < len; i++)
    {
       ch = exp[i];
        switch (ch)
        {
        case '(':
        case '{':
        case '[':
            push(&s, ch);
            break;
        case ')':
        case '}':
        case ']':
            if (empty(&s)) return false;
            else
            {
                open_ch = pop(&s);
                if ((open_ch == '(' && ch != ')') ||
                    (open_ch == '{' && ch != '}') ||
                    (open_ch == '[' && ch != ']'))
                    return false;
                break;
            }
        }
    }
    while (!empty(&s)) return false;
    return true;
}
