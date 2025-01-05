#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int val;
	struct node *prev, *next;
} Node, List;

List* init(void) {
 	Node *s = (Node*) malloc(sizeof(Node));
	s->val = -1, s->prev = s->next = s;
	return s;
}

void pushBack(List *head, int val) {
	Node *curr = (Node*) malloc(sizeof(Node));
	curr->val = val, curr->prev = head->prev, curr->next = head;
	head->prev = head->prev->next = curr;
}

List* createList(size_t size, int val) {
	List *s = init();
	for (int i = 0; i < size; ++i) pushBack(s, val);
	return s;
}

void traverse_n(List *head, size_t cnt) {
	printf("%d.", head->next->val);
	for (Node* curr = head->next->next; curr != head && cnt > 0; curr = curr->next, --cnt)
		printf("%d", curr->val);
	printf("\n");
}

int main () {
	List *Rn = createList(550, 0);
	List *Sn = createList(550, 0);

	Rn->next->val = 2, Sn->next->val = 2;
	for (int n = 1; n <= 2000; ++n) {
		// R(n) = R(n) * n
		int carry = 0;
		for (Node *curr = Rn->prev; curr != Rn; curr = curr->prev) {
			int res = curr->val * n + carry;
			carry = res / 10; curr->val = res % 10;
		}

		// R(n) = R(n) / (2n + 1)
		carry = 0;
		for (Node *curr = Rn->next; curr != Rn; curr = curr->next) {
			int div = (n << 1) + 1;
			int res = curr->val + carry * 10;
			curr->val = res / div; carry = res - curr->val * div;
		}

		// S(n) += R(n)
		carry = 0;
		for (Node *curr1 = Sn->prev, *curr2 = Rn->prev; curr1 != Sn && curr2 != Rn;
		curr1 = curr1->prev, curr2 = curr2->prev) {
			int res = curr1->val + curr2->val + carry;
			curr1->val = res % 10; carry = res / 10;
		}
	}

	int cnt;
	scanf("%d", &cnt);
	traverse_n(Sn, cnt);
	return 0;
}
