#include<iostream>
#include <Cstdlib>
#include<Ctime>

using namespace std;

struct ListNode
{
	int m_nValue;
	ListNode *m_pNext;
};

void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted);//ɾ�����
void CreateListTail(ListNode ** L, const int a[], int a_length);//β�巨��������
void PrintNode(ListNode* L);//��ӡ��������
bool GetNode(const ListNode* L, int i, ListNode** Node);//��ȡ��㣬 ListNode** Node���붨��ָ��ڵ��ָ�룬���ܷ��ؽ��
int main()
{
	int a[8] = {1,5,6,8,9,45,2,63};

	ListNode *L = (ListNode*)malloc(sizeof(ListNode));//Ϊ������������ͷ���
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
	
	if (pToBeDeleted->m_pNext!=NULL)//ɾ������ڵ��У��м�Ľڵ�
	{
		ListNode *p;
		p = pToBeDeleted->m_pNext;
		pToBeDeleted->m_nValue = p->m_nValue;
		pToBeDeleted->m_pNext = p->m_pNext;

		delete p;
		p = NULL;//ɾ��ָ���Ҫ�ͷ�
	}
	else if (*pListHead==pToBeDeleted)//����һ����㣬ɾ��ͷ���
	{
		delete pToBeDeleted;
		pToBeDeleted = NULL;

		*pListHead= NULL;//ͷ���ָ��գ�Ϊ������
	}
	else   //����ڵ���ɾ��β�ڵ�
	{
		ListNode *pNode=*pListHead;

		while (pNode->m_pNext!=pToBeDeleted)//Ѱ��Ҫɾ���ڵ��ǰһ���ڵ�
		{
			pNode=pNode->m_pNext;
		}
		pNode->m_nValue = NULL;

		delete pToBeDeleted;
		pToBeDeleted = NULL;

	}

}

void CreateListTail(ListNode ** L, const int a[],int a_length)//��������β�巨
{
	ListNode *p, *r;

//	*L = (ListNode*)malloc(sizeof(ListNode));//Ϊ������������ͷ���
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

bool GetNode(const ListNode* L, int i, ListNode** Node)// ListNode** Node���붨��ָ��ڵ��ָ�룬���ܷ��ؽ��
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