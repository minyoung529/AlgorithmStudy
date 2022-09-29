#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

int V, E, start, u, v, w;
vector<pii> weight[20001];
const int INF = 987654321;
priority_queue<pii, vector<pii>, greater<pii>> pq;

vector<int> dijkstra(int start, int vertex);

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	cin >> V >> E >> start;

	for (int i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		weight[u].emplace_back(w, v);
	}

	vector<int> result = dijkstra(start, V + 1);

	for (int i = 1; i <= V; i++)
	{
		if (result[i] == INF) cout << "INF" << '\n';
		else cout << result[i] << '\n';
	}
}

vector<int> dijkstra(int start, int vertex)
{
	vector<int> dist(vertex, INF);
	pq.push({ 0, start });
	dist[start] = 0;

	while (!pq.empty())
	{
		int now = pq.top().second;
		int sToNow = pq.top().first;
		pq.pop();

		// 이미 최단 경로를 지났으면
		if (dist[now] != sToNow) continue;

		for (auto n : weight[now])
		{
			int neighbor = n.second;
			int nowToNeighbor = n.first;

			if (dist[neighbor] > nowToNeighbor + sToNow)
			{ 
				dist[neighbor] = nowToNeighbor + sToNow;
				pq.push(make_pair(dist[neighbor], neighbor));
			}
		}
	}

	return dist;
}