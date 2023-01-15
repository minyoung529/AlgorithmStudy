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

// union-find
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

// 최대 비용 구하기
void DFS(int v, int weight)
{
	visited[v] = true;

	for (int i = 0; i < nodes[v].size(); i++)
	{
		if (!visited[nodes[v][i].to])
		{
			// 방문한 적 없다면, 비용을 더해서 다음 탐색 호출
			DFS(nodes[v][i].to, weight + nodes[v][i].w);
		}
	}

	// 최대 비용 계산
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

	// 크루스칼 알고리즘
	sort(edges.begin(), edges.end());

	for (int i = 0; i < edges.size(); i++)
	{
		Edge edge = edges[i];
		int fa = find(edge.a), fb = find(edge.b);

		if (fa != fb)
		{
			result += edge.w;
			parents[fa] = fb;

			// 각 노드에 연결된 정점, 간선을 저장
			nodes[edge.a].push_back({ edge.b, edge.w });
			nodes[edge.b].push_back({ edge.a, edge.w });
		}
	}

	// 0부터 N까지 경로를 계산
	for (int i = 0; i < vCnt; i++)
	{
		// 계속 visited 초기화
		for (int i = 0; i < vCnt; i++)
			visited[i] = false;

		DFS(i, 0);
	}

	cout << result << '\n' << worst;
}