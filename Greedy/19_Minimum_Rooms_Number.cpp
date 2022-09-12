#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef unsigned long long int ulli;

vector<pair<ulli, ulli>> times;
priority_queue<ulli, vector<ulli>, greater<ulli>> rooms;

int main()
{
	int len;
	cin >> len;

	for (int i = 0; i < len; i++)
	{
		ulli start, end;
		cin >> start >> end;
		times.push_back({ start,end });
	}

	sort(times.begin(), times.end());

	for (int i = 0; i < len; i++)
	{
		// 강의실을 이용할 수 있다면
		if (!rooms.empty() && rooms.top() <= times[i].first)
		{
			rooms.pop();
		}

		rooms.push(times[i].second);
	}

	cout << rooms.size();
}