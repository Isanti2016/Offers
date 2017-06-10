#include <iostream>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left, *right;
};

void CreateTree(TreeNode* *T);//前序遍历创建二叉树,用char字符串创建，char必须是全局遍历，不能作为参数，不然递归str会回退
void CreateBitTree(TreeNode* *T);//书上的创建二叉树，用控制台输入
void PreOrderTraverse(TreeNode* T);//前序遍历二叉树
bool IsSubTree(TreeNode* pRoot1, TreeNode* pRoot2);//用于判断和子树是否相等
bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2);//利用递归，寻找树的子树
char *str = NULL;//二叉树数据用char* 存储




int main_6()
{
	//创建树
	str ="889##24##7##7##";//正常包含子树的情况
	//str = "8898###32##4##7##7##";//IsSubTree中不含if (pRoot1==NULL)越界的情况
	TreeNode *pRoot1;
	CreateTree(&pRoot1);
	//CreateBitTree(&T);
	cout << "parents:\t";
	PreOrderTraverse(pRoot1);
	cout << endl;

	//创建子树
	str = "89##2##";
	TreeNode *pRoot2;
	CreateTree(&pRoot2);
	cout << "child:\t";
	PreOrderTraverse(pRoot2);
	cout << endl; 

	if (HasSubtree(pRoot1, pRoot2))
	{
		cout << "parents pRoot1 has child pRoot2" << endl;
	}
	else
		cout << "NULL" << endl;
	


	return 0;
}
void CreateTree(TreeNode* *T)//前序遍历创建二叉树,用char字符串创建，char必须是全局遍历，不能作为参数，不然递归str会回退
{
	if (*str != '\0')
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
	if (ch == '#')
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
		(*T)->val = ch - '0';//必须为(*T)
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
bool IsSubTree(TreeNode* pRoot1, TreeNode* pRoot2)//用于判断和子树是否相等
{
	if (pRoot2 == NULL)//必须在前面
		return true;
	if (pRoot1==NULL)//不加入，会越界,如pRoot1左子树最后一个和pRoot2根相等时，pRoot1->left会出问题,//必须在后面
		return false;
	if (pRoot1->val == pRoot2->val)
		return IsSubTree(pRoot1->left, pRoot2->left) && IsSubTree(pRoot1->right, pRoot2->right);
	else
		return false;
}
bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)//利用递归，寻找树的子树
{
	bool result = false;
	if (pRoot2 == NULL)//空树是任何数的子树，在前面
		return true;
	if (pRoot1 == NULL)//空树不含子树，在后面
		return false;

	if (pRoot1->val == pRoot2->val)
	{
		result = IsSubTree(pRoot1, pRoot2);//必须返回一个bool类型结果，才能决定是否再次遍历pRoot1的子树
	}
	if (!result)//要把查找左子树和右子树分开，不然左树中找到了，还要在右子树中在查找一遍
	{
		result=HasSubtree(pRoot1->left, pRoot2);
	}
	if (!result)
	{
		result=HasSubtree(pRoot1->right, pRoot2);
	}
	return result;
}