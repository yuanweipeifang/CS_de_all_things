#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1001

// 定义树节点结构体
typedef struct TreeNode
{
    int weight;                 // 权值
    int parent, lchild, rchild; // 父节点、左子节点、右子节点的下标
    char data;                  // 数据
} TreeNode, Tree[MAX];          // 树节点类型，定义一个最大数量为MAX的树数组

Tree tree;

// 定义哈夫曼编码结构体
typedef struct HuffmanCode
{
    int bit[200];              // 位串数组
    int start;                 // 起始位置
} HuffmanCode, CodeArray[100]; // 哈夫曼编码类型，定义一个最大数量为100的编码数组

CodeArray codes; // 定义哈夫曼编码数组

int encodedBits[1001] = {0}; // 存储编码后的比特串
int encodedLength = 0;       // 编码后的比特串长度

/*
选择最小的两个权值
n：表示哈夫曼树中节点的总数。
min1：用于存储最小的权值节点的下标。
min2：用于存储第二小的权值节点的下标。
*/
void selectMinWeights(int n, int *min1, int *min2)
{
    int left = MAX, right = MAX;
    for (int i = 1; i <= n; ++i)
    {
        if (tree[i].parent == 0) // 若节点没有父节点
        {
            if (tree[i].weight < left) //! 当前节点的权值小于左节点
            {
                right = left;          // 更新右节点的权值
                *min2 = *min1;         // 更新第二小的权值节点下标
                left = tree[i].weight; // 更新最小的权值
                *min1 = i;             // 更新最小的权值节点下标
            }
            else if (tree[i].weight < right) // 当前节点的权值小于右节点
            {
                right = tree[i].weight; // 更新右节点的权值
                *min2 = i;              // 更新第二小的权值节点下标
            }
        }
    }
}

// 初始化树
void initializeTree(int n)
{
    int min1, min2;

    // 为每个节点输入数据
    for (int i = 1; i <= n; i++)
    {
        getchar();
        scanf("%c", &tree[i].data);
    }

    // 为每个节点输入权值
    for (int i = 1; i <= n; i++)
    {
        if (scanf("%d", &tree[i].weight) != 1)
        {
            exit(1); // 如果输入无效则退出程序(加入错误处理)
        }
    }

    // 构建哈夫曼树
    for (int i = n; i < 2 * n - 1; i++)
    {
        selectMinWeights(i, &min1, &min2);                          // 选择最小的两个权值
        tree[i + 1].weight = tree[min1].weight + tree[min2].weight; // 设置父节点的权值为两个子节点权值之和
        tree[min1].parent = i + 1;                                  // 设置子节点的父节点为新添加的父节点
        tree[min2].parent = i + 1;                                  // 设置子节点的父节点为新添加的父节点
        tree[i + 1].lchild = min1;                                  // 设置新添加的父节点的左孩子为min1
        tree[i + 1].rchild = min2;                                  // 设置新添加的父节点的右孩子为min2
    }
}

// 生成Huffman编码
void generateHuffmanCodes(int n)
{
    for (int i = 1; i <= n; i++)
    {
        codes[i].start = n; // 初始化编码起始索引
        int current = i;
        int parent = tree[current].parent; // 获取当前节点的父节点
        // 遍历树以生成Huffman编码
        while (parent)
        {
            if (tree[parent].lchild == current)
                codes[i].bit[codes[i].start] = 0; // 如果当前节点是左子节点，则赋值为0
            else
                codes[i].bit[codes[i].start] = 1; // 如果当前节点是右子节点，则赋值为1
            codes[i].start--;                     // 移动到下一个索引
            current = parent;                     // 更新当前节点为其父节点
            parent = tree[current].parent;        // 更新父节点为其父节点
        }
        codes[i].start++;
    }
}

// 打印编码后的代码
void printEncodedCode(int n)
{
    encodedLength = 0;
    char code[1001];
    scanf("%s", code); // 读取输入的编码
    for (int i = 0; i < strlen(code); i++)
    { // 遍历输入的编码
        for (int j = 1; j <= n; j++)
        { // 遍历树中的节点
            if (code[i] == tree[j].data)
            {
                for (int k = codes[j].start; k <= n; k++)
                {                                                 // 遍历生成的Huffman编码
                    printf("%d", codes[j].bit[k]);                // 打印编码
                    encodedBits[encodedLength] = codes[j].bit[k]; // 存储编码
                    encodedLength++;                              // 更新编码长度
                }
            }
        }
    }
    printf("\n");
}

int main()
{
    int n;
    scanf("%d", &n); // 读取输入的节点数

    // 调用相关函数
    initializeTree(n);
    generateHuffmanCodes(n);
    printEncodedCode(n);

    //! 解码并打印
    int t;
    for (int i = 0; i < encodedLength;)
    {
        t = 2 * n - 1;
        while (tree[t].lchild != 0 && tree[t].rchild != 0)
        { // 遍历直到叶子节点
            if (encodedBits[i] == 0)
                t = tree[t].lchild; // 移动到左子节点
            else
                t = tree[t].rchild; // 移动到右子节点
            i++;
        }
        printf("%c", tree[t].data); // 打印解码后的字符
    }

    return 0;
}

/*
        100
       /    \
      b      60
            /  \
           e   (c+(d+a))
               /      \
              c       (d+a)
                      /  \
                     d    a

           100
          /    \
         b      60
               /  \
              e   35
                  /  \
                 c   20
                     /  \
                    d    a
*/

/*
开始
|
|--- 读取节点数n
|
|--- 初始化树
|     |
|     |--- 为每个节点输入数据和权值
|
|--- 构建哈夫曼树
|     |
|     |--- 选择最小的两个权值
|     |     |
|     |     |--- 遍历节点
|     |           |
|     |           |--- 如果节点没有父节点
|     |                 |
|     |                 |--- 如果当前节点的权值小于左节点
|     |                 |     |
|     |                 |     |--- 更新右节点的权值
|     |                 |     |--- 更新第二小的权值节点下标
|     |                 |     |--- 更新最小的权值
|     |                 |     |--- 更新最小的权值节点下标
|     |                 |
|     |                 |--- 如果当前节点的权值小于右节点
|     |                       |
|     |                       |--- 更新右节点的权值
|     |                       |--- 更新第二小的权值节点下标
|
|--- 生成Huffman编码
|     |
|     |--- 遍历节点
|           |
|           |--- 如果当前节点有父节点
|                 |
|                 |--- 如果当前节点是左子节点
|                 |     |
|                 |     |--- 赋值为0
|                 |
|                 |--- 如果当前节点是右子节点
|                       |
|                       |--- 赋值为1
|                       |
|                       |--- 移动到下一个索引
|                       |
|                       |--- 更新当前节点为其父节点
|                       |
|                       |--- 更新父节点为其父节点
|
|--- 读取输入的编码
|     |
|     |--- 遍历输入的编码
|           |
|           |--- 遍历树中的节点
|                 |
|                 |--- 如果当前编码与节点数据匹配
|                       |
|                       |--- 遍历生成的Huffman编码
|                             |
|                             |--- 打印编码
|                             |--- 存储编码
|                             |--- 更新编码长度
|
|--- 打印编码后的代码
|     |
|     |--- 遍历编码长度
|           |
|           |--- 遍历直到叶子节点
|                 |
|                 |--- 如果当前编码为0
|                 |     |
|                 |     |--- 移动到左子节点
|                 |
|                 |--- 如果当前编码为1
|                       |
|                       |--- 移动到右子节点
|                       |
|                       |--- 打印解码后的字符
|
|--- 结束


*/