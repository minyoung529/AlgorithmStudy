#include<iostream>
using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int width, height, cnt, answer = 0;

int field[51][51];
bool visited[51][51] = { false, };

void DFS(int y, int x);

int main()
{
	int testCnt;
	cin >> testCnt;

	while (testCnt--)
	{
		// 초기화
		fill_n(field[0], 51 * 51, 0);
		fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
		answer = 0;

		cin >> width >> height >> cnt;
		
		for(int i = 0; i < cnt; i++)
		{
			int x, y;
			cin >> x >> y;
			field[y][x] = 1;
		}

		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				// 발견한 적 없는 양배추를 탐색
				if (!visited[i][j] && field[i][j] == 1)
				{
					answer++;
					DFS(i, j);
				}
			}
		}

		cout << answer << endl;
	}
}

// DFS 탐색으로 인접 양배추를 찾는다
void DFS(int y, int x)
{
	visited[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx > width || ny > height) continue;

		// 양배추가 있으면서 발견하지 않은 양배추만 탐색
		if (field[ny][nx] == 1 && !visited[ny][nx])
		{
			DFS(ny, nx);
		}
	}

	return;
}