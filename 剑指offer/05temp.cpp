#include<iostream>  
#include<vector>  
using namespace std;

//Î»²Ù×÷Ëã·¨  
// void main()
//// {
//	char* data = "abcd";
//	int length = strlen(data);
//	int last = (1 << length) - 1;
//	cout << last << endl;
//
//	int i;
//	for (i = 1; i <= last; i++)
//	{
//		int currentIndex = length - 1;
//		while (currentIndex >= 0)
//		{
//			if (i&(1 << currentIndex))
//			{
//				cout << data[length - currentIndex - 1];
//			}
//			--currentIndex;
//		}
//		cout << endl;
//	}
//}
void algorithm(char* data, int num, vector<char>& result)
{
	if (!num)
	{
		vector<char>::iterator it = result.begin();
		for (it; it != result.end(); ++it)
		{
			cout << *it;
		}
		cout << endl;
		return;
	}
	if (*data == '\0')
		return;
	result.push_back(*data);
	algorithm(data + 1, num - 1, result);
	result.pop_back();
	algorithm(data + 1, num, result);
}

void main_5()
{
	char* data = "abcd";
	int length = strlen(data);
	vector<char> result;
	int i;
	for (i = 1; i <= length; i++)
	{
		algorithm(data, i, result);
	}
}