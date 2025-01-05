#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *left, *right;
    char ch;
} Node, Tree;

Node *newNode(char ch)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->ch = ch;
    node->left = node->right = NULL;
    return node;
}

Tree *createTree(void)
{
    char ch;
    scanf(" %c", &ch); // 注意空格，避免读取换行符
    if (ch == '#')
    {
        return NULL;
    }
    Node *curr = newNode(ch);
    curr->left = createTree();
    curr->right = createTree();
    return curr;
}

void printExpression(Tree *curr)
{
    if (curr == NULL)
    {
        return;
    }
    printExpression(curr->left);
    printf("%c", curr->ch);
    printExpression(curr->right);
}

int main()
{
    Tree *t = createTree();
    printExpression(t);
    printf("\n");
    return 0;
}
