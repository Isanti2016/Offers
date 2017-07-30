#include <iostream>

using namespace std;
template<unsigned int n> //模版的写法
class Solution4
{
public:					//虽然struct和class大多数时候等价，但用class时的收，要用pubulic
	enum Value { N = Solution4<n - 1>::N + n };
};
template<> 
class Solution4<1>//全特化的模版
{
public:
	enum Value { N = 1 };
};
int main_18_4()
{
	Solution4<100> temp;//模版元编程，编译的时候求出来的值
	cout << temp.N << endl;
	return 0;
}