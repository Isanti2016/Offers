#include <iostream>

using namespace std;

struct RandomListNode
{
	int label;
	RandomListNode* next;
};

void IniListNode(RandomListNode* root, int a[], int length);//创建链表,尾插法,没有头结点
void print(RandomListNode *root);//打印链表
RandomListNode* Clone(RandomListNode* pHead);//克隆链表主程序
void CloneList(RandomListNode* pHead);//复制结点
RandomListNode* ReconnectListNode(RandomListNode* pHead);//把A和A'分离，形成原链表，和复制后的链表
RandomListNode* ReconnectListNode_1(RandomListNode* pHead);//把A和A'分离，形成原链表，和复制后的链表,书上的方法

int main()//简单链表的复制
{
	int a[] = {1,2,3,4,5,6};
	RandomListNode* root=new RandomListNode;
	int length = sizeof(a) / sizeof(a[0]);
	IniListNode(root, a, length);//此处不用指向节点指针的指针就可以改变链表root，因为链表中没有头结点。
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

void IniListNode(RandomListNode* root,int a[],int length)//创建链表,尾插法,没有头结点
{
	//root = new RandomListNode;//放在main中，防止root未初始化，无法使用
	root->label = a[0];
	RandomListNode* r,*p;
	r = root;

	for (int i = 1; i < length;i++)
	{
		p = new RandomListNode;
		p->label = a[i];
		r->next=p;
		r = p;//r保存指向最后一个
	}
	r->next = NULL;
}
void print(RandomListNode *root)//打印链表
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
		RandomListNode *CloneNode = new RandomListNode;//创建新的节点用于复制
		CloneNode->label = pNode->label;
		CloneNode->next = pNode->next;

		pNode->next = CloneNode;//在A后面增加一个备份A->A'->B->B'->...
		pNode = CloneNode->next;
	}


}
// RandomListNode* ReconnectListNode(RandomListNode* pHead)//把A和A'分离，形成原链表，和复制后的链表
// {
// 	RandomListNode* pNode = pHead;
// 	RandomListNode* pCloneHead = NULL;
// 	RandomListNode* pCloneNode = NULL;
// 	if (pNode)//必须有判断，是为了给头指针赋值，用于返回
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
RandomListNode* ReconnectListNode_1(RandomListNode* pHead)//把A和A'分离，形成原链表，和复制后的链表,书上的方法
{
	RandomListNode* pNode = pHead;
	RandomListNode* pCloneHead = NULL;
	RandomListNode* pCloneNode = NULL;
	if (pNode)//必须有判断，是为了给头指针赋值，用于返回
	{
		pCloneHead = pNode->next;
		pCloneNode = pNode->next;

		pNode->next = pCloneNode->next;//已经更新到结点B
		pNode = pNode->next;
	}

	while (pNode)//B存在
	{
		pCloneNode->next = pNode->next;
		pCloneNode = pCloneNode->next;

		pNode->next = pCloneNode->next;
		pNode = pNode->next;

	}

	return pCloneHead;
}
