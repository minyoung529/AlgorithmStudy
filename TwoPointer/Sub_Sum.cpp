#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 100001
int arr[100001];
long long int sum[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int n, s, ans = MAX;
	cin >> n >> s;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		sum[i] += arr[i] + sum[i - 1];
	}

	for (int i = 1; i <= n; i++)
	{
		if (sum[i] < s) continue;

		long long idx = lower_bound(sum, sum + i, sum[i] - s) - sum;

		if (sum[i] - sum[idx] < s)	// 초과면 길이 연장
		{
			idx--;
		}

		if (idx >= 0)
		{
			ans = min((int)(i - idx), ans);
		}
	}

	if (ans == MAX)
		ans = 0;

	cout << ans;
}