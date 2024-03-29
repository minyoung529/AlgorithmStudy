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

	bool operator > (const Edge& e) const
	{
		return w > e.w;
	}
};

vector<Edge> edges;

//
int find(int v)
{
	vector<int> vec;

	// 최상위 부모 찾기 
	while (v != parents[v])
	{
		vec.push_back(v);
		v = parents[v];
	}

	// 거쳤던 부모들의 부모를  최상위 노드로 
	for (int i : vec)
	{
		parents[i] = v;
	}

	return v;
}

int MST()
{
	int res = 0;

	for (int i = 0; i < edges.size(); i++)
	{
		// fN => N의 최상위 부모 
		int fa = find(edges[i].a), fb = find(edges[i].b);

		// 둘의 부모가 같지 않다면 
		// = 사이클이 생기지 않는다면  
		if (fa != fb)
		{
			// 비용을 증가시키고
			// union
			res += edges[i].w;
			parents[fa] = fb;
		}
	}

	return res;
}

int main()
{
	int vCnt, lCnt;
	long long int min = 0, max = 0;

	cin >> vCnt >> lCnt;

	// parents 초기화 
	for (int i = 0; i <= vCnt; i++)
		parents[i] = i;

	for (int i = 0; i < lCnt + 1; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		edges.push_back({ a,b,1-w });
	}

	// 가중치를 기준으로 오름차순 정렬 
	sort(edges.begin(), edges.end());
	min = MST();


	for (int i = 0; i <= vCnt; i++)
		parents[i] = i;

	sort(edges.begin(), edges.end(), greater<Edge>());
	max = MST();

	//cout << max << ' ' << min;
	cout << max * max - min * min;
}
