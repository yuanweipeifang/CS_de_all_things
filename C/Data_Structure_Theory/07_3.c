#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义栈结构
typedef struct Stack
{
    int top;
    unsigned capacity;
    char *array;
} Stack;

// 创建栈
Stack *createStack(unsigned capacity)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char *)malloc(stack->capacity * sizeof(char));
    return stack;
}

// 判断栈是否满
int isFull(Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

// 判断栈是否空
int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

// 入栈
void push(Stack *stack, char item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

// 出栈
char pop(Stack *stack)
{
    if (isEmpty(stack))
        return '\0';
    return stack->array[stack->top--];
}

// 获取栈顶元素
char peek(Stack *stack)
{
    if (isEmpty(stack))
        return '\0';
    return stack->array[stack->top];
}

// 判断运算符优先级
int precedence(char op)
{
    if (op == '+' || op == '-')
    {
        return 1;
    }
    else if (op == '*' || op == '/')
    {
        return 2;
    }
    return 0;
}

// 将中缀表达式转换为逆波兰表达式
void infixToPostfix(char *expression)
{
    Stack *stack = createStack(strlen(expression));
    char result[strlen(expression)];
    int idx = 0;

    for (int i = 0; i < strlen(expression); i++)
    {
        char c = expression[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            result[idx++] = c;
        }
        else if (c == '(')
        {
            push(stack, c);
        }
        else if (c == ')')
        {
            while (!isEmpty(stack) && peek(stack) != '(')
            {
                result[idx++] = pop(stack);
            }
            pop(stack); // 弹出 '('
        }
        else
        {
            while (!isEmpty(stack) && precedence(c) <= precedence(peek(stack)))
            {
                result[idx++] = pop(stack);
            }
            push(stack, c);
        }
    }

    while (!isEmpty(stack))
    {
        result[idx++] = pop(stack);
    }

    result[idx] = '\0';
    printf("%s\n", result);
}

int main()
{
    char expression[100];
    scanf("%s", expression);

    infixToPostfix(expression);

    return 0;
}
