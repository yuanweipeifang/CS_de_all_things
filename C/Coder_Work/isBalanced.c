#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    char *data;
    int top;
    int max;
} Stack; // 定义栈的结构

void init(Stack *s, int max)
{
    s->data = (char *)malloc(sizeof(char) * max); // 申请栈的关键字节
    s->top = -1;                                  // 定义栈顶指针
    s->max = max;                                 // 栈是否未满
}

void push(Stack *s, char c)
{
    if (s->top < s->max - 1)
    {
        s->data[++(s->top)] = c; // 将关键字位置填入字符并将栈顶指针加一
    }
    else
    {
        exit(1);
    }
    return;
}

char pop(Stack *s)
{
    if (s->top >= 0)
    {
        return s->data[(s->top)--]; // 将栈顶指针减一并且弹出对应字符
    }
    else
    {
        exit(1);
    }
}
bool isEmpty(Stack *s)
{
    return s->top == -1; // 就看栈顶指针是否为-1
}
bool isPair(char left, char right)
{
    return (left == '(' && right == ')') || (left == '[' && right == ']') || (left == '{' && right == '}');
} // 观察左右括号是否匹配成功
bool isBalanced(char *expression, int max)
{
    Stack s;
    init(&s, max);
    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{')
        {
            push(&s, expression[i]);
        }
        else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}')
        {
            if (isEmpty(&s) || !isPair(s.data[s.top], expression[i]))
            {
                free(s.data);
                return false;
            }
            else
            {
                pop(&s);
            }
        }
    }

    free(s.data);
    return isEmpty(&s);
}
int main()
{
    int maxSize = 100;
    char expression[maxSize];
    fgets(expression, maxSize, stdin);

    if (isBalanced(expression, maxSize))
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }

    return 0;
}
