#include <iostream>
#include <vector>

using namespace std;

void reOrderArray(vector<int> &array,bool (*fun)(int));//利用函数指针，构成模版，奇数在前，偶数在后
void reOrderArray_1(vector<int> &array, bool(*fun)(int)); //利用函数指针，构成模版，奇数在前，偶数在后，顺序不变
void swap(vector<int> &array, int low, int high);
bool isEvent(int num);//函数模版

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

void reOrderArray(vector<int> &array,bool (*fun)(int)) //利用函数指针，构成模版,奇数在前，偶数在后
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
void reOrderArray_1(vector<int> &array, bool(*fun)(int)) //利用函数指针，构成模版，奇数在前，偶数在后，顺序不变
{
	if (array.size() == 0)
	{
		return;
	}
	for (int i = 1; i < array.size(); i++)
	{
		if (array[i] & 1)//为奇数
		{
			int temp = array[i];
			int j = i - 1;
			while (!(array[j]&1)&&j>=0)//利用插入排序，要注意j>=0,不然j--可能越界
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

