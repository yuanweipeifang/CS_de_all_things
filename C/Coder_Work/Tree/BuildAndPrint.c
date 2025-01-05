#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char data;
    struct node *l, *r;
} *bitree, node;

void build(bitree *t)
{
    char c;
    scanf("%c ", &c);
    // 这里一定要注意好题目的样例是否包含了空格
    // 忽略空格可能会导致程序的严重错误
    if (c != '#')
    {
        *t = (bitree)malloc(sizeof(node));
        (*t)->data = c;
        build(&((*t)->l));
        build(&((*t)->r));
    }
    else
    {
        *t = NULL;
    }
}

// 前序遍历二叉树
void preorder(bitree t)
{
    if (t != NULL)
    {
        printf("%c ", t->data);
        preorder(t->l);
        preorder(t->r);
    }
    if (t == NULL)
    {
        return;
    }
}

int main()
{
    bitree t;
    build(&t);
    preorder(t);
    return 0;
}
