#include <iostream>

using namespace std;
int GetUglyNumber_solution(int index);//得到第index个丑数
int Min_UglyNumber(int num1, int num2, int num3);

int main_14()
{
	int index = 15;
	int result= GetUglyNumber_solution(index);
	cout << "100th ugly numbers:" << result << endl;;
	return 0;
}

int GetUglyNumber_solution(int index)
{
	int *UglyNumber = new int[index];
	UglyNumber[0] = 1;
	int *Number2 = UglyNumber;
	int *Number3 = UglyNumber;
	int *Number5 = UglyNumber;
	int count = 1;
	while (count<index)
	{
		int num_min = Min_UglyNumber(*Number2 * 2, *Number3 * 3, *Number5 * 5);
		UglyNumber[count] = num_min;

		while (UglyNumber[count] >= *Number2 *2)
		{
			Number2++;
		}
		while (UglyNumber[count] >= *Number3 *3)
		{
			Number3++;
		}
		while (UglyNumber[count] >= *Number5 *5)
		{
			Number5++;
		}

		count++;
	}
	return UglyNumber[index-1];

}
int Min_UglyNumber(int num1, int num2, int num3)
{
	int min_num = (num1 < num2) ? num1 : num2;
	min_num = (min_num < num3) ? min_num : num3;
	return min_num;
}