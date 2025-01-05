#include <stdio.h>
#include <string.h>

int isPalindrome(char *str, int start, int end)
{
    while (start < end)
    {
        if (str[start] != str[end])
        {
            return 0; // 不是回文
        }
        // 移动前后的两个指针来从外向内遍历
        start++;
        end--;
    }
    return 1; // 是回文
}

void findAndPrintLongestPalindrome(char *str)
{
    int len = strlen(str); // 获取输入字符串的长度
    int maxLen = 0;        // 用于记录最长回文字符串的长度
    int startIdx = 0;      // 记录最长回文字符串的起始索引
    int endIdx = 0;        // 记录最长回文字符串的结束索引

    for (int i = 0; i < len; i++)
    {
        for (int j = i; j < len; j++)
        {
            if (isPalindrome(str, i, j) && (j - i + 1) > maxLen)
            {
                //! 如果从索引 i 到 j 的部分是回文，并且长度大于之前找到的最长回文字符串的长度
                // 则更新最长回文字符串的信息
                maxLen = j - i + 1; // 更新最长回文字符串的长度
                startIdx = i;       // 更新最长回文字符串的起始索引
                endIdx = j;         // 更新最长回文字符串的结束索引
            }
        }
    }
    // 输出最长的回文部分
    for (int k = startIdx; k <= endIdx; k++)
    {
        printf("%c", str[k]); // 输出最长回文字符串的字符
    }
    printf("\n"); // 输出换行符
}

int main()
{
    char str[100];
    scanf("%s", str);
    findAndPrintLongestPalindrome(str);
    return 0;
}
