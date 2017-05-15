#include<iostream>
#include <Cstdlib>
#include<Ctime>

using namespace std;

struct ListNode
{
	int m_nValue;
	ListNode *m_pNext;
};

void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted);//删除结点
void CreateListTail(ListNode ** L, const int a[], int a_length);//尾插法创建链表
void PrintNode(ListNode* L);//打印整个链表
bool GetNode(const ListNode* L, int i, ListNode** Node);//获取结点， ListNode** Node必须定义指向节点的指针，才能返回结点
int main()
{
	int a[8] = {1,5,6,8,9,45,2,63};

	ListNode *L = (ListNode*)malloc(sizeof(ListNode));//为整个链表生成头结点
	L->m_nValue = 0;
	L->m_nValue = NULL;
	int a_length = sizeof(a) / sizeof(a[0]);
	CreateListTail(&L, a,a_length);
	PrintNode(L);

	ListNode *pToBeDeleted;
	if (GetNode(L, 3, &pToBeDeleted))
	{

//		cout << pToBeDeleted->m_nValue << endl;
//		cout << pToBeDeleted->m_pNext << endl;
		DeleteNode(&L, pToBeDeleted);
		PrintNode(L);
	}
	else
	{
		cout << "no the ListNode in the L" << endl;
	}
	 
	return 0;
}

void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted)
{
	if (pListHead==NULL||pToBeDeleted==NULL)
	{
		return;
	}
	
	if (pToBeDeleted->m_pNext!=NULL)//删除多个节点中，中间的节点
	{
		ListNode *p;
		p = pToBeDeleted->m_pNext;
		pToBeDeleted->m_nValue = p->m_nValue;
		pToBeDeleted->m_pNext = p->m_pNext;

		delete p;
		p = NULL;//删除指针后要释放
	}
	else if (*pListHead==pToBeDeleted)//仅有一个结点，删除头结点
	{
		delete pToBeDeleted;
		pToBeDeleted = NULL;

		*pListHead= NULL;//头结点指向空，为空链表
	}
	else   //多个节点中删除尾节点
	{
		ListNode *pNode=*pListHead;

		while (pNode->m_pNext!=pToBeDeleted)//寻找要删除节点的前一个节点
		{
			pNode=pNode->m_pNext;
		}
		pNode->m_nValue = NULL;

		delete pToBeDeleted;
		pToBeDeleted = NULL;

	}

}

void CreateListTail(ListNode ** L, const int a[],int a_length)//创建链表，尾插法
{
	ListNode *p, *r;

//	*L = (ListNode*)malloc(sizeof(ListNode));//为整个链表生成头结点
	r = *L;
	for (int i=0;i<a_length;i++)
	{
		p = (ListNode*)malloc(sizeof(ListNode));
		p->m_nValue = a[i];
		r->m_pNext = p;
		r = p;
	}
	r->m_pNext = NULL;
}
void PrintNode(ListNode* L)
{
	ListNode* p;
	p = L->m_pNext;
	while (p)
	{
		cout << p->m_nValue << " ";
		p = p->m_pNext;
	}
	cout << endl;
}

bool GetNode(const ListNode* L, int i, ListNode** Node)// ListNode** Node必须定义指向节点的指针，才能返回结点
{
	ListNode *p;
	int j=1;
	p = L->m_pNext;
	while (p&&j<i)
	{
		p = p->m_pNext;
		j++;
	}
	if (!p||j>i)
	{
		return false;
	}
	*Node = p;
	return true;
}