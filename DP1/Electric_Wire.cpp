#include<iostream>
#include<algorithm>
using namespace std;

pair<int, int> arr[100000];
int length[100000];
int index[100000];
int ans[100000];

int main()
{
	int len, cnt = 0;
	cin >> len;

	for (int i = 0; i < len; i++)
		cin >> arr[i].first >> arr[i].second;

	sort(arr, arr + len);

	for (int i = 0; i < len; i++)
	{
		if (cnt == 0)
		{
			length[cnt++] = arr[i].second;
			index[i] = 0;
		}
		else if (length[cnt - 1] < arr[i].second)
		{
			index[i] = cnt;
			length[cnt++] = arr[i].second;
		}
		else
		{
			int lowerIdx = lower_bound(length, length + cnt, arr[i].second) - length;
			length[lowerIdx] = arr[i].second;
			index[i] = lowerIdx;
		}
	}

	cout << len - cnt << '\n';
	int t = 0;

	for (int i = len - 1; i >= 0; i--)
	{
		if (cnt == index[i] + 1)
			cnt--;
		else
			ans[t++] = arr[i].first;
	}

	for (int i = t - 1; i >= 0; i--)
	{
		cout << ans[i] << '\n';
	}
}