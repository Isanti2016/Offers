#include <iostream>
#include <string>

using namespace std;

string ReverseSentence(string str);
void Reverse(string& str, int low, int high);//实现反转
void swap_17(string& str, int low, int high);

int main_16()
{
	string str = "I am a student";//这个单词比较巧,因为I就一个单词，最后一步不反转也可以
	//string str = "student.";
	//string str = "Hello World!";
	cout << str << endl;
	string result = ReverseSentence(str);
	cout << result << endl;
	return 0;
}
string ReverseSentence(string str) {
	string result = str;
	int length = str.size();
	if (length == 0)
		return result;
	Reverse(result, 0, length - 1);
	int i = 0, j=1;
	while(j<length)
	{
		if (j == length - 1)//包含仅有一个单词或者最后一个单词后面没有空格的情况
			Reverse(result, i, j);
		if (result[j] == ' ')//根据空格反转每个单词
		{
			Reverse(result, i, j-1);
			j++;    //为了跳过空格，继续反转其他单词
			i = j;
		}
		else
			j++;
	}
	return result;
}
void Reverse(string& str, int low, int high)
{
	while (low < high)//注意反转的条件，不应该拿中值比较。
	{
		swap(str[low++], str[high--]);//调用系统的swap函数进行反转
	}
	cout << "reverse:" << str << endl;
}
void swap_17(string& str, int low, int high)
{
	char* ch_str = (char*)str.data();
	char temp = ch_str[low];
	ch_str[low] = ch_str[high];
	ch_str[high] = temp;
	str = ch_str;
}