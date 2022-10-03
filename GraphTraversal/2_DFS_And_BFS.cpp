#include<bits/stdc++.h>
using namespace std;

bool arr[1001][1001];
bool visited[1001];

void DFS(int start);
void BFS(int start);
int cnt, len, start;

int main()
{
	cin >> cnt >> len >> start;

	while (len--)
	{
		int num1, num2;
		cin >> num1 >> num2;

		arr[num1][num2] = arr[num2][num1] = 1;
	}

	DFS(start);
	cout << endl;

	// ÃÊ±âÈ­
	fill_n(visited, 1001, false);
	BFS(start);
}

void DFS(int start)
{
	visited[start] = true;
	cout << start << " ";

	for (int i = 1; i <= cnt; i++)
	{
		if (arr[start][i] && !visited[i])
		{
			DFS(i);
		}
	}
}

void BFS(int start)
{
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		cout << x << " ";

		for (int i = 1; i <= cnt; i++)
		{
			if (arr[x][i] && !visited[i])
			{
				visited[i] = true;
				q.push(i);
			}
		}
	}
}