#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;

struct node
{
	int a; ull w;
};

// index에 연결된 노드를 모아놓는 변수
vector<node> arr[5001];

int main()
{
	int vCnt, lCnt;
	cin >> vCnt >> lCnt;

	for (int i = 0; i < vCnt - 1; i++)
	{
		int a, b;
		ull w;
		cin >> a >> b >> w;

		// 양방향 간선
		arr[a].push_back({ b,w });
		arr[b].push_back({ a,w });
	}

	for (int i = 0; i < lCnt; i++)
	{
		// BFS
		bool visited[5001];
		fill_n(visited, 5001, false);

		queue<int> q;
		int target, count = 0;
		ull usado;

		// 처음 탐색할 노드를 queue에 넣는다
		cin >> usado >> target;
		q.push(target);

		// queue가 빌 때까지
		while (!q.empty())
		{
			int node = q.front();
			q.pop();

			// 탐색하지 않은 곳이라면 => 탐색
			if (!visited[node])
			{
				visited[node] = true; // 방문했음을 체크

				// 인접한 노드들을 모두 탐색
				for (int j = 0; j < arr[node].size(); j++)
				{
					if (arr[node][j].w >= usado)
					{
						int n = arr[node][j].a;

						// 방문하지 않았다면 enque & count++
						if (!visited[n])
						{
							q.push(n);
							count++;
						}
					}
				}
			}
		}

		cout << count << endl;
	}
}