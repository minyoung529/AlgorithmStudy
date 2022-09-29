#include<bits/stdc++.h>
using namespace std;

int stairs[300];
int dp[300];

int main()
{
	int len;
	cin >> len;

	for (int i = 0; i < len; i++)
	{
		cin >> stairs[i];
	}

	dp[0] = stairs[0];
	dp[1] = dp[0] + stairs[1];
	dp[2] = max(stairs[0], stairs[1]) + stairs[2];

	for (int i = 3; i < len; i++)
	{
		// 2 전 계단이나
		// 바로 전 + 바로 전 - 2전 계단
		dp[i] = max(dp[i - 2], dp[i - 3] + stairs[i - 1]) + stairs[i];
	}

	cout << dp[len - 1];
}