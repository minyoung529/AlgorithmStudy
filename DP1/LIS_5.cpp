#include<iostream>
#include<algorithm>

using namespace std;
int arr[1000001];
int lengths[1000001];
int index[1000001];
int ans[1000001];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int input;
	int cnt = 0;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> input;
		arr[i] = input;

		if (cnt == 0)
		{
			lengths[cnt++] = input;
		}
		else if (lengths[cnt - 1] < input)   // 현재 게 더 크다면 계속 길이 늘임
		{
			lengths[cnt++] = input;
		}
		else  // 아니라면 앞에 거 갱신
		{
			int lowerIdx = lower_bound(lengths, lengths + cnt, input) - lengths;
			lengths[lowerIdx] = input;
		}
	}

	cout << cnt << '\n';
}