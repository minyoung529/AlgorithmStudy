#include<iostream>
#include<deque>
#include<vector>
using namespace std;

deque<int> disk[51];
int radius, numCnt, tCnt, sum = 0, curAlive;

bool visited[51][51];
void DFS(int x, int y, vector<pair<int, int>>& vec);
bool Check();

int main()
{
	cin >> radius >> numCnt >> tCnt;
	curAlive = radius * numCnt;

	// 입력
	for (int i = 1; i <= radius; i++)
	{
		disk[i].resize(numCnt);

		for (int j = 0; j < numCnt; j++)
		{
			cin >> disk[i][j];
			sum += disk[i][j];
		}
	}

	while (tCnt--)
	{
		int target, direction, num;
		cin >> target >> direction >> num;
		num %= numCnt;

		// 돌리기
		for (int i = target; i <= radius; i += target)
		{
			for (int j = 0; j < num; j++)
			{
				if (!direction)	// 시계
				{
					disk[i].push_front(disk[i].back());
					disk[i].pop_back();
				}
				else
				{
					disk[i].push_back(disk[i].front());
					disk[i].pop_front();
				}
			}
		}

		// 체크 못하면 평균 구하기
		if (!Check() && curAlive > 0)
		{
			float aver = sum / (float)curAlive;

			for (int i = 1; i <= radius; i++)
			{
				for (int j = 0; j < numCnt; j++)
				{
					if (disk[i][j] < 0)continue;
					if (disk[i][j] == aver)continue;

					int val = (disk[i][j] > aver) ? -1 : 1;

					sum += val;
					disk[i][j] += val;
				}
			}
		}
	}

	cout << sum;
}

int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };

void DFS(int x, int y, vector<pair<int, int>>& vec)
{
	visited[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny > radius || ny <= 0) continue;
		nx = (nx + numCnt) % numCnt;

		if (disk[ny][nx] == disk[y][x] && !visited[ny][nx])
		{
			vec.push_back({ ny, nx });
			DFS(nx, ny, vec);
		}
	}
}

bool Check()
{
	bool check = false;

	fill(&visited[0][0], &visited[50][51], false);

	for (int i = 1; i <= radius; i++)
	{
		for (int j = 0; j < numCnt; j++)
		{
			if (visited[i][j] || disk[i][j] < 0) continue;

			vector<pair<int, int>> deleted;
			DFS(j, i, deleted);

			// 지울 수들이 있다면
			if (!deleted.empty())
			{
				check = true;
				deleted.push_back({ i, j });	// 현재 좌표도 넣기

				curAlive -= deleted.size();

				// 모두 지우고 sum 갱신
				for (pair<int, int> p : deleted)
				{
					sum -= disk[p.first][p.second];
					disk[p.first][p.second] = -1;
				}
			}
		}
	}

	return check;
}
