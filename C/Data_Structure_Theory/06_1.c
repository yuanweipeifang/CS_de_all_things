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
    node->ch = ch, node->left = node->right = NULL;
    return node;
}

Tree *createTree()
{
    char ch = getchar();
    Node *curr = newNode(ch);
    ch = getchar();
    if (ch == '(')
    {
        curr->left = createTree();
        curr->right = createTree();
    }
    else if (ch == ',')
    {
        curr->left = curr->right = NULL;
    }
    else if (ch == ')')
    {
        getchar();
        curr->left = curr->right = NULL;
    }
    return curr;
}

// Pre-order traversal of a binary tree
void preTraverse(Tree *root)
{
    if (root == NULL)
        return;
    printf("%c", root->ch);
    preTraverse(root->left);
    preTraverse(root->right);
}
int main()
{
    Tree *t = createTree();
    preTraverse(t);
    return 0;
}
