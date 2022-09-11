#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> times;
priority_queue<int, vector<int>, greater<int>> rooms;

int main()
{
	int len;
	cin >> len;

	for (int i = 0; i < len; i++)
	{
		int start, end;
		cin >> start >> end;
		times.push_back({ start,end });
	}

	sort(times.begin(), times.end());

	for (int i = 0; i < len; i++)
	{
		if (!rooms.empty() && rooms.top() <= times[i].first)
		{
			rooms.pop();
		}

		rooms.push(times[i].second);
	}

	cout << rooms.size();
}