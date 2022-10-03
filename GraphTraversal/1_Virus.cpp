#include <bits/stdc++.h>
using namespace std;

bool arr[101][101];
bool visited[101];
int cnt, len, answer;

void DFS(int n);

int main()
{
	cin >> cnt >> len;

	while (len--)
	{
		int num1, num2;
		cin >> num1 >> num2;

		arr[num1][num2] = arr[num2][num1] = true;
	}

	DFS(1);
	cout << answer;
}

// DFS
void DFS(int n)
{
	visited[n] = true;

	for (int i = 2; i <= cnt; i++)
	{
		// 방문하지 않았고 연결된 요소를
		if (arr[n][i] && !visited[i])
		{
			DFS(i);
			answer++;
		}
	}
}