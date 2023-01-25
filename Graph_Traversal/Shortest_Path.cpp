#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node
{
	int cost; int to;
	bool operator < (const Node& node) const { return cost < node.cost; }
};

vector<Node> node[1001];
int dist[1001];
bool visited[1001];

int main()
{
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	int vCnt, lCnt, start, end, cost;
	priority_queue<Node> pq;
	cin >> vCnt >> lCnt;

	for (int i = 0; i < lCnt; i++)
	{
		cin >> start >> end >> cost;
		node[start].push_back({ cost, end });
	}

	cin >> start >> end;
	pq.push({ 0, start });

	for (int i = 0; i <= vCnt; i++)
		dist[i] = 1000000000;

	dist[start] = 0;

	// dijkstra
	while (!pq.empty())
	{
		int v = pq.top().to;
		int cost = pq.top().cost;
		pq.pop();

		if (dist[v] < cost) continue;

		for (Node n : node[v])
		{
			if (dist[n.to] > dist[v] + n.cost)
			{
				dist[n.to] = dist[v] + n.cost;
				pq.push({ dist[n.to], n.to });
			}
		}
	}

	cout << dist[end];
}