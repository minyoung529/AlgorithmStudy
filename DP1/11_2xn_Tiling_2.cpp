#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	unsigned long long int dp[1001] = { 0,1,3,5,0 };

	for (int i = 4; i <= 1000; i++)
	{
		// ㅣ 로 추가되는 게 하나,
		// =로 추가되는 게 둘!
		dp[i] += (dp[i - 1] + dp[i - 2] * 2) % 10007;
	}

	cin >> n;
	cout << dp[n];
}