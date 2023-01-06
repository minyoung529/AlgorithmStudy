#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Edge
{
	int a, b, w;

	bool operator < (const Edge& e) const
	{
		return w < e.w;
	}
};
struct Node
{
	int to, w;
};

int parents[1000];
unsigned long long result = 0, worst = 0;

bool visited[1000];
vector<Node> nodes[1000];
vector<Edge> edges;

int find(int v)
{
	vector<int> vec;

	while (v != parents[v])
	{
		vec.push_back(v);
		v = parents[v];
	}

	for (int i : vec)
		parents[i] = v;

	return v;
}

void DFS(int v, int weight)
{
	visited[v] = true;

	for (int i = 0; i < nodes[v].size(); i++)
	{
		if (!visited[nodes[v][i].to])
		{
			DFS(nodes[v][i].to, weight + nodes[v][i].w);
		}
	}

	worst = max(worst, (unsigned long long)weight);
}

int main()
{
	int vCnt, lCnt, a, b, w;

	cin >> vCnt >> lCnt;

	for (int i = 0; i <= vCnt; i++) parents[i] = i;
	for (int i = 0; i < lCnt; i++)
	{
		cin >> a >> b >> w;
		edges.push_back({ a,b,w });
	}

	sort(edges.begin(), edges.end());

	for (int i = 0; i < edges.size(); i++)
	{
		Edge edge = edges[i];
		int fa = find(edge.a), fb = find(edge.b);

		if (fa != fb)
		{
			result += edge.w;
			parents[fa] = fb;

			nodes[edge.a].push_back({ edge.b, edge.w });
			nodes[edge.b].push_back({ edge.a, edge.w });
		}
	}

	for (int i = 0; i < vCnt; i++)
	{
		for (int i = 0; i < vCnt; i++)
			visited[i] = false;

		DFS(i, 0);
	}

	cout << result << '\n' << worst;
}