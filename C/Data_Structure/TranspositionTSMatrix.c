#include <stdio.h>
#include <stdlib.h>

#define ok 1
#define error 0
#define max 1000

typedef struct
{
    int hang;
    int lie;
    int data;
} seq;

void zhuanzhi(seq zzj[], int j) // 矩阵转置,i个元素
{
    int i;
    for (i = 0; i < j; i++)
    {
        int a;
        a = zzj[i].hang;
        zzj[i].hang = zzj[i].lie;
        zzj[i].lie = a; // 行列互换
    }
    for (int j = 0; j < i - 1; j++) // 冒泡排序将转置矩阵按照行序排列
        for (int m = 0; m < i - 1 - j; m++)
        {
            if (zzj[m].hang > zzj[m + 1].hang)
            {
                seq t;
                t = zzj[m], zzj[m] = zzj[m + 1], zzj[m + 1] = t;
            }
        }
}
void shuchu(seq zzj[], int j) // 矩阵输出.j个元素
{
    for (int i = 0; i < j; i++)
    {
        printf("%d ", zzj[i].hang);
        printf("%d ", zzj[i].lie);
        printf("%d ", zzj[i].data);
        printf("\n");
    }
}
int main()
{
    int m, n;
    scanf("%d", &m);
    scanf("%d", &n);
    seq zzj[m * n];   // 申请一个含有m*n个元素的数组
    int i;            // 元素个数
    for (i = 0;; i++) // 输入数组
    {
        int a, b, c;

        scanf("%d", &a);
        getchar();
        scanf("%d", &b);
        getchar();
        scanf("%d", &c);
        if (a == 0 && b == 0 && c == 0)
            break;
        zzj[i].hang = a;
        zzj[i].lie = b;
        zzj[i].data = c;
    }

    zhuanzhi(zzj, i);
    shuchu(zzj, i);
    return 0;
}
