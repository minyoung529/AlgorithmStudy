#include<iostream>
using namespace std;

bool check[26] = { 0, };
char arr[20][20];
int ans = 0, r, c;

int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };

bool visited[20][20];

void DFS(int x, int y, int count = 0)
{
	int idx = arr[y][x] - 'A';

	check[idx] = true;
	visited[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= c || ny >= r || visited[ny][nx] || check[arr[ny][nx] - 'A'] > 0)
		{
			ans = max(ans, count);
			continue;
		}

		DFS(nx, ny, count + 1);
	}

	check[idx] = false;
	visited[y][x] = false;
}

int main()
{
	cin >> r >> c;

	for (int i = 0; i < r; i++)
	{
		string str;
		cin >> str;

		for (int j = 0; j < c; j++)
		{
			arr[i][j] = str[j];
		}
	}

	DFS(0, 0);
	cout << ans + 1;
}