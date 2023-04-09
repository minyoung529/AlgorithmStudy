#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>

#define INF 987654321;
#define RED 1
#define BLUE 2
using namespace std;

int v, e;
vector<vector<int>> graph;
vector<int> isVisited;

void input()
{
	cin >> v >> e;
	graph.assign(v + 1, vector<int>(0, 0));
	isVisited.assign(v + 1, false);

	for (int i = 0; i < e; i++)
	{
		int s, e;
		cin >> s >> e;
		graph[s].emplace_back(e);
		graph[e].emplace_back(s);
	}
}

void DFS(int cur)
{
	// ���� �湮���� ���� �����̶�� ���������� ĥ�Ѵ�.
	if (!isVisited[cur])
		isVisited[cur] = RED;

	// ���� ������ ����� �������� ��� �湮
	for (int i = 0; i < graph[cur].size(); i++)
	{
		int next = graph[cur][i];

		// ���� �湮���� ���� �����̶�� ���� ������ �ݴ�Ǵ� ������ ĥ�Ѵ�.
		if (!isVisited[next])
		{
			if (isVisited[cur] == RED)   isVisited[next] = BLUE;
			else if (isVisited[cur] == BLUE) isVisited[next] = RED;
			DFS(next);
		}
	}
}

// �̺� �׷������� Ȯ���ϴ� �Լ�
bool isBipartite()
{
	// ��� �������� ���ƺ��鼭 ������ �������� ���� ������ Ȯ��
	for (int cur = 1; cur <= v; cur++)
	{
		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i];
			// ���� ������ ������ ���� ���ٸ� �̺� �׷����� �ƴ�
			if (isVisited[cur] == isVisited[next])   return false;
		}
	}
	return true;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int testcase;
	cin >> testcase;

	while (testcase--)
	{
		input();
		// �׷����� ��� ����Ǿ� �ִٴ� ������ ������, �湮 ó���� ���� ���� �����鿡 DFS ����
		for (int i = 1; i <= v; i++)
			if (!isVisited[i])
				DFS(i);

		if (isBipartite())
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}