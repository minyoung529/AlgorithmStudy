#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

pair<int, vector<int>> dp[1000001];

int main()
{
	int num;
	cin >> num;

	dp[1] = { 0, {1} };
	dp[2] = { 1, {1,2} };
	dp[3] = { 1, {1,3} };

	if (num <= 3)
	{
		cout << dp[num].first << '\n';

		reverse(dp[num].second.begin(), dp[num].second.end());

		for (int i : dp[num].second)
		{
			cout << i << ' ';
		}

		return 0;
	}

	for (int i = 4; i <= num; i++)
	{
		if (i % 6 == 0)
		{
			dp[i].first = min(dp[i / 2].first + 1, dp[i / 3].first + 1);

			if (dp[i].first == dp[i / 2].first + 1)
				dp[i].second = dp[i / 2].second;
			else
				dp[i].second = dp[i / 3].second;

		}
		else if (i % 2 == 0)
		{
			dp[i].first = min(dp[i / 2].first + 1, dp[i - 1].first + 1);

			if (dp[i].first == dp[i / 2].first + 1)
				dp[i].second = dp[i / 2].second;
			else
				dp[i].second = dp[i - 1].second;
		}
		else if (i % 3 == 0)
		{
			dp[i].first = min(dp[i / 3].first + 1, dp[i - 1].first + 1);

			if (dp[i].first == dp[i / 3].first + 1)
				dp[i].second = dp[i / 3].second;
			else
				dp[i].second = dp[i - 1].second;
		}
		else
		{
			dp[i].first = dp[i - 1].first + 1;
			dp[i].second = dp[i - 1].second;
		}

		dp[i].second.push_back(i);
	}

	cout << dp[num].first << '\n';

	reverse(dp[num].second.begin(), dp[num].second.end());

	for (int i : dp[num].second)
	{
		cout << i << ' ';
	}
}