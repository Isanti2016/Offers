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
	//SealedClassB B;//SealedClassA�ǲ��ܱ��̳е���
	return 0;
}