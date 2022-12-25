#include<math.h>
#define MOD 1000000007
using namespace std;
long long dp[5001];

int solution(int n)
{
	dp[1] = 0; dp[2] = 3; dp[4] = 11;

	for (int i = 6; i <= n; i++)
	{
		dp[i] = ((dp[i - 2] * 4 % MOD) - (dp[i - 4] % MOD) + MOD) % MOD;
	}

	return dp[n];
}

// ((f(n - 2) x 4 % 1,000,000,007) - (f(n - 4) % 1,000,000,007) + 1,000,000,007) % 1,000,000,007