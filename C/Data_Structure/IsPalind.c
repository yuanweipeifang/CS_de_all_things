#include <stdio.h>

// 判断一个数是否为回文数
int isPalindrome(int num)
{
    int reversedNum = 0;
    int originalNum = num;

    while (num > 0)
    {
        int remainder = num % 10;
        reversedNum = reversedNum * 10 + remainder;
        num /= 10;
    }

    return originalNum == reversedNum;
}

// 打印指定范围内的回文数
void printPalindromes(int start, int end)
{
    // printf("在范围[%d, %d]内的回文数有：\n", start, end);
    for (int i = start; i <= end; i++)
    {
        if (isPalindrome(i))
        {
            printf("%d\n", i);
        }
    }
}

int main()
{
    int start, end;
    scanf("%d %d", &start, &end);

    printPalindromes(start, end);

    return 0;
}
