#include <iostream>
#include <string>

using namespace std;

string ReverseSentence(string str);
void Reverse(string& str, int low, int high);//ʵ�ַ�ת
void swap_17(string& str, int low, int high);

int main_16()
{
	string str = "I am a student";//������ʱȽ���,��ΪI��һ�����ʣ����һ������תҲ����
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
		if (j == length - 1)//��������һ�����ʻ������һ�����ʺ���û�пո�����
			Reverse(result, i, j);
		if (result[j] == ' ')//���ݿո�תÿ������
		{
			Reverse(result, i, j-1);
			j++;    //Ϊ�������ո񣬼�����ת��������
			i = j;
		}
		else
			j++;
	}
	return result;
}
void Reverse(string& str, int low, int high)
{
	while (low < high)//ע�ⷴת����������Ӧ������ֵ�Ƚϡ�
	{
		swap(str[low++], str[high--]);//����ϵͳ��swap�������з�ת
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