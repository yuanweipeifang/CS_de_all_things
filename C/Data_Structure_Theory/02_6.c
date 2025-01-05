#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char data;
    struct node *pre, *next;
    int freq;
} Node, List;

List *init(int n)
{
    List *s = (List *)malloc(sizeof(List));
    Node *head = s;
    s->next = s, s->pre = s, s->data = ' ';
    s->freq = 0;
    for (int i = 0; i < n; i++)
    {
        char ch;
        scanf(" %c", &ch);
        Node *node = (Node *)malloc(sizeof(Node));
        node->data = ch;
        node->freq = 0;
        node->pre = head->pre;
        node->next = head;
        head->pre->next = node;
        head->pre = node;
    }
    return s;
}

void locate(List *s, char x)
{
    Node *curr = s->next; // 从链表的第一个节点开始遍历
    while (curr != s)
    { // 循环直到遍历到链表的末尾
        if (curr->data == x)
        {                          // 如果找到了与输入字符相同的节点
            curr->freq++;          // 将该节点的频率加一
            Node *tmp = curr->pre; // 用临时节点 tmp 来寻找合适的位置
            while (tmp != s && curr->freq > tmp->freq)
            { // 在链表中向前查找合适的位置
                tmp = tmp->pre;
            }
            if (curr != tmp->next)
            {   // 如果当前节点不在正确的位置
                // 以下是将当前节点移动到正确的位置
                curr->pre->next = curr->next;
                curr->next->pre = curr->pre;
                curr->pre = tmp;
                curr->next = tmp->next;
                tmp->next->pre = curr;
                tmp->next = curr;
            }
            break; // 找到目标节点后结束循环
        }
        curr = curr->next; // 继续遍历下一个节点
    }
}

void traverse(List *s)
{
    Node *curr = s->next;
    while (curr != s)
    {
        printf("%c ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    List *s = init(m);
    for (int i = 0; i < n; i++)
    {
        char x;
        scanf(" %c", &x);
        locate(s, x);
    }
    traverse(s);
    return 0;
}
