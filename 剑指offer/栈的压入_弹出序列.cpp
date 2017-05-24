#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool IsPopOrder(vector<int> pushV, vector<int> popV);//ÅÐ¶ÏÑ¹Èëµ¯³öÕ»

int main()
{
	vector<int> vec = { 1,2,3,4,5 };
	//vector<int> vec1 = {5,4,3,2,1};
	//vector<int> vec1 = { 4,5,3,2,1 };
	vector<int> vec1 = { 4,3,5,2,1 };
	//vector<int> vec1 = { 4,3,5,1,2 };

	bool result = IsPopOrder(vec, vec1);

	if (result)
	{
		cout << "vec1 is a subsidiary of vec" << endl;
	}
	else
		cout << "NULL" << endl;

	return 0;
}

bool IsPopOrder(vector<int> pushV, vector<int> popV)
{
	if (pushV.size()!=popV.size())
		return false;
	if (pushV.empty() || popV.empty())
		return false;
	stack<int> temp ;
	int j = 0;
	for (int i = 0; i < pushV.size();i++)
	{
		temp.push(pushV[i]);
		while (!temp.empty()&&temp.top()==popV[j])
		{
			temp.pop();
			j++;
		}
	}
	return temp.empty();
}