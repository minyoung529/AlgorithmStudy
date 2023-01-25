#include<iostream>
using namespace std;

int dp[2][100001], stickers[2][100001], n;

int main()
{
	int testCnt;
	cin >> testCnt;

	while (testCnt--)
	{
		cin >> n;

		for (int i = 0; i < 2; i++)
			for (int j = 1; j <= n; j++)
				cin >> stickers[i][j];

		dp[0][0] = dp[1][0] = 0;
		dp[0][1] = stickers[0][1];
		dp[1][1] = stickers[1][1];

		for (int i = 2; i <= n; i++)
		{
			dp[0][i] = max(dp[1][i-1], dp[1][i-2]) + stickers[0][i];
			dp[1][i] = max(dp[0][i-1], dp[0][i-2]) + stickers[1][i];
		}

		cout << max(dp[0][n], dp[1][n]) << '\n';
	}
}