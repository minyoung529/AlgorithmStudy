#include<bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
using namespace std;

int field[1000][1000];
int visited[1000][1000];

int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };

int main()
{
	FASTIO;
	int width, height;
	queue <pair<int, int>> q;

	cin >> height >> width;

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			cin >> field[y][x];

			if (field[y][x] == 2)
			{
				// 시작 블록이면 queue에 넣고 방문 처리
				q.push({ y, x });
				visited[y][x] = 1;
			}
		}
	}

	// BFS
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;

		q.pop();

		// 사방 검사
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= height || nx >= width) continue;
			if (visited[ny][nx] != 0 || field[ny][nx] == 0) continue;

			// 전에 있던 블록 + 1
			// 길이 연장
			visited[ny][nx] = visited[y][x] + 1;

			q.push({ ny, nx });
		}
	}

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (field[y][x] > 0)
			{
				// 갈 수 있고 방문한 길은 그냥 출력
				if(visited[y][x])
					cout << visited[y][x] - 1 << ' ';

				// 갈 수 있지만 방문하지 못한 길은  -1 출력
				else
					cout << - 1 << ' ';
			}
			else
				cout << 0 << ' ';
		}
		cout << '\n';
	}
}