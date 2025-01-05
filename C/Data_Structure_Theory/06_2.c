#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *left, *right;
    char ch;
} Node, Tree;

Node *newNode(char ch) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->ch = ch;
    node->left = node->right = NULL;
    return node;
}

Tree *createTree(void) {
    char ch;
    scanf(" %c", &ch); // 注意空格，避免读取换行符
    if (ch == '#') {
        return NULL;
    }
    Node *curr = newNode(ch);
    curr->left = createTree();
    curr->right = createTree();
    return curr;
}

// 计算树的叶子节点数   
//! 注意：这里的叶子节点指的是没有子节点的节点，而不是空节点
// 空节点的子节点数为0，因此不算在叶子节点数中
// 空树的叶子节点数为0
// 因此，如果树的根节点为空，则返回0
// 否则，递归计算左右子树的叶子节点数，并返回两者之和
int countLeaves(Node *curr) {
    if (curr == NULL) {
        return 0;
    }
    if (curr->left == NULL && curr->right == NULL) {
        return 1;
    }
    return countLeaves(curr->left) + countLeaves(curr->right);
}

int main() {
    Tree *t = createTree();
    int leaves = countLeaves(t);
    printf("%d\n", leaves);
    return 0;
}
