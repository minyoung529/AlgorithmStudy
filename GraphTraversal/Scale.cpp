#include<iostream>
#include<vector>
using namespace std;

bool arr[2001][2001];
bool visited[2001];
void DFS(int v, bool fromTo);
int vCnt, lCnt, answer = 0;

int main()
{
	cin >> vCnt >> lCnt;

	for (int i = 0; i < lCnt; i++)
	{
		int from, to;
		cin >> from >> to;

		arr[from][to] = true;
	}

	for (int i = 1; i <= vCnt; i++)
	{
		// 정방향, 역방항 화살표를 모두 계산
		DFS(i, true); DFS(i, false);

		cout << vCnt - answer + 1 << '\n';

		fill_n(visited, vCnt + 1, false);
		answer = 0;
	}
}

// v => 방문한 정점
// fromTo => 정방향 화살표인지 역방향 화살표인지
void DFS(int v, bool fromTo)
{
	visited[v] = true;
	answer++;

	for (int i = 1; i <= vCnt; i++)
	{
		// 정방향은 정방향으로만, 역방향은 역방향으로만
		// 방문하지 않은 곳만 간다
		if (!visited[i] && ((fromTo && arr[v][i]) || !fromTo && arr[i][v]))
		{
			DFS(i, fromTo);
		}
	}
}