#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{						 // 定义Node节点
	char data;			 // data数据域
	struct Node *Lchild; // 左孩子
	struct Noed *Rchild; // 右孩子
} Node;

/* 创建树，这里使用二级指针
是因为当tree创建其左右孩子时需要使用到二级指针指向他们的数据域以及指针域*/
void creatTree(Node **tree, char *data, int *index)
{
	char temp;			 // temp用于保存data里面的数据
	temp = data[*index]; // index是为了方便对全局变量的操作
	*index += 1;		 //*index改变索引值
	if (temp == '#')	 // 如果temp值为#
	{
		*tree = NULL; // tree指向NULL
	}
	else
	{
		*tree = (Node *)malloc(sizeof(Node));		// 如果不等于#，则对其开辟空间保存
		(*tree)->data = temp;						/*data数据域进行赋值*/
		creatTree(&((*tree)->Lchild), data, index); // 创建树的左孩子，这里传入变量tree的指向的Lchild并且对其进行取地址符
		creatTree(&((*tree)->Rchild), data, index); // 如上使用遍历的方法进行创建
	}
}

void printf_preTree(Node *tree) // 前序遍历，先是根，然后是左孩子，最后是右孩子
{
	if (tree == NULL) // 如果指向NULL则直接返回
	{
		return;
	}
	else
	{
		printf("%c->", tree->data);	  // 先打印根的data
		printf_preTree(tree->Lchild); // 再使用遍历的方法对Lchild进行打印
		printf_preTree(tree->Rchild); // 如上打印Rchild
	}
}

void printf_ioTree(Node *tree) // 中序遍历，先是左孩子，然后就是根，再然后就是右孩子
{
	if (tree == NULL)
	{
		return -1;
	}
	else
	{
		printf_preTree(tree->Lchild); // 先找到最左的孩子
		printf("%c->", tree->data);	  // 然后打印data
		printf_preTree(tree->Rchild); // 再去打印根的孩子，最后会回到右孩子打印
	}
}

void printf_lastTree(Node *tree) // 尾序打印，先打印左孩子，再右孩子，最后就是根
{
	if (tree == NULL)
	{
		return;
	}
	else
	{
		printf_lastTree(tree->Lchild); // 找到左边的孩子
		printf_lastTree(tree->Rchild); // 找到右边的孩子
		printf("%c->", tree->data);	   // 打印右边的孩子
	}
}

int main(void)
{
	Node *tree;
	int index = 0;
	char data[100];	   // 增加一个数组用于接收用户输入的数据
	scanf("%s", data); // 读取用户输入的数据
	creatTree(&tree, data, &index);

	printf("前序遍历结果为：");
	printf_preTree(tree);
	printf("\n");

	printf("中序遍历结果为：");
	printf_ioTree(tree);
	printf("\n");

	printf("尾序遍历结果为：");
	printf_lastTree(tree);
	printf("\n");

	return 0;
}
