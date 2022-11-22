#include<bits/stdc++.h>
using namespace std;
typedef long long  ull;

pair<ull, int> arr[500000];	// first > value, second > start
ull oarr[500000];			// 원본 데이터

int main()
{
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	int len, limit;
	ull result = 0;
	cin >> len >> limit;

	for (int i = 0; i < len; i++)
	{
		cin >> arr[i].first;
		oarr[i] = arr[i].first;

		// 시작 위치를 0을 설정
		arr[i].second = 0;
	}

	for (int i = 1; i < len; i++)
	{
		ull previous = arr[i - 1].first;

		if (previous + arr[i].first > limit)	// 길이를 연장할 때 한계값을 넘으면
		{
			// 전 누적된 합 + 현재 값이 한계값을 넘지 않게
			// 시작 위치부터 계속 길이를 잘라준다
			for (int j = arr[i - 1].second; j < i; j++)
			{
				previous -= oarr[j];
				arr[i].second = j + 1;

				if (previous + arr[i].first <= limit)	// 넘지 않게 되면 break
				{
					break;
				}
			}

			// 그럼에도 한계값 넘으면 continue
			if (previous + arr[i].first > limit)
				continue;
		}
		else
		{
			arr[i].second = arr[i - 1].second;	// 시작 위치를 전 시작 위치로 갱신한다. (연장)
		}

		// 연장
		arr[i].first += previous;
		result = max(result, arr[i].first);
	}

	cout << result;
}