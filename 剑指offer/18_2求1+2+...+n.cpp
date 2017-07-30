#include <iostream>

using namespace std;

class AB;
AB* Array[2];//定义指针数组

class AB
{
public:
	AB() {}
	~AB(){}
	virtual unsigned int Sum(unsigned int n)
	{
		return 0;
	}
};
class BA:public AB
{
public:
	BA() {}
	~BA(){}
	virtual unsigned int Sum(unsigned int n)
	{
		return Array[!!n]->Sum(n - 1)+n;
	}
};

int main_18_2()
{
	int n;
	cin >> n;
	AB a;
	BA b;
	Array[0] = &a;
	Array[1] = &b;					//用于!!n访问，当n不等于0时；
	int value = Array[1]->Sum(n);
	cout << value << endl;
	return 0;
}