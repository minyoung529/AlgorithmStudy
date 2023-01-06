#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001], len, n;

// LIS
int main()
{
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int here;
		cin >> here;

		int* pos = lower_bound(dp, dp + len, here);
		*pos = here;

		if (pos == dp + len)
		{
			len++;
		}
	}

	cout << len;
}