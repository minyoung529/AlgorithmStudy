#include<bits/stdc++.h>
using namespace std;

bool field[25][25];
bool visited[25][25];

int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };

int len;

priority_queue<int, vector<int>, greater<int>> pQueue;

int DFS(int y, int x);

int main()
{
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	cin >> len;

	for (int i = 0; i < len; i++)
	{
		string str;
		cin >> str;

		for (int j = 0; j < len; j++)
		{
			field[i][j] = (str[j] == '1');
		}
	}

	// DFS
	for (int y = 0; y < len; y++)
	{
		for (int x = 0; x < len; x++)
		{
			if (!visited[y][x] && field[y][x])
			{
				// �湮 Ƚ���� �켱���� ť�� ����
				pQueue.push(DFS(y, x));
			}
		}
	}

	// ������ ���
	cout << pQueue.size() << '\n';

	// �켱���� ť ��� ���
	while (!pQueue.empty())
	{
		cout << pQueue.top() << '\n';
		pQueue.pop();
	}
}

int DFS(int y, int x)
{
	int count = 1;
	visited[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= len || nx >= len) continue;

		if (field[ny][nx] && !visited[ny][nx])
		{
			// �湮 Ƚ���� ����
			count += DFS(ny, nx);
		}
	}

	return count;
}