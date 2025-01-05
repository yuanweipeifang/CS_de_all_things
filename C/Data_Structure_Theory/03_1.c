/*假设一个算术表达式中可以包含三种括号：圆括号“（ ”和“ ）”、方括号“ [ ”
和“ ] ”和花括号“{”和“}”，且这三种括号可按任意的次序嵌套使用
（如：…[…{…}…[…]…]…[…]…(…)…）。编写判别给定表达式中所含括号是否正确配对
出现的程序（已知表达式已存入数据元素为字符的顺序表中）。
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 定义了一个栈的结构体
typedef struct
{
    char *data;  // 栈内数据
    int top;     // 栈顶指针
    int maxSize; // 栈的最大容量
} Stack;
// 初始化栈，设置栈的最大大小为maxSize
void init(Stack *s, int maxSize)
{
    s->data = (char *)malloc(maxSize * sizeof(char)); // 为栈分配内存空间
    s->top = -1;                                      // 初始化栈顶指针为-1
    s->maxSize = maxSize;                             // 设置栈的最大大小
}

// 入栈操作，在栈顶添加元素c
void push(Stack *s, char c)
{
    // 判断栈是否已满
    if (s->top < s->maxSize - 1)
    {
        s->data[++(s->top)] = c; // 栈顶指针加一，并在新的栈顶位置添加元素c
    }
    else
    {
        exit(1); // 如果栈已满，则退出程序
    }
}

/* 从栈中弹出一个元素 */
char pop(Stack *s)
{
    /* 如果栈不为空 */
    if (s->top >= 0)
    {
        /* 返回栈顶元素并将栈顶指针减一 */
        return s->data[(s->top)--];
    }
    else
    {
        /* 如果栈为空，退出程序 */
        exit(1);
    }
}

// 判断栈是否为空
bool isEmpty(Stack *s)
{
    return s->top == -1;
}

// 判断两个括号是否配对
bool isPair(char left, char right)
{
    // 圆括号和方括号匹配
    return (left == '(' && right == ')') || (left == '[' && right == ']') || (left == '{' && right == '}');
}

// 判断表达式是否是合法的括号表达式
bool isBalanced(char *expression, int maxSize)
{
    Stack s;
    init(&s, maxSize);
    // 遍历表达式字符串
    for (int i = 0; expression[i] != '\0'; i++)
    {
        // 如果遇到左括号，入栈
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{')
        {
            push(&s, expression[i]);
        }
        // 如果遇到右括号，判断是否配对，配对则出栈，否则返回false
        else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}')
        {
            // 如果栈为空，则说明表达式中有多余的右括号，返回false
            if (isEmpty(&s) || !isPair(s.data[s.top], expression[i]))
            {
                free(s.data);
                return false;
            }
            else // 如果栈不为空，则出栈
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
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }

    return 0;
}
