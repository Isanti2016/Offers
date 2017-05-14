#include<iostream>

using namespace std;

#define MAX 200

int Addnum(char* str1, char* str2);

int main_2()
{
	char str1[MAX];
	char str2[MAX];


	printf("please input first num:\n");
	gets_s(str1);
	printf("please input second num:\n");
	gets_s(str2);

	Addnum(str1, str2);
	return 0;
}

int Addnum(char* str1, char* str2)
{
	int length1 = strlen(str1);
	int length2 = strlen(str2);
	int M = length1 < length2 ? length2 : length1;
	int *num1 = new int[M];
	int *num2 = new int[M];
	for (int i = 0; i < length1; i++)
		num1[i] = str1[i] - '0';
 	for (int i = 0; i < length2; i++)
 		num2[i] = str2[i] - '0';



	puts(str1);
	puts(str2);


	return 0;
}