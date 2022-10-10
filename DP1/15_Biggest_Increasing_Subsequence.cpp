#include<bits/stdc++.h>
using namespace std;

// first > value
// second > length
pair<int, int> arr[1000];

int main()
{
	int len, answer = 1;
	cin >> len;

	for (int i = 0; i < len; i++)
	{
		cin >> arr[i].first;
		answer = max(arr[i].first, answer);
	}

	for (int i = 0; i < len; i++)
	{
		arr[i].second = arr[i].first;

		for (int j = 0; j < i; j++)
		{
			if (arr[j].first < arr[i].first)
			{
				arr[i].second = max(arr[i].second, arr[j].second + arr[i].first);
				answer = max(answer, arr[i].second);
			}
		}
	}

	cout << answer;
}