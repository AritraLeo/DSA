#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Entering the elements into stack
void push(struct stack *ptr, char val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

// Deleting an element from the stack.
char pop(struct stack *st)
{
    char num;
    if (st->top == -1)
    {
        printf("\nStack underflow(i.e., stack empty).");
        return -1;
    }
    num = st->arr[st->top];
    st->top--;

    return num;
}

// Paranthesis match
int ParanthesisMatch(char *exp, int space)
{
    // Intializing stack
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = space;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(sp, '(');
        }

        else if (exp[i] == ')')
        {
            if (isEmpty(sp))
                return 0;

            pop(sp);
        }
    }
    if (isEmpty(sp))
        return 1;
    else
        return 0;
}

int main()
{

    char *exp = "(8 * 9)";
    int len = strlen(exp);
    // Checking match
    if (ParanthesisMatch(exp, len))
    {
        printf("The paranthesis is matched");
    }
    else
    {
        printf("The paranthesis is not matched");
    }

    return 0;
}
