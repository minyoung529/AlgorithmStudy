#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

vector<pii> nodes[100001];
bool visited[100001];

int main()
{
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	int vCnt, lCnt;
	int temp = 0;
	long long int total = 0, mstSum = 0;
	priority_queue<pii, vector<pii>, greater<pii>> pQueue;
	cin >> vCnt >> lCnt;

	for (int i = 0; i < lCnt; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		nodes[a].push_back({ w,b });
		nodes[b].push_back({ w,a });

		// 모든 간선의 가중치 더함
		total += w;
	}

	pQueue.push({ 0,1 });

	// 프림 알고리즘
	while (vCnt && !pQueue.empty())
	{
		int cost = pQueue.top().first;
		int node = pQueue.top().second;
		pQueue.pop();

		if (!visited[node])
		{
			mstSum += cost;
			vCnt--;
			visited[node] = true;

			for (int i = 0; i < nodes[node].size(); i++)
			{
				if (!visited[nodes[node][i].second])
				{
					pQueue.push({ nodes[node][i].first, nodes[node][i].second });
				}
			}
		}
	}

	// 모든 노드를 연결하지 못했다면
	if (vCnt > 0)
		cout << -1;
	else
		cout << total - mstSum;
}