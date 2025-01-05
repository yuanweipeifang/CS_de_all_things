#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node *next;
};

struct Node *creat(int *nums, int cnt)
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *front_p = head;
    struct Node *current_p = NULL;

    for (int i = 0; i < cnt; i++)
    {
        current_p = (struct Node *)malloc(sizeof(struct Node));
        current_p->value = nums[i];
        front_p->next = current_p;
        front_p = current_p;
    }

    front_p->next = NULL;
    return head;
}

int find_mid(struct Node *line)
{
    // start
    // 快慢指针法
    line = line->next;
    struct Node *fast = line;
    struct Node *slow = line;
    while (fast && fast->next)
    {
        if (fast->next->next == NULL)
        {
            return slow->next->value;
        }
        // 快指针走两步，比慢指针快一步
        fast = fast->next->next;
        slow = slow->next; // 1 2 3 4 5
    }
    return slow->value;
    // end
}

int main()
{
    int n, m;
    scanf("%d", &n);

    int a[100000];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    struct Node *line = creat(a, n);
    m = find_mid(line);
    printf("%d\n", m);
    return 0;
}