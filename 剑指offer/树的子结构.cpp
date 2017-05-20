#include <iostream>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left, *right;
};
char *str = NULL;//������������char* �洢
void CreateTree(TreeNode* *T)//ǰ���������������,��char�ַ���������char������ȫ�ֱ�����������Ϊ��������Ȼ�ݹ�str�����
{	
	if(*str!='\0')
	{ 
		if (*str == '#')
		{
			*T = NULL;
			str++;//strҲҪ�Զ�+1��ָ����һλ����scanf����ʱ��ֻ������
		}
		else
		{
			*T = (TreeNode*)malloc(sizeof(TreeNode));
			if (!*T)//�����ڴ����
				exit(OVERFLOW);
			(*T)->val = (*str++) - '0';
			CreateTree(&(*T)->left);
			CreateTree(&(*T)->right);
		}
	}
}
void CreateBitTree(TreeNode* *T)//���ϵĴ������������ÿ���̨����
{
	char ch;
	scanf("%c", &ch);//ֻ�����ַ����룬ÿ��ѭ������һ���ַ���scanf�᲻�ϰѺ�����ַ����룬�������ַ���
	if (ch=='#')
	{
		*T = NULL;
	}
	else
	{
		*T = new TreeNode;//new����һ��ָ�����ֶ����ָ�룬���з���
		if (!*T)
		{
			exit(OVERFLOW);
		}
		(*T)->val = ch-'0';//����Ϊ(*T)
		CreateBitTree(&(*T)->left);
		CreateBitTree(&(*T)->right);
	}

}
void PreOrderTraverse(TreeNode* T)//ǰ�����������
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