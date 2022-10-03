#include<bits/stdc++.h>
using namespace std;

char arr[101][101];
bool visited[101][101];
int dx[4] = { -1, 0, 0, 1 }, dy[4] = { 0, 1, -1, 0 };
int cnt;

int See();
void DFS(int y, int x, char c);

int main()
{
	int answer1 = 0, answer2 = 0;
	cin >> cnt;

	for (int y = 0; y < cnt; y++)
	{
		string rgb;
		cin >> rgb;

		for (int x = 0; x < cnt; x++)
		{
			arr[y][x] = rgb[x];
		}
	}

	// 일반 사람의 시야
	answer1 = See();

	// 초기화
	memset(visited, 0, sizeof(visited));

	// G => R
	// 적록색약의 시야에서는 비슷하다
	for (int y = 0; y < cnt; y++)
	{
		for (int x = 0; x < cnt; x++)
		{
			if (arr[y][x] == 'G')
				arr[y][x] = 'R';
		}
	}

	// 적록색약의 시야
	answer2 = See();

	cout << answer1 << ' ' << answer2;
}

// DFS 호출 코드
int See()
{
	int res = 0;

	for (int y = 0; y < cnt; y++)
	{
		for (int x = 0; x < cnt; x++)
		{
			if (!visited[y][x])
			{
				DFS(y, x, arr[y][x]);
				res++;
			}
		}
	}

	return res;
}

void DFS(int y, int x, char c)
{
	visited[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= cnt || ny >= cnt || c != arr[ny][nx])continue;

		if (!visited[ny][nx])
		{
			DFS(ny, nx, c);
		}
	}
}