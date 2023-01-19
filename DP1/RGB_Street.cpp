#include<iostream>
using namespace std;

struct rgb { int r, g, b; };

int dp[30000000];
rgb houses[1000];

int main()
{
	int len, r, g, b, result = 100000000;
	cin >> len;

	for (int i = 0; i < len; i++)
	{
		cin >> r >> g >> b;
		houses[i] = { r, g, b };
	}

	dp[0] = houses[0].r;
	dp[1] = houses[0].g;
	dp[2] = houses[0].b;

	for (int i = 1; i < len; i++)
	{
		int idx = i * 3;

		dp[idx] += min(dp[idx - 1], dp[idx - 2]) + houses[i].r;		// r
		dp[idx + 1] += min(dp[idx - 3], dp[idx - 1]) + houses[i].g;	// g
		dp[idx + 2] += min(dp[idx - 3], dp[idx - 2]) + houses[i].b;// b
	}

	result = min(dp[(len - 1) * 3], dp[(len - 1) * 3 + 1]);
	result = min(result, dp[(len - 1) * 3 + 2]);

	cout << result;
}