#include <stdio.h>
#include <stdlib.h>

// 定义二叉树结点
typedef struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// 根据前序序列和中序序列建立二叉树
TreeNode* buildTree(char* preorder, char* inorder, int preStart, int preEnd, int inStart, int inEnd) {
    if (preStart > preEnd || inStart > inEnd) {
        return NULL;
    }

    // 创建根结点
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->data = preorder[preStart];
    root->left = NULL;
    root->right = NULL;

    // 在中序序列中找到根结点的位置
    int rootIndex;
    for (int i = inStart; i <= inEnd; i++) {
        if (inorder[i] == root->data) {
            rootIndex = i;
            break;
        }
    }

    // 递归构建左子树和右子树
    root->left = buildTree(preorder, inorder, preStart + 1, preStart + (rootIndex - inStart), inStart, rootIndex - 1);
    root->right = buildTree(preorder, inorder, preStart + (rootIndex - inStart) + 1, preEnd, rootIndex + 1, inEnd);

    return root;
}

// 后序遍历二叉树
void postorderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%c", root->data);
}

int main() {
    char preorder[100];
    char inorder[100];

    // 读取前序序列和中序序列
    scanf("%s", preorder);
    scanf("%s", inorder);

    // 计算序列长度
    int len = 0;
    while (preorder[len] != '\0') {
        len++;
    }

    // 建立二叉树
    TreeNode* root = buildTree(preorder, inorder, 0, len - 1, 0, len - 1);

    // 后序遍历二叉树并输出结果
    postorderTraversal(root);
    printf("\n");

    return 0;
}
