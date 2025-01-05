#include <stdio.h>
int bp[1005] = {};

int main() {
	int m, k;
	scanf("%d %d", &m ,&k);
	int rear = 0, sum = 0;
	bp[k - 1] = 1;
	while (1) {
		sum = 0;
		// 循环数组
		for (int i = 0; i < k; ++i)
			sum += bp[(i + rear) % k];
		if (bp[rear] <= m && sum > m) break;
		bp[rear] = sum;
		rear = (rear + 1) % k;
	}
	for (int i = 0; i < k; ++i)
		printf("%d ", bp[(rear + i) % k]);
	printf("\n");
	return 0;
}
