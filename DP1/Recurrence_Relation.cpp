#include<iostream>
using namespace std;

unsigned long long int dp[36] = { 1, };

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			// t(n) = t(0)*t(n-1) + t(1)*t(n-2) + ... + t(n-1)*t(0)
			dp[i] += dp[j] * dp[i - j - 1];
		}
	}

	cout << dp[n];
}