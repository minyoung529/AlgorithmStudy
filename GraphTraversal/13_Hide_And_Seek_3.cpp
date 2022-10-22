#include<iostream>
#include<queue>
using namespace std;

#define MAX 100000
bool visited[100001];
int start, endV, answer = 10000000;

void set(int f, int s, queue<pair<int, int>>& q)
{
	if (f < 0 || f > MAX || visited[f]) return;

	visited[f] = true;
	q.push({ f , s });
}

int main()
{
	cin >> start >> endV;

	queue<pair<int, int>> q;
	q.push({ start, 0 });

	if (start >= endV)
	{
		cout << start - endV;
		return 0;
	}

	while (!q.empty())
	{
		pair<int, int> top = q.front();

		// 찾았다면 종료  
		if (top.first == endV)
		{
			answer = min(top.second, answer);
		}

		q.pop();

		if (top.first != 0)
			set(top.first * 2, top.second, q);

		set(top.first - 1, top.second + 1, q);
		set(top.first + 1, top.second + 1, q);
	}

	cout << answer;
}