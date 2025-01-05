#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct DNode {
    int data;
    struct DNode* prior, * next;
}DNode, * DoubleList;

void CreatHead(DoubleList* S) {
    (*S) = (DNode*)malloc(sizeof(DNode));
    (*S)->prior = NULL;
    (*S)->next = NULL;
}

int items(int n) {
    int i = 1;
    double sum = 0;
    int a, b;
    for (;; i++) {
        a = 2 * i + 1;
        b = i;
        sum = sum + log10(a / b);
        if (sum > n + 1) {
            return i;
        }
    }
}

void insert(DoubleList a,int b) {//双向链表的插入或者可以说是双向链表的初始化，即将双向链表的数据域中插入值
    DoubleList p, tmp;
    int i;
    p = a;
    //在这个函数中运用的是尾插的方法来进行插入的操作
    for (i = 0; i < 600; i++) {
        tmp = (DNode*)malloc(sizeof(DNode));
        tmp->data = b;
        tmp->prior = p;
        p->next = tmp;
        p = tmp;
    }
    p->next = NULL;
}

void display(DoubleList a, int m) {//这个函数用来输出题目索要我们输出的值
    DoubleList p;
    p = a->next;
    printf("%d.", p->data);
    p = p->next;
    for (int i = 1; i <= m; i++) {//此处的m为我们要输出的小数的位数
        printf("%d", p->data);
//如果下一个结点不为空的话，就继续输出，如果为空，则跳出循环，直接结束
        if (p->next) {
            p = p->next;
        }
        else {
            break;
        }
    }
    printf("\n");
}

int main() {
    int n, k;
    scanf("%d", &n);//输入所要求输出的位数
    k = items(n);//算出递推中大概要递推多少次
    DoubleList num, sum;//num用来计算每一次R(n)的值，sum用来保存计算出来的所有R(n)做和得到的值，即我们最后输出时要用的值
    CreatHead(&num);
    CreatHead(&sum);
    DoubleList p1, p2;//定义两个新的双向链表来指向num和sum两个链表
    insert(num,0);
    insert(sum,0);
    p1 = num->next;
    p2 = sum->next;
    //首先将num的数值域赋成R(1)的值，方便后续的递推，并计算出第一个sum的值
    p1->data = 1;
    p2->data = 2;
    DoubleList numtail, sumtail;
    //两个while循环来将p1和p2指向num和sum的尾结点处
    while (p1->next) {
        p1 = p1->next;
    }
    numtail = p1;//numtail指向最后一个结点
    while (p2->next) {
        p2 = p2->next;
    }
    sumtail = p2;//sumtail指向最后一个结点
    int i;
    int temp = 0;
    int ret;
    int t;
    for (i = 1, t = 3; i <= k; i++, t = t + 2) {//这里求解派的值运用的公式为反三角函数的幂次展开式
        p1 = numtail;
        ret = 0;//用ret来保存每一次的进位或者进行除法之后剩余的数
        while (p1 != num) {//首先计算R(n)*n，每个链表的结点都只保存了一个10进制的数，所以乘法和除法可以像手算一样一个数一个数相乘在相加
            temp = p1->data * i + ret;//这里从最后一个数来进行计算，因为乘法是向前在进位
            ret = temp / 10;
            temp = temp % 10;//留下这个结点所要保存的数值
            p1->data = temp;
            p1 = p1->prior;
        }
        ret = 0;//重新置为0，方便后续的运算
        p1 = num->next;
        while (p1) {//此处计算[R(n)*n]/(2n+1)中的除法
            temp = p1->data + ret * 10;
            //此处的ret要乘上10，因为这里我们是从前往后在进行除法，前一位不能除尽得到的余数到了后一位是要乘上10才能用的
            ret = temp % t;
            temp = temp / t;
            p1->data = temp;
            p1 = p1->next;//此处因为是从前往后算，所以结束循环的条件是指针指向空指针的时候，也就表示着计算的结束
        }
        ret = 0;
        //加法要从后往前算，因为加法可能会向前进位，所以这里要从后向前算
        p1 = numtail;
        p2 = sumtail;
        //加法的操作与乘法大致相同，只是运用了两个指针，一个用来指向num，一个用来指向储存结果的sum链表
        while (p1 != num && p2 != sum) {//此处其实可以只写一个，这样写只是为了防止在创建链表的时候，所创建的长度不同，导致程序的崩溃
            temp = p1->data * 2 + p2->data + ret;
            ret = temp / 10;
            temp = temp % 10;
            p2->data = temp;
            p1 = p1->prior, p2 = p2->prior;
        }
    }
    display(sum, n);//按照题目输出指定小数位数的派值了即可
    return 0;
}
