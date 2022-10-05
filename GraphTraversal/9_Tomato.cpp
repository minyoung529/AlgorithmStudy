#include<iostream>
#include<queue>
using namespace std;

int width, height;

// 토마토 
int field[1000][1000];
// 방문 체크 배 
bool visited[1000][1000];

int curTomato, tomatoSum = 0;

// 사방 
int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1,0,-1,0 };

queue<pair<int, int>> q;

void Tomato(int x, int y);


int main()
{
	int answer = 0;
	cin >> width >> height;

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			cin >> field[y][x];
			visited[y][x] =열 false;

			// 익혀야하는 토마토 저장 
			if (field[y][x] == 0) tomatoSum++;
			// 이미 익은 토마토는 queue에 넣어준다 
			else if (field[y][x] == 1) q.push({ x,y });
		}
	}

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		// 익은 토마토이고 방문하지 않았을 때 
		if (field[y][x] > 0 && !visited[y][x])
		{
			Tomato(x, y);
		}

		answer = field[y][x];
	}

	// 익혀야하는 토마토를 익히지 못했을 때 -1 
	if (tomatoSum == curTomato)
	{
		cout << answer - 1;
	}
	else
	{
		cout << -1;
	}
}

void Tomato(int x, int y)
{
	visited[y][x] = true;

	// 사방 검사 
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= width || ny >= height) continue;

		// 방문하지 않았고 익지 않았다면 
		if (!visited[ny][nx] && field[ny][nx] == 0)
		{
			curTomato++;
			field[ny][nx] = field[y][x] + 1;
			q.push({ nx, ny });
		}
	}
}
