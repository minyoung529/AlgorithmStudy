#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ulli;

// 위치와 아이디를 가진 구조체
struct Node
{
	pair<int, int> pos;
	int id;
};

// 간선 구조체
struct Edge
{
	int a, b;
	double dist;

	bool operator < (const Edge&	 e) const
	{
		return dist < e.dist;
	}
};

int parents[1001];
vector<Node> nodes;
vector<Edge> edges;

// union-find
int find(int v)
{
	vector<int> memo;

	while (parents[v] != v)
	{
		v = parents[v];
		memo.push_back(v);
	}

	for (int i : memo)
		parents[i] = v;

	return v;
}
bool uni(int a, int b)
{
	int fa = find(a), fb = find(b);

	if (fa != fb)
	{
		parents[fa] = fb;
		return true;
	}

	return false;
}

// 점과 점 사이의 거리 구하기
double GetDist(pair<int, int> p1, pair<int, int> p2)
{
	return sqrt((ulli)pow(p1.first - p2.first, 2) + (ulli)pow(p1.second - p2.second, 2));
}

int main()
{
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int vCnt, lCnt, x, y;
	double result = 0;
	cin >> vCnt >> lCnt;

	// 각 노드의 위치를 입력 받는다
	for (int i = 1; i <= vCnt; i++)
	{
		cin >> x >> y;

		parents[i] = i;
		nodes.push_back(Node{ {x, y}, i });
	}

	// 이미 정해진 경로를 입력 받는다
	for (int i = 0; i < lCnt; i++)
	{
		cin >> x >> y;
		uni(x, y);
	}

	// 만들 수 있는 모든 간선을 만들어
	// Edge 벡터에 넣는다
	for (int i = 0; i < vCnt; i++)
	{
		for (int j = 0; j < vCnt; j++)
		{
			if (i == j) continue;

			double dist = GetDist(nodes[i].pos, nodes[j].pos);
			edges.push_back({ nodes[i].id, nodes[j].id, dist });
		}
	}

	// 오름차순 정렬
	// 크루스칼
	sort(edges.begin(), edges.end());

	// 사이클이 생기지 않게 가중치를 더함
	for (int i = 0; i < edges.size(); i++)
	{
		if (uni(edges[i].a, edges[i].b))
		{
			result += edges[i].dist;
		}
	}

	// 소수점 둘째 자리까지 출력
	cout << fixed;
	cout.precision(2);
	cout << result;
}
