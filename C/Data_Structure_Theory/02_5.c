#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// 删除A表中既在B表又在C表中出现的元素
Node* deleteCommonElements(Node *A, Node *B, Node *C) {
    Node *p = A;
    Node *pre = NULL;
    
    while (p != NULL) {
        int data = p->data;
        Node *q = B;
        int foundB = 0;
        while (q != NULL) {
            if (q->data == data) {
                foundB = 1;
                break;
            }
            q = q->next;
        }
        
        if (foundB) {
            Node *r = C;
            int foundC = 0;
            while (r != NULL) {
                if (r->data == data) {
                    foundC = 1;
                    break;
                }
                r = r->next;
            }
            
            if (foundC) {
                if (pre == NULL) {
                    A = p->next;
                    free(p);
                    p = A;
                } else {
                    pre->next = p->next;
                    free(p);
                    p = pre->next;
                }
            } else {
                pre = p;
                p = p->next;
            }
        } else {
            pre = p;
            p = p->next;
        }
    }
    
    return A;
}

// 将链表逆序
Node* reverseList(Node *head) {
    Node *prev = NULL;
    Node *current = head;
    Node *next = NULL;
    
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    return prev;
}

// 打印链表
void printList(Node *head) {
    Node *p = head;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    int m, n, p;
    
    // 输入检测，确保输入合法
    while (scanf("%d %d %d", &m, &n, &p) != 3 || m <= 0 || n <= 0 || p <= 0) {
        while (getchar() != '\n'); // 清空输入缓冲区
    }
    
    Node *A = NULL;
    Node *B = NULL;
    Node *C = NULL;
    
    // 输入A表元素
    for (int i = 0; i < m; i++) {
        int data;
        scanf("%d", &data);
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = A;
        A = newNode;
    }
    
    // 输入B表元素
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = B;
        B = newNode;
    }
    
    // 输入C表元素
    for (int i = 0; i < p; i++) {
        int data;
        scanf("%d", &data);
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = C;
        C = newNode;
    }
    
    // 删除A表中既在B表又在C表中出现的元素
    A = deleteCommonElements(A, B, C);
    
    // 将A表逆序
    A = reverseList(A);
    
    // 输出A表
    printList(A);
    
    return 0;
}
