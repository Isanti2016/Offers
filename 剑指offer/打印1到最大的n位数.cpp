#include<iostream>

using namespace std;

void Print1ToMaxofNDigits(int n);
bool Increatement(char *number);
void PrintNumber(char *number);

int main_1()
{
	Print1ToMaxofNDigits(3);
	return 0;
}

void Print1ToMaxofNDigits(int n)
{
	if (n <=0)
		return;

	char* number = new char[n + 1];
	memset(number,'0',n);
	number[n] = '\0';
	while (!Increatement(number))
	{
		PrintNumber(number);
	}

	delete[] number;
	number = NULL;//delete过后及时赋值为NULL
}
bool Increatement(char *number)
{
	bool IsOverflow = false;
	int nTakeOver = 0;//进位标志
	int nlenghth = strlen(number);
	for (int i=nlenghth-1;i>=0;i--)
	{
		int nSum = number[i] - '0' + nTakeOver;
		if (i == nlenghth - 1)
			nSum++;
		if (nSum>=10)//大于10进位
		{
			if (i == 0)
				IsOverflow = true;
			else
			{
				nSum=nSum - 10;
				number[i] = nSum + '0';
				nTakeOver = 1;
			}
		}
		else
		{
			number[i] = nSum + '0';
			break;
		}
	}
	return IsOverflow;
}
void PrintNumber(char *number)
{
	bool IsBegining = true;
	int nLength = strlen(number);
	for (int i=0;i<nLength;i++)
	{
		if (IsBegining&&number[i]!='0')
		{
			IsBegining = false;		
		}
		if (!IsBegining)
		{
			printf("%c", number[i]);
		}	
	}
	printf("\t");
}