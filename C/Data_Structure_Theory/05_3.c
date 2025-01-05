#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义广义表结点结构体
typedef struct Node {
    int value;
    struct Node *next;
    struct Node *child;
} Node;

// 按表头分析方法求广义表深度的递归函数
int depth_head(Node *root) {
    if (root == NULL) {
        return 1;
    } else {
        int child_depth = depth_head(root->child);
        int next_depth = depth_head(root->next);
        return 1 + (child_depth > next_depth ? child_depth : next_depth);
    }
}

// 按表尾分析方法求广义表深度的递归函数
int depth_tail(Node *root) {
    if (root == NULL) {
        return 1;
    } else {
        int child_depth = depth_tail(root->child);
        int next_depth = depth_tail(root->next);
        return 1 + (child_depth > next_depth ? child_depth : next_depth);
    }
}

// 将输入字符串转换为广义表结点
Node *parse_input(char *input) {
    if (input[0] != '(') {
        Node *node = (Node *)malloc(sizeof(Node));
        node->value = input[0];
        node->next = NULL;
        node->child = NULL;
        return node;
    }

    Node *head = NULL;
    Node *tail = NULL;
    int i = 1;
    while (input[i] != ')') {
        if (input[i] == ',') {
            i++;
            continue;
        }
        if (input[i] == '(') {
            int count = 1;
            int j = i + 1;
            while (count > 0) {
                if (input[j] == '(') {
                    count++;
                } else if (input[j] == ')') {
                    count--;
                }
                j++;
            }
            Node *child = parse_input(input + i);
            if (head == NULL) {
                head = child;
                tail = child;
            } else {
                tail->next = child;
                tail = child;
            }
            i = j;
        } else {
            Node *node = (Node *)malloc(sizeof(Node));
            node->value = input[i];
            node->next = NULL;
            node->child = NULL;
            if (head == NULL) {
                head = node;
                tail = node;
            } else {
                tail->next = node;
                tail = node;
            }
            i++;
        }
    }
    return head;
}

int main() {
    char input[1024];
    scanf("%s", input);

    Node *root = parse_input(input);

    printf("%d\n", depth_head(root)+1);
    printf("%d\n", depth_tail(root)+1);

    // 释放广义表结点内存
    Node *curr = root;
    while (curr != NULL) {
        Node *next = curr->next;
        if (curr->child != NULL) {
            Node *child = curr->child;
            while (child != NULL) {
                Node *next_child = child->next;
                free(child);
                child = next_child;
            }
        }
        free(curr);
        curr = next;
    }

    return 0;
}
