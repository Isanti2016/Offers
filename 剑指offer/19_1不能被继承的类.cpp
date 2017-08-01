#include <iostream>

using namespace std;

class SealedClassA
{
	static SealedClassA* GetInstance()
	{
		return new SealedClassA;
	}
private:
	SealedClassA() {}
	~SealedClassA() {}
};
class SealedClassB :public SealedClassA
{

};
int main_19_1()
{
	//SealedClassB B;//SealedClassA是不能被继承的类
	return 0;
}