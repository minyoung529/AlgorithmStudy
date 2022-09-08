#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef unsigned long long int ulli;

int main()
{
	int len, answer = 0;
	ulli endTime = 0;
	// first => end Time, second => start Time
	vector<pair<ulli, ulli>> times;

	cin >> len;

	for (int i = 0; i < len; i++)
	{
		ulli startTime, endTime;
		cin >> startTime;
		cin >> endTime;
		times.push_back({ endTime, startTime });
	}
	
	// endTime을 기준으로 정렬
	sort(times.begin(), times.end());

	for (int i = 0; i < len; i++)
	{
		// 회의가 끝나는 시간보다 같거나 늦을 때는 회의를 시작할 수 있다
		if (endTime <= times[i].second)
		{
			// 끝나는 시간 갱신
			endTime = times[i].first;
			answer++;
		}
	}

	cout << answer;
}