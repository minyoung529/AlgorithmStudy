#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ulli;

// 간선 구조체
struct Edge
{
	int a, b, w;

	bool operator < (const Edge& e) const
	{
		return w < e.w;
	}
};

int parents[1001];
bool isWoman[1001];
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

	for (int i : memo) parents[i] = v;

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

int main()
{
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int vCnt, lCnt, result = 0;
	cin >> vCnt >> lCnt;

	// 각 노드의 위치를 입력 받는다
	for (int i = 1; i <= vCnt; i++)
	{
		char c;
		cin >> c;

		isWoman[i] = (c == 'W');
		parents[i] = i;
	}

	for (int i = 0; i < lCnt; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;

		if (isWoman[a] != isWoman[b])
		{
			edges.push_back({ a,b,w });
		}
	}


	// 크루스칼
	sort(edges.begin(), edges.end());

	for (int i = 0; i < edges.size(); i++)
	{
		if (uni(edges[i].a, edges[i].b))
		{
			vCnt--;
			result += edges[i].w;
		}
	}

	if (vCnt == 1)
		cout << result;
	else
		cout << -1;
}