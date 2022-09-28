#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	unsigned long long int dp[1001] = { 0,1,2,3,0 };

	for (int i = 4; i <= 1000; i++)
	{
		dp[i] += (dp[i - 1] + dp[i - 2]) % 10007;
	}

	cin >> n;
	cout << dp[n];
}