#include<bits/stdc++.h>
using namespace std;

int main()
{
	int dp[30][30], y, x;
	cin >> y >> x;

	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (i > 0 && j > 0 && j != i)
			{
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			}
			else
			{
				dp[i][j] = 1;
			}
		}
	}

	cout << dp[y - 1][x - 1];
}