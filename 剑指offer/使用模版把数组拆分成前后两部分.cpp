#include <iostream>
#include <vector>

using namespace std;

void reOrderArray(vector<int> &array,bool (*fun)(int));//���ú���ָ�룬����ģ�棬������ǰ��ż���ں�
void reOrderArray_1(vector<int> &array, bool(*fun)(int)); //���ú���ָ�룬����ģ�棬������ǰ��ż���ں�˳�򲻱�
void swap(vector<int> &array, int low, int high);
bool isEvent(int num);//����ģ��

int main()
{
	//vector<int> array = { 1,8,6,9,2,75,6,3 };
	vector<int> array = { 1,2,3,4,5,6,7 };
	cout << "original array:" << endl;
	for (auto it = array.begin(); it != array.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//reOrderArray(array,isEvent);
	reOrderArray_1(array, isEvent);

	cout << "reOrder array:" << endl;
	for (auto it=array.begin();it!=array.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	return 0;

}

void reOrderArray(vector<int> &array,bool (*fun)(int)) //���ú���ָ�룬����ģ��,������ǰ��ż���ں�
{
	int low = 0;
	int high = array.size() - 1;
	while (low < high)
	{
		while (low < high && fun(array[low]))
			low++;
		while (low < high && !fun(array[high]))
			high--;
		swap(array, low, high);
	}
}
void reOrderArray_1(vector<int> &array, bool(*fun)(int)) //���ú���ָ�룬����ģ�棬������ǰ��ż���ں�˳�򲻱�
{
	if (array.size() == 0)
	{
		return;
	}
	for (int i = 1; i < array.size(); i++)
	{
		if (array[i] & 1)//Ϊ����
		{
			int temp = array[i];
			int j = i - 1;
			while (!(array[j]&1)&&j>=0)//���ò�������Ҫע��j>=0,��Ȼj--����Խ��
			{
				array[j + 1] = array[j];
				j--;
			}
			array[j + 1] = temp;
		}

	}
}
void swap(vector<int> &array, int low, int high)
{
	int temp = array[low];
	array[low] = array[high];
	array[high] = temp;
}
bool isEvent(int num)
{
	if (num&1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

