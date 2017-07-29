#include <iostream>
#include <vector>

using namespace std;

vector<int> FindNumbersWithSum(vector<int> array, int sum);

int main_15()
{
	vector<int> data = { 1,2,3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
	vector<int> result = FindNumbersWithSum(data, 21);
	for (auto it = result.begin(); it != result.end();it++)
	{
		cout<< *it << " ";
	}
	return 0;
}
vector<int> FindNumbersWithSum(vector<int> array, int sum) {
	vector<int> result;
	result.clear();
	int length = array.size();
	if (length < 2)
		return result;
	int Min = 0xffff;
	int	product = 0, num1 = 0, num2 = 0;
	int low = 0, high = length-1;
	bool flag = false;
	while (low < high)
	{
		while ((array[low] + array[high] < sum) && (low < high))
			low++;
		while ((array[low] + array[high] > sum) && (low < high))
			high--;
		if ((array[low] + array[high] == sum) && (low < high))
		{
			product = array[low] * array[high];
			if (product < Min)
			{
				Min = product;
				num1 = array[low];
				num2 = array[high];
				flag = true;
			}
		}
		low++;
	}
	if (flag)
	{
		result.push_back(num1);
		result.push_back(num2);
	}
	return result;

}