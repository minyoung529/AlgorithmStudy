#include<bits/stdc++.h>
using namespace std;

int main()
{
	int tCnt;
	int dp[12] = { 0, };

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i <= 11; i++)
	{
		// 3 전까지의 방법을 모두 더해준다
		dp[i] += dp[i - 1];
		dp[i] += dp[i - 2];
		dp[i] += dp[i - 3];
	}

	cin >> tCnt;

	while (tCnt--)
	{
		int input;
		cin >> input;
		cout << dp[input] << '\n';
	}
}