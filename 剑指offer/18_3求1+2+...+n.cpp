#include <iostream>

using namespace std;

typedef unsigned int(*fun)(unsigned int n);//��������ָ��fun

unsigned int Solution3_Teminator(unsigned int n)
{
	return 0;
}
unsigned int Sum_Solution3(unsigned int n)
{
	static fun f[2] = {Solution3_Teminator,Sum_Solution3};//ʵ�������������!!n�Ĺ�ϵ
	return f[!!n](n - 1) + n;
}


int main_18_3()
{
	int n;
	cin >> n;
	unsigned result = Sum_Solution3(n);
	cout << result << endl;
	return 0;
}