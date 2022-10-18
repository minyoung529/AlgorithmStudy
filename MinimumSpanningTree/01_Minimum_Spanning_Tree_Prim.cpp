#include<iostream>
#include<queue>
#include<vector>
using namespace std;

// 방문했는지 체크 
bool check[10001];
// 노드들에 각 연결된 노드, 가중치를 저장 
vector<pair<int, int>> nodes[10001];
// 인접했던 노드, 가중치를 저장 
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main()
{
	int vCnt, lCnt, result = 0;
	cin >> vCnt >> lCnt;

	for (int i = 0; i < lCnt; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;

		// a, b와 연결된 간선을 각각 저장해준다  
		nodes[a].push_back({ w,b });
		nodes[b].push_back({ w,a });
	}

	// 임의의 시작점 
	// pq.top().first => 가중치
	// pq.top().second => 노드 
	pq.push({ 0,1 });

	while (vCnt)
	{
		int cost = pq.top().first;
		int n = pq.top().second;
		pq.pop();

		// 방문하지 않은 노드이면 
		if (!check[n])
		{
			// 방문하고 cost값 올려준다 
			check[n] = true;
			result += cost;
			--vCnt;

			for (int i = 0; i < nodes[n].size(); i++)
			{
				// 방문하지 않은 노드들은 
				if (!check[nodes[n][i].second])
				{
					// 가중치를 first로 우선순위 큐에 넣어준다 
					pq.push({ nodes[n][i].first, nodes[n][i].second });
				}
			}
		}
	}

	cout << result;
}
