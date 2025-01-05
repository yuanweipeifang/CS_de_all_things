/*
假设表达式由单字母变量和双目四则运算算符构成。
试编写程序，将一个通常书写形式且书写正确的表达式
转换为逆波兰式。*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// 定义堆栈结构
typedef struct
{
    char *data;
    int top;
    int capacity;
} Stack;

// 创建一个堆栈
Stack *createStack(int capacity)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));         // 分配堆栈内存
    stack->data = (char *)malloc(capacity * sizeof(char)); // 分配堆栈数据内存
    stack->top = -1;                                       // 初始化栈顶指针
    stack->capacity = capacity;                            // 设置堆栈容量
    return stack;                                          // 返回堆栈指针
}

// 释放堆栈内存
void freeStack(Stack *stack)
{
    free(stack->data);
    free(stack);
}

// 将元素压入堆栈
void push(Stack *stack, char c)
{
    stack->data[++stack->top] = c; // 压入栈顶
}

// 从堆栈中弹出元素
char pop(Stack *stack)
{
    return stack->data[stack->top--]; // 返回栈顶元素并将栈顶指针减一
}

// 判断字符是否为运算符
int isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
    {
        return 1;
    }
    return 0;
}

// 返回运算符的优先级
int precedence(char c)
{
    if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    return 0;
}

// 将中缀表达式转换为后缀表达式
void infixToPostfix(char *infix, char *postfix)
{
    Stack *stack = createStack(strlen(infix)); // 创建一个堆栈
    int i, j = 0;

    for (i = 0; infix[i]; i++)
    {
        if (infix[i] == '(')
        {
            push(stack, '('); // 左括号压入堆栈
        }
        else if (infix[i] == ')')
        {
            while (stack->top != -1 && stack->data[stack->top] != '(')
            {
                postfix[j++] = pop(stack); // 弹出堆栈直到遇到左括号
            }
            stack->top--; // 弹出左括号
        }
        else if (isOperator(infix[i]))
        {
            while (stack->top != -1 && precedence(stack->data[stack->top]) >= precedence(infix[i]))
            {
                postfix[j++] = pop(stack); // 弹出栈中优先级大于等于当前运算符的元素
            }
            push(stack, infix[i]); // 当前运算符入栈
        }
        else
        {
            postfix[j++] = infix[i]; // 操作数直接输出
        }
    }

    while (stack->top != -1)
    {
        postfix[j++] = pop(stack); // 弹出堆栈中所有元素
    }

    postfix[j] = '\0'; // 添加字符串结束标志

    freeStack(stack); // 释放堆栈内存
}

// 主函数
int main()
{
    char infix[MAX_SIZE];   // 定义中缀表达式数组
    char postfix[MAX_SIZE]; // 定义后缀表达式数组

    scanf("%s", infix); // 输入中缀表达式

    infixToPostfix(infix, postfix); // 将中缀表达式转换为后缀表达式

    printf("%s\n", postfix); // 输出后缀表达式

    return 0;
}