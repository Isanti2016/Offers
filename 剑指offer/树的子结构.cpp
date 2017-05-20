#include <iostream>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left, *right;
};
char *str = NULL;//二叉树数据用char* 存储
void CreateTree(TreeNode* *T)//前序遍历创建二叉树,用char字符串创建，char必须是全局遍历，不能作为参数，不然递归str会回退
{	
	if(*str!='\0')
	{ 
		if (*str == '#')
		{
			*T = NULL;
			str++;//str也要自动+1，指向下一位，而scanf读入时，只进不退
		}
		else
		{
			*T = (TreeNode*)malloc(sizeof(TreeNode));
			if (!*T)//分配内存出错
				exit(OVERFLOW);
			(*T)->val = (*str++) - '0';
			CreateTree(&(*T)->left);
			CreateTree(&(*T)->right);
		}
	}
}
void CreateBitTree(TreeNode* *T)//书上的创建二叉树，用控制台输入
{
	char ch;
	scanf("%c", &ch);//只能用字符输入，每次循环读入一个字符，scanf会不断把后面的字符读入，不能用字符串
	if (ch=='#')
	{
		*T = NULL;
	}
	else
	{
		*T = new TreeNode;//new返回一个指向所分对象的指针，堆中分配
		if (!*T)
		{
			exit(OVERFLOW);
		}
		(*T)->val = ch-'0';//必须为(*T)
		CreateBitTree(&(*T)->left);
		CreateBitTree(&(*T)->right);
	}

}
void PreOrderTraverse(TreeNode* T)//前序遍历二叉树
{
	if (!T)
		return;
	cout << T->val << "   ";
	PreOrderTraverse(T->left);
	PreOrderTraverse(T->right);
}

int main()
{
	str ="889##24##7##7##";
	TreeNode *T;
	CreateTree(&T);
	//CreateBitTree(&T);
	PreOrderTraverse(T);
	cout << endl;      
	return 0;
}