#include<bits/stdc++.h>
using namespace std;

int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };

int field[200][200];

struct virus
{
	int y, x, virus, day;

	// 날짜순, 바이러스 번호 순으로 정렬
	bool operator>(const struct virus& v) const
	{
		if (day == v.day)
			return virus > v.virus;

		return day > v.day;
	}
};

priority_queue<virus, vector<virus>, greater<virus>> q;

int main()
{
	int n, k, x, y, s;
	cin >> n >> k;

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			int v;
			cin >> v;
			field[y][x] = v;

			if (v > 0)
			{
				q.push({ y,x,v,1 });
			}
		}
	}

	cin >> s >> x >> y;

	// BFS
	while (!q.empty())
	{
		// s day가 지나면 전염을 멈춘다
		if (q.top().day > s) break;

		virus front = q.top();
		q.pop();

		// 사방으로 인접한 요소들을 전염시킨다
		for (int i = 0; i < 4; i++)
		{
			int nx = front.x + dx[i];
			int ny = front.y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n || field[ny][nx] > 0) continue;

			field[ny][nx] = front.virus;

			q.push({ ny, nx, front.virus, front.day + 1 });
		}
	}

	cout << field[x - 1][y - 1];
}