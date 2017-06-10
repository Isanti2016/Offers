#include <iostream>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left, *right;
};

void CreateTree(TreeNode* *T);//ǰ���������������,��char�ַ���������char������ȫ�ֱ�����������Ϊ��������Ȼ�ݹ�str�����
void CreateBitTree(TreeNode* *T);//���ϵĴ������������ÿ���̨����
void PreOrderTraverse(TreeNode* T);//ǰ�����������
bool IsSubTree(TreeNode* pRoot1, TreeNode* pRoot2);//�����жϺ������Ƿ����
bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2);//���õݹ飬Ѱ����������
char *str = NULL;//������������char* �洢




int main_6()
{
	//������
	str ="889##24##7##7##";//�����������������
	//str = "8898###32##4##7##7##";//IsSubTree�в���if (pRoot1==NULL)Խ������
	TreeNode *pRoot1;
	CreateTree(&pRoot1);
	//CreateBitTree(&T);
	cout << "parents:\t";
	PreOrderTraverse(pRoot1);
	cout << endl;

	//��������
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
void CreateTree(TreeNode* *T)//ǰ���������������,��char�ַ���������char������ȫ�ֱ�����������Ϊ��������Ȼ�ݹ�str�����
{
	if (*str != '\0')
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
	if (ch == '#')
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
		(*T)->val = ch - '0';//����Ϊ(*T)
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
bool IsSubTree(TreeNode* pRoot1, TreeNode* pRoot2)//�����жϺ������Ƿ����
{
	if (pRoot2 == NULL)//������ǰ��
		return true;
	if (pRoot1==NULL)//�����룬��Խ��,��pRoot1���������һ����pRoot2�����ʱ��pRoot1->left�������,//�����ں���
		return false;
	if (pRoot1->val == pRoot2->val)
		return IsSubTree(pRoot1->left, pRoot2->left) && IsSubTree(pRoot1->right, pRoot2->right);
	else
		return false;
}
bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)//���õݹ飬Ѱ����������
{
	bool result = false;
	if (pRoot2 == NULL)//�������κ�������������ǰ��
		return true;
	if (pRoot1 == NULL)//���������������ں���
		return false;

	if (pRoot1->val == pRoot2->val)
	{
		result = IsSubTree(pRoot1, pRoot2);//���뷵��һ��bool���ͽ�������ܾ����Ƿ��ٴα���pRoot1������
	}
	if (!result)//Ҫ�Ѳ������������������ֿ�����Ȼ�������ҵ��ˣ���Ҫ�����������ڲ���һ��
	{
		result=HasSubtree(pRoot1->left, pRoot2);
	}
	if (!result)
	{
		result=HasSubtree(pRoot1->right, pRoot2);
	}
	return result;
}