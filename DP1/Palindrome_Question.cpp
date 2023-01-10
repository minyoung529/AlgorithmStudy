#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int dp[2001][2001];
vector<int> seperated;

bool IsPalindrome(int p1, int p2)
{
	for (int i = p1; i < p1 + (p2 - p1) / 2 + 1; i++)
	{
		if (seperated[i] != seperated[p2 - (i - p1)])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	int n, a, b;
	int input;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> input;
		seperated.push_back(input);
	}

	// DP
	for (int i = 1; i <= n; i++)
	{
		dp[i][i] = 1;

		for (int j = i + 1; j <= n; j++)
		{
			if (seperated[i - 1] == seperated[j - 1])
			{
				if (dp[i][j - 1] == 1 || dp[i - 1][j] == 1)
				{
					dp[i][j] = 1;
				}
				else if (dp[i][j - 1] == 2 || dp[i - 1][j] == 2)
				{
					dp[i][j] = 0;
				}
				else if (IsPalindrome(i - 1, j - 1))
				{
					dp[i][j] = 2;
				}
			}
		}
	}

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		cout << (bool)dp[a][b] << '\n';
	}
}