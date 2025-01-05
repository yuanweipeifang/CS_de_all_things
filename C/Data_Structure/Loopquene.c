#include <stdio.h>

int queue[1005] = {};
int rear = 0, len;

int main() {
	scanf("%d", &len);
	while(1) {
		scanf("%d", &queue[rear++]);
		char ch = getchar();
		if (ch == '\n') break;
	}

	if (rear >= len) { // 队满输出 yes
		printf("yes\n");
		rear = len;
	} else printf("no\n");

	int val, front = 0;
	scanf("%d", &val);
	while (front < rear && queue[front] != val) ++front;
	++front;

	for (int i = front; i < rear - 1; ++i) {
		printf("%d ", queue[i]);
    }
    // 会判空格与换行符
	printf("%d\n", queue[rear - 1]);
	printf("%d", queue[front]);
	return 0;
}