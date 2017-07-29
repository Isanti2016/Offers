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
	while (number % 2 == 0)//只要有因子的2则一直把因子2去掉
		number /= 2;
	while (number % 3 == 0)//只要有因子的3则一直把因子3去掉
		number /= 3;
	while (number % 5 == 0)//只要有因子的5则一直把因子5去掉
		number /= 5;
	return (number == 1) ? true : false;//1是丑数
}