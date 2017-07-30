#include <iostream>

using namespace std;
void Probability(int num, int a[]);
void Probability(int original, int current, int sum, int a[]);

int main_17()
{
	int n;
	cin >> n;
	int len = 6 * n - n + 1;//点数出现的范围是n到6*n
	int* a = new int[len];//为了存放每个点数出现的次数
	memset(a,0,len*sizeof(int));
	
	Probability(n, a);

	for (int i = 0; i < n;++i)
	{
		cout << a[i] << "  ";
	}
	cout << endl;
	delete a;
	return 0;
}
void Probability(int num, int a[])
{
	for (int i = 1; i <= num;++i)
	{
		Probability(num, num, i, a);
	}
}
void Probability(int original, int current, int sum, int a[])
{
	if (current==1)
	{
		a[sum - original]++;
	}
	else
	{
		for (int i = 1; i <= 6;++i)
		{
			Probability(original, current - 1, i + sum, a);
		}
	}
}