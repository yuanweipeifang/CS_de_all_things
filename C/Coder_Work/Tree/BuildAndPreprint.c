#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义节点结构
typedef struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
} Node;

// 根据先序遍历结果构建树
// 传入参数：先序遍历结果字符串preorder，指向当前字符的指针index
// 返回值：构建好的树的根节点
Node *buildTree(char *preorder, int *index)
{
    // 如果当前字符为'0'或者到达字符串末尾，则返回空节点
    if (preorder[*index] == '0' || preorder[*index] == '\0')
    {
        (*index)++; // 指向下一个字符
        return NULL;
    }

    // 分配内存创建新节点
    Node *newNode = (Node *)malloc(sizeof(Node));
    // 读取节点数据
    newNode->data = preorder[*index];
    // 指向下一个字符
    (*index)++;

    // 递归构建左子树和右子树
    newNode->left = buildTree(preorder, index);
    newNode->right = buildTree(preorder, index);

    return newNode;
}

// 先序遍历二叉树
void inorderTraversal(Node *root, char *result, int *index)
{
    if (root == NULL)
    {
        return;
    }

    // 将节点数据存入结果数组
    result[(*index)++] = root->data;

    // 递归遍历左子树和右子树
    inorderTraversal(root->left, result, index);
    inorderTraversal(root->right, result, index);
}

// 主函数
int main()
{
    char preorder[100];
    scanf("%s", preorder);

    int index = 0;
    // 构建树
    Node *root = buildTree(preorder, &index);

    char result[100];
    int resultIndex = 0;
    // 先序遍历并将结果存入result数组
    inorderTraversal(root, result, &resultIndex);
    result[resultIndex] = '\0';

    // 输出先序遍历结果
    printf("%s\n", result);

    return 0;
}