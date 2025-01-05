#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
} Node;

Node *creat(int *nums, int cnt)
{
	Node *head = (Node *)malloc(sizeof(Node));
	Node *front = head;
	Node *curr = NULL;
	for (int i = 0; i < cnt; i++)
	{
		curr = (Node *)malloc(sizeof(Node));
		curr->data = nums[i];
		front->next = curr;
		front = curr;
	}
	front->next = NULL;
	return head;
}

void print(Node *head)
{
	Node *curr = head->next;
	while (curr != NULL)
	{
		printf("%d ", curr->data);
		curr = curr->next;
	}
	printf("\n");
}

/// @brief 开始逆序输出链表
/// @param head 链表头指针
Node *reverseList(Node *head)
{
	// 此处p,q指针用于遍历链表，q指针用于记录下一个节点的位置
	Node *p = head->next;
	Node *q = NULL;
	// 将链表头指针指向最后一个节点
	head->next = NULL;
	while (p != NULL)
	{
		// 记录下一个节点的位置
		q = p->next;
		// 将当前节点的next指针指向前一个节点
		p->next = head->next;
		// 将链表头指针指向当前节点
		head->next = p;
		// 将p指针指向下一个节点
		p = q;
	}
	return head;
}

int main()
{
	int n;
	scanf("%d", &n);
	int a[1000];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	struct node *head = creat(a, n);
	print(reverseList(head));

	system("pause");
	return 0;
}