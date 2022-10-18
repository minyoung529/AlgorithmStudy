#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int parents[1001];

// 간선 
struct Edge
{
	int a, b, w;

	bool operator < (const Edge& e) const
	{
		return w < e.w;
	}
};

// 최상위 부모 찾기 
int find(int v)
{
	vector<int> vec;

	while (v != parents[v])
	{
		vec.push_back(v);
		v = parents[v];
	}

	// 메모이제이션 
	for (int i : vec)
	{
		parents[i] = v;
	}

	return v;
}

int main()
{
	int vCnt, lCnt;
	long long int result = 0;
	vector<Edge> edges;

	cin >> vCnt >> lCnt;

	for (int i = 0; i <= vCnt; i++)
		parents[i] = i;

	for (int i = 0; i < lCnt; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;

		edges.push_back({ a,b,w });
	}

	// 가중치 기준 오름차순 정렬 
	sort(edges.begin(), edges.end());

	for (int i = 0; i < edges.size(); i++)
	{
		int fa = find(edges[i].a), fb = find(edges[i].b);

		// 사이클이 생기지 않는다면
		// 간선 선택  
		if (fa != fb)
		{
			result += edges[i].w;
			parents[fa] = fb;
		}
	}

	cout << result;
}
