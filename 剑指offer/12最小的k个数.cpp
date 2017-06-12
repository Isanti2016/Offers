#include <iostream>
#include <vector>
#include <set>
#include <functional>
using namespace std;

vector<int> GetLeastNumbers_Solution(vector<int> input, int k);//����С��k����


int main_12()
{
	vector<int> input = { 4,5,1,6,2,7,3,8 };
	vector<int> result;
	result = GetLeastNumbers_Solution(input,4);
	for (auto it = result.begin(); it != result.end();it++)
	{
		cout << *it << "   ";
	}
	cout << endl;
	return 0;
}

vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
	vector<int> result;
	result.clear();
	int length = input.size();
	if (k <= 0 || length == 0 || length < k)
		return result;
	multiset<int, greater<int> > res_set;//��������С��k�����������ظ���,������multiset��greater��<functional>�У�����������ͷ��������ɾ��������

	for (int i = 0; i < length; i++)
	{
		if (i < k)
		{
			res_set.insert(input[i]);
		}
		else
		{
			if (input[i] < (*res_set.begin()))
			{
				res_set.erase(res_set.begin());//���ܲ����������֣�ֻ�ܲ���������ָ�������
				res_set.insert(input[i]);
			}
		}
	}
	result.assign(res_set.begin(), res_set.end());//�������ֵ
	return result;
}