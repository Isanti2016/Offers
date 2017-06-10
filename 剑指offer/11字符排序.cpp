#include <iostream>
#include <vector>
#include <set>
using namespace std;


vector<string> Permutation(string str);//��ʽ�ϵ��ַ�ȫ��
void Permutation(string str, set<string>&result, int begin, int end);//�����ַ�ȫ��
void swap(string& str, int num1, int num2);//�����ַ�
int main()
{
	//char* str = "abcdefg";
	//char str[10] = "abc";
	//string str = "abc";
	string str = "bba";
	cout << "permutation :" << endl;

	vector<string> result;//���
	result=Permutation(str);


	for (int i = 0; i < result.size();i++)
	{
		for (int j = 0; j < result[0].size();j++)
		{
			cout << result[i][j] << "  ";
		}
		cout << endl;//ÿһ��ȫ�Ż���
	}
	cout << endl;

	return 0;
}
vector<string> Permutation(string str)
{
	vector<string> result;//���
	set<string> set_result;//set���Ԫ���ظ������⣬��ȫ�ź��ַ��������򣬣����ֵ���
	int length = str.size();
	if (length==0)
	{
		return result;
	}

	Permutation(str,set_result,0,length);

	result.assign( set_result.begin(), set_result.end());//��setת��ΪҪ���vector
	return result;
}
void Permutation(string str,set<string>&result,int begin,int end)//����set���Ԫ���ظ�����ȫ�ź��ֵ������������ 
{
	if (begin==end-1)
	{
		result.insert(str);
	}
	else
	{

		for (int i = begin; i < end;i++)
		{

			swap(str, i, begin);
			Permutation(str, result, begin + 1, end);
			swap(str, i, begin);//�ָ�Ϊԭ�����ַ���
		}
	}
}

void swap(string& str, int num1, int num2)//�����ַ�
{
	char temp = str[num1];
	str[num1] = str[num2];
	str[num2] = temp;
}