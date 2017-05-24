
#include <iostream>
#include <vector>
#include<Ctime>	

using namespace std;

vector<int> printMatrix(vector<vector<int> > matrix);//顺时针打印矩阵

int main_7()
{
	clock_t start, finish;
	double totaltime;
	start = clock();

	//vector<vector<int>> temp = {{1}};
	vector<vector<int>> temp = { { 1,2,3,4,5},{ 6,7,8,9,10},{11,12,13,14,15 }};
	//vector<vector<int>> temp = { { 1,2,3,4 },{ 5,6,7,8 },{ 9,10,11,12 },{ 13,14,15,16 } };
	//vector<vector<int>> temp = { { 1,2},{3,4 }};
	//vector<vector<int>> temp = { { 1,2},{3,4 }};
	vector<int> result = printMatrix(temp);
	for (auto it=result.begin();it!=result.end();it++)
	{
		cout << *it << "  ";
	}
	cout << endl;

	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "totaltime: " << totaltime << endl;
	return 0;
}

vector<int> printMatrix(vector<vector<int> > matrix) {
	int row = matrix.size();
	int column = matrix[0].size();
	vector<int> result;
	int i = 0, start = 0;
	while (i < (row*column))
	{
		int endx = column - start - 1;
		int endy = row - start - 1;
		//从左到右，不让=endx时，要是矩形，每一条边打印长度相同，但如果有一个元素，无法打印
		for (int a = start; (a <= endx) && i < (row*column); a++)
		{
			result.push_back(matrix[start][a]);
			i++;
		}
		//从上到下
		for (int a = start +1; (a <= endy) && i < (row*column); a++)
		{
			result.push_back(matrix[a][endx]);
			i++;
		}
		//从右到左
		for (int a = endx -1; (a >= start) && i < (row*column); a--)
		{
			result.push_back(matrix[endy][a]);
			i++;
		}
		//从下到上
		for (int a = endy -1; (a > start) && i < (row*column); a--)
		{
			result.push_back(matrix[a][start]);
			i++;
		}
		start++;
	}
	return result;
}