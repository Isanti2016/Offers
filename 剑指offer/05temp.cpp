#include <iostream> 
#include <strstream> 
using namespace std;

int GetUglyNumber_Solution_1(int index);
bool IsUgly_1(int number);

int main_5()
{
	cout << GetUglyNumber_Solution_1(7) << endl;
	system("pause");
	return 0;
}

int GetUglyNumber_Solution_1(int index) {
	int count = 0;
	int num = 0;

	if (index <= 0)
		return num;

	while (count < index)
	{
		++num;
		if (IsUgly_1(num))
			count++;
	}
	return num;
}
bool IsUgly_1(int number)
{
	while (number % 2 == 0)//ֻҪ�����ӵ�2��һֱ������2ȥ��
		number /= 2;
	while (number % 3 == 0)//ֻҪ�����ӵ�3��һֱ������3ȥ��
		number /= 3;
	while (number % 5 == 0)//ֻҪ�����ӵ�5��һֱ������5ȥ��
		number /= 5;
	return (number == 1) ? true : false;//1�ǳ���
}