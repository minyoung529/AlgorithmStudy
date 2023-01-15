#include<iostream>
#include<vector>
#include <string.h>
using namespace std;

bool visited[501];
vector<int> vertices[501];
int lineCnt = 0, caseCnt = 0;

void DFS(int root);

int main()
{
	while (true)
	{
		int vCnt, lCnt, answer = 0;
		cin >> vCnt >> lCnt;
		if (vCnt == 0 && lCnt == 0)break;

		for (int i = 0; i < lCnt; i++)
		{
			int a, b;
			cin >> a >> b;

			vertices[a].push_back(b);
			vertices[b].push_back(a);
		}

		for (int i = 1; i <= vCnt; i++)
		{
			if (!visited[i])
			{
				lineCnt = 0;
				
				DFS(i);

				// 간선이 정상적인 트리 구조가 아니면
				if (!lineCnt)answer++;
			}
		}

		cout << "Case " << ++caseCnt << ": ";

		switch (answer)
		{
		case 0:
			cout << "No trees." << '\n';
			break;

		case 1:
			cout << "There is one tree." << '\n';
			break;

		default:
			cout << "A forest of " << answer << " trees." << '\n';
		}

		for (int i = 1; i <= vCnt; i++)
			vertices[i].clear();

		memset(visited, 0, sizeof(visited));
	}
}

void DFS(int root)
{
	visited[root] = true;

	for (int i = 0; i < vertices[root].size(); i++)
	{
		if (visited[vertices[root][i]])
		{
			--lineCnt;
		}
		else
		{
			++lineCnt;
			DFS(vertices[root][i]);
		}
	}
}