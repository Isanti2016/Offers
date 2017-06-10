#include <iostream>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left, *right;

};

void CreateTree(TreeNode** pRoot,char ch[], int length);//创建二叉树
void print(TreeNode* pRoot);//中序遍历打印二叉树
void printList(TreeNode* pList);//打印链表
TreeNode* Convert(TreeNode* pRoot);//二叉排序树转双向链表
void ConvertTree(TreeNode* pRoot, TreeNode** pLastNodeInList);

int main_10()
{
	//char ch[] = { '10','6','4','#','#','8','#','#','14','12','16','#','#' };
	char ch[] = { '9','6','4','#','#','8','#','#','4','2','#','#','6','#','#' };//前序遍历创建二叉树
	TreeNode* pRoot = NULL;
	int length = sizeof(ch) / sizeof(ch[0]);
	CreateTree(&pRoot, ch, length);
	cout << "print Tree:" << endl;
	print(pRoot);

	cout << endl;

	TreeNode* pHead=Convert(pRoot);
	cout << "print list:" << endl;
	printList(pHead);

	return 0;
}
int index = 0;
void CreateTree(TreeNode** pRoot,char ch[],int length)//前序遍历创建二叉树
{
	if (index < length)
	{
		if (ch[index] == '#')
		{
			index++;
			*pRoot=NULL;
		}
		else
		{
			*pRoot = new TreeNode;
			int num = 0;
			num = ch[index++] - '0';
			(*pRoot)->val = num;
			CreateTree(&(*pRoot)->left, ch, length);
			CreateTree(&(*pRoot)->right, ch, length);
		}

	}

}
void print(TreeNode *pRoot)//中序遍历打印二叉树
{
	if (pRoot==NULL)
	{
		return;
	}
	print(pRoot->left);

	cout << pRoot->val << "   ";

	print(pRoot->right);
}
void printList(TreeNode* pList)//打印链表
{
	TreeNode *pNode = pList;
	while (pNode!=NULL)
	{
		cout << pNode->val << "   ";
		pNode = pNode->right;
	}
	cout << endl;
}
TreeNode* Convert(TreeNode* pRoot)//二叉排序树转双向链表
{
	TreeNode* p = NULL;
	ConvertTree(pRoot, &p);
	TreeNode* pHead = p;
	while (pHead != NULL && pHead->left != NULL)//把尾指针转换为头指针
	{
		pHead = pHead->left;
	}
	return pHead;

}
void ConvertTree(TreeNode* pRoot, TreeNode** pLastNodeInList)
{
	if (pRoot == NULL)
	{
		return;
	}
	TreeNode* pCurrent = pRoot;

	if (pCurrent->left != NULL)
	{
		ConvertTree(pRoot->left, pLastNodeInList);
	}

	pCurrent->left = *pLastNodeInList;//第一次赋值为空，因为头指针

	if (*pLastNodeInList != NULL)// 不为空值的时候，就为当前指针的前一个指针
	{
		(*pLastNodeInList)->right = pCurrent;
	}
	*pLastNodeInList = pCurrent;//pLastNodeInList一直保存为前一个指针

	if (pCurrent->right != NULL)
	{
		ConvertTree(pRoot->right, pLastNodeInList);
	}
}