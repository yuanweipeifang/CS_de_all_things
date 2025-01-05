// 二叉树的最简洁模板
// 需要时替换其中的某些字符即可
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
    scanf("%c", &c);
    if (c != '0')
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
        preorder(t->l);
        preorder(t->r);
        printf("%c", t->data);
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
