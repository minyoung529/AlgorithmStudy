#include<iostream>
using namespace std;

long long int dp[100] = { 1, 1, 1, 2, 2 };

int main()
{
	int n, input;
	cin >> n;

	for (int i = 5; i < 100; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 5];
	}

	while (n--)
	{
		cin >> input;
		cout << dp[input - 1] << '\n';
	}
}