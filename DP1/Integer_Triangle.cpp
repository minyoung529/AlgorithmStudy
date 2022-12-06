#include<iostream>
using namespace std;

int triangle[500][500];

int main()
{
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int height;
	cin >> height;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> triangle[i][j];
		}
	}

	for (int i = height - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			int maxVal = max(triangle[i][j], triangle[i][j + 1]);
			triangle[i - 1][j] += maxVal;
		}
	}

	cout << triangle[0][0];
}