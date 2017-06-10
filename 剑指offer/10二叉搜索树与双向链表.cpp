#include <iostream>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left, *right;

};

void CreateTree(TreeNode** pRoot,char ch[], int length);//����������
void print(TreeNode* pRoot);//���������ӡ������
void printList(TreeNode* pList);//��ӡ����
TreeNode* Convert(TreeNode* pRoot);//����������ת˫������
void ConvertTree(TreeNode* pRoot, TreeNode** pLastNodeInList);

int main_10()
{
	//char ch[] = { '10','6','4','#','#','8','#','#','14','12','16','#','#' };
	char ch[] = { '9','6','4','#','#','8','#','#','4','2','#','#','6','#','#' };//ǰ���������������
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
void CreateTree(TreeNode** pRoot,char ch[],int length)//ǰ���������������
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
void print(TreeNode *pRoot)//���������ӡ������
{
	if (pRoot==NULL)
	{
		return;
	}
	print(pRoot->left);

	cout << pRoot->val << "   ";

	print(pRoot->right);
}
void printList(TreeNode* pList)//��ӡ����
{
	TreeNode *pNode = pList;
	while (pNode!=NULL)
	{
		cout << pNode->val << "   ";
		pNode = pNode->right;
	}
	cout << endl;
}
TreeNode* Convert(TreeNode* pRoot)//����������ת˫������
{
	TreeNode* p = NULL;
	ConvertTree(pRoot, &p);
	TreeNode* pHead = p;
	while (pHead != NULL && pHead->left != NULL)//��βָ��ת��Ϊͷָ��
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

	pCurrent->left = *pLastNodeInList;//��һ�θ�ֵΪ�գ���Ϊͷָ��

	if (*pLastNodeInList != NULL)// ��Ϊ��ֵ��ʱ�򣬾�Ϊ��ǰָ���ǰһ��ָ��
	{
		(*pLastNodeInList)->right = pCurrent;
	}
	*pLastNodeInList = pCurrent;//pLastNodeInListһֱ����Ϊǰһ��ָ��

	if (pCurrent->right != NULL)
	{
		ConvertTree(pRoot->right, pLastNodeInList);
	}
}