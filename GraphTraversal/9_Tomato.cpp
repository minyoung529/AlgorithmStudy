#include<iostream>
#include<queue>
using namespace std;

int width, height;

// �丶�� 
int field[1000][1000];
// �湮 üũ �� 
bool visited[1000][1000];

int curTomato, tomatoSum = 0;

// ��� 
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
			visited[y][x] =�� false;

			// �������ϴ� �丶�� ���� 
			if (field[y][x] == 0) tomatoSum++;
			// �̹� ���� �丶��� queue�� �־��ش� 
			else if (field[y][x] == 1) q.push({ x,y });
		}
	}

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		// ���� �丶���̰� �湮���� �ʾ��� �� 
		if (field[y][x] > 0 && !visited[y][x])
		{
			Tomato(x, y);
		}

		answer = field[y][x];
	}

	// �������ϴ� �丶�並 ������ ������ �� -1 
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

	// ��� �˻� 
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= width || ny >= height) continue;

		// �湮���� �ʾҰ� ���� �ʾҴٸ� 
		if (!visited[ny][nx] && field[ny][nx] == 0)
		{
			curTomato++;
			field[ny][nx] = field[y][x] + 1;
			q.push({ nx, ny });
		}
	}
}
