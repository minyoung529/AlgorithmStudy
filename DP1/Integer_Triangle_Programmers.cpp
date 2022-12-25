#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> t)
{
	for (int i = t.size() - 1; i > 0; i--)
	{
		for (int j = 0; j < t[i].size() - 1; j++)
		{
			t[i - 1][j] += max(t[i][j] + t[i - 1][j], t[i][j + 1] + t[i - 1][j]);
		}
	}

	for (int i = 0; i <  t.size(); i++)
	{
		for (int j = 0; j < t[i].size() - 1; j++)
		{
			cout << t[i][j] << ' ';
		}
		cout << endl;
	}


	return t[0][0];
}