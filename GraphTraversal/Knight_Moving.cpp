#include<iostream>
#include<queue>
using namespace std;

int arr[300][300], curX, curY, destX, destY, scale;
int dx[8] = { -2, -1, 1, 2, -2, -1, 1, 2 };
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
bool visited[300][300];

struct pos
{
	int x, y;
};

int bfs();

int main()
{
	int tCnt;
	cin >> tCnt;

	while (tCnt--)
	{
		cin >> scale;
		cin >> curX >> curY;
		cin >> destX >> destY;

		cout << bfs() << '\n';

		for (int i = 0; i < 300; i++)
		{
			for (int j = 0; j < 300; j++)
			{
				arr[i][j] = 0;
				visited[i][j] = false;
			}
		}
	}
}

int bfs()
{
	queue<pos> q;
	bool isfind = false;
	q.push({ curX, curY });

	while (!q.empty() && !isfind)
	{
		pos front = q.front();
		q.pop();

		visited[front.y][front.x] = true;

		if (front.y == destY && front.x == destX)
			break;

		for (int i = 0; i < 8; i++)
		{
			int nx = front.x + dx[i];
			int ny = front.y + dy[i];

			if (nx < 0 || ny < 0 || nx >= scale || ny >= scale || visited[ny][nx])
				continue;

			q.push({ nx, ny });

			arr[ny][nx] = arr[front.y][front.x] + 1;
			visited[ny][nx] = true;

			if (ny == destY && nx == destX)
				isfind = true;
		}
	}

	return arr[destY][destX];
}