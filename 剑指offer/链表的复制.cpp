#include <iostream>

using namespace std;

struct RandomListNode
{
	int label;
	RandomListNode* next;
};

void IniListNode(RandomListNode* root, int a[], int length);//��������,β�巨,û��ͷ���
void print(RandomListNode *root);//��ӡ����
RandomListNode* Clone(RandomListNode* pHead);//��¡����������
void CloneList(RandomListNode* pHead);//���ƽ��
RandomListNode* ReconnectListNode(RandomListNode* pHead);//��A��A'���룬�γ�ԭ�����͸��ƺ������
RandomListNode* ReconnectListNode_1(RandomListNode* pHead);//��A��A'���룬�γ�ԭ�����͸��ƺ������,���ϵķ���

int main()//������ĸ���
{
	int a[] = {1,2,3,4,5,6};
	RandomListNode* root=new RandomListNode;
	int length = sizeof(a) / sizeof(a[0]);
	IniListNode(root, a, length);//�˴�����ָ��ڵ�ָ���ָ��Ϳ��Ըı�����root����Ϊ������û��ͷ��㡣
	print(root);
	RandomListNode* result = Clone(root);
	if (result)
	{
		cout << "Clone ListNode:" << endl;
		print(result);
	}
	else
	{
		cout << "error in the Clone" << endl;
	}
	return 0;

}

void IniListNode(RandomListNode* root,int a[],int length)//��������,β�巨,û��ͷ���
{
	//root = new RandomListNode;//����main�У���ֹrootδ��ʼ�����޷�ʹ��
	root->label = a[0];
	RandomListNode* r,*p;
	r = root;

	for (int i = 1; i < length;i++)
	{
		p = new RandomListNode;
		p->label = a[i];
		r->next=p;
		r = p;//r����ָ�����һ��
	}
	r->next = NULL;
}
void print(RandomListNode *root)//��ӡ����
{
	RandomListNode* pNode=root;
	while (pNode)
	{
		cout << pNode->label << "   ";
		pNode = pNode->next;
	}
	cout << endl;
}
RandomListNode* Clone(RandomListNode* pHead)
{
	CloneList(pHead);

	//return ReconnectListNode(pHead);
	return ReconnectListNode_1(pHead);
}

void CloneList(RandomListNode* pHead)
{
	RandomListNode* pNode = pHead;
	while (pNode)
	{
		RandomListNode *CloneNode = new RandomListNode;//�����µĽڵ����ڸ���
		CloneNode->label = pNode->label;
		CloneNode->next = pNode->next;

		pNode->next = CloneNode;//��A��������һ������A->A'->B->B'->...
		pNode = CloneNode->next;
	}


}
// RandomListNode* ReconnectListNode(RandomListNode* pHead)//��A��A'���룬�γ�ԭ�����͸��ƺ������
// {
// 	RandomListNode* pNode = pHead;
// 	RandomListNode* pCloneHead = NULL;
// 	RandomListNode* pCloneNode = NULL;
// 	if (pNode)//�������жϣ���Ϊ�˸�ͷָ�븳ֵ�����ڷ���
// 	{
// 		pCloneHead = pNode->next;
// 		pCloneNode = pNode->next;
// 	}
// 
// 	while (pNode->next->next)
// 	{
// 		pNode->next = pNode->next->next;
// 		pNode = pNode->next;
// 
// 		pCloneNode->next = pCloneNode->next->next;	
// 		pCloneNode = pCloneNode->next;
// 
// 
// 	}
// 	return pCloneHead;
// }
RandomListNode* ReconnectListNode_1(RandomListNode* pHead)//��A��A'���룬�γ�ԭ�����͸��ƺ������,���ϵķ���
{
	RandomListNode* pNode = pHead;
	RandomListNode* pCloneHead = NULL;
	RandomListNode* pCloneNode = NULL;
	if (pNode)//�������жϣ���Ϊ�˸�ͷָ�븳ֵ�����ڷ���
	{
		pCloneHead = pNode->next;
		pCloneNode = pNode->next;

		pNode->next = pCloneNode->next;//�Ѿ����µ����B
		pNode = pNode->next;
	}

	while (pNode)//B����
	{
		pCloneNode->next = pNode->next;
		pCloneNode = pCloneNode->next;

		pNode->next = pCloneNode->next;
		pNode = pNode->next;

	}

	return pCloneHead;
}
