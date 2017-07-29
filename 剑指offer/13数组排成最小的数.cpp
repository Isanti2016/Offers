#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

string PrintMinNumber(vector<int>& numbers);
int cmp(const string str1, const string str2);

int main_13()
{
	vector<int> number = {3,32,321};
	cout << "Original array:" << endl;
	for (auto it = number.begin(); it != number.end(); it++)
	{
		cout << *it << "   ";
	}
	cout << endl << "results:" << endl;;


	string result = PrintMinNumber(number);

	cout << result << endl;

	return 0;
}

string PrintMinNumber(vector<int>& numbers)
{
	vector<string> vec;
	string result="";
	int length = numbers.size();
	if (length == 0)
	{
		return result;
	}
	for (int i = 0; i < length;i++)
	{
		stringstream ss;//利用stringstream把int转为string
		string str;
		ss << numbers[i];
		ss >> str;//利用stringstream把int转为string
		vec.push_back(str);
	}
	
	sort(vec.begin(), vec.end(), cmp);//调用algorithm中的sort算法进行排序

	for (auto it = vec.begin(); it != vec.end();it++)
	{
		result = result + *it;
	}

	return result;
}
int cmp(const string str1, const string str2)
{
	string s1 = str1 + str2;
	string s2 = str2 + str1;
	return s1 < s2;
}