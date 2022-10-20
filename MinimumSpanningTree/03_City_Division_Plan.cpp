#include<bits/stdc++.h>
using namespace std;

int parents[100001];

struct Edge
{
	int a, b, w;

	bool operator < (const Edge& e) const
	{
		return w < e.w;
	}
};

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

int main()
{
	int vCnt, lCnt;
	int maxVal = 0;
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

	// ũ�罺Į
	sort(edges.begin(), edges.end());

	for (int i = 0; i < edges.size(); i++)
	{
		int fa = find(edges[i].a), fb = find(edges[i].b);
		
		if (fa != fb)
		{
			result += edges[i].w;

			// ����ġ MAX�� ���ϱ�
			maxVal = max(maxVal, edges[i].w);
			parents[fa] = fb;
		}
	}

	// ��ü ��� - MAX ����ġ
	cout << result - maxVal;
}