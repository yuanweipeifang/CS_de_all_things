#include <stdio.h>
#include <string.h>

int firstUniqChar(char *s)
{
    int count[26] = {0};
    int len = strlen(s);

    for (int i = 0; i < len; i++)
    {
        count[s[i] - 'a']++; // 统计每个字母出现的次数
        // i表示字母，，count[s[i] - 'a']表示该字母出现的次数
        // 后面用count数组判断是否出现次数为1的字母
    }

    for (int i = 0; i < len; i++)
    {
        if (count[s[i] - 'a'] == 1) // 如果出现的次数为1，则返回该索引
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    char s[100];
    scanf("%s", s);

    int result = firstUniqChar(s);

    printf("%d\n", result);

    return 0;
}
