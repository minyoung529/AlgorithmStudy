#include<iostream>
#include<algorithm>
using namespace std;

int w, h, t, answer = 0, machineY, machineX;
int copied[51][51], field[51][51];
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };

void Diffusion(int x, int y, int val)
{
	int sum = 0;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= w || ny >= h || field[ny][nx] == -1) continue;

		field[ny][nx] += val / 5;
		sum += val / 5;
	}

	field[y][x] -= sum;
}

void Move(int x, int y, int val)
{
	if (field[y][x] == -1) return;	// 공기청정기는 움직이지 않음
	if (val == -1) val = 0;

	field[y][x] = val;
}

int main()
{
	cin >> h >> w >> t;

	// 입력
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> field[i][j];

			if (field[i][j] == -1)
			{
				machineX = j;
				machineY = i;
			}
		}
	}

	while (t--)
	{
		copy(&field[0][0], &field[50][50], &copied[0][0]);

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (copied[i][j] > 0)
				{
					Diffusion(j, i, copied[i][j]);
				}
			}
		}

		copy(&field[0][0], &field[50][50], &copied[0][0]);

		for (int i = 0; i < w - 1; i++)
		{
			// --->
			Move(i + 1, machineY - 1, copied[machineY - 1][i]);
			Move(i + 1, machineY, copied[machineY][i]);

			// <---
			Move(i, 0, copied[0][i + 1]);
			Move(i, h - 1, copied[h - 1][i + 1]);
		}

		for (int i = 0; i < h - 1; i++)
		{
			int downX = 0, upX = w - 1;

			if (i >= machineY)
			{
				downX = w - 1; // O
			}

			if (i >= machineY - 1)
			{
				upX = 0;
			}

			Move(downX, i + 1, copied[i][downX]);
			Move(upX, i, copied[i + 1][upX]);
		}
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (field[i][j] != -1)
				answer += field[i][j];
		}
	}

	cout << answer;
}