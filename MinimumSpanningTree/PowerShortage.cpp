#include<bits/stdc++.h>
using namespace std;

struct Edge
{
	int a, b, w;

	bool operator < (const Edge& e) const
	{
		return w < e.w;
	}
};

int parent[200001];

// union-find + memoization
int find(int v)
{
	vector<int> children;

	while (parent[v] != v)
	{
		v = parent[v];
		children.push_back(v);
	}

	for (int i : children)
	{
		parent[i] = v;
	}

	return v;
}

int main()
{
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	// testCase
	while (true)
	{
		int vCnt, lCnt;
		long long int total = 0, result = 0;
		vector<Edge> edges;

		cin >> vCnt >> lCnt;

		// terminate
		if (vCnt == 0) return 0;

		for (int i = 0; i <= vCnt; i++)
		{
			parent[i] = i;
		}

		// kruskal
		for (int i = 0; i < lCnt; i++)
		{
			int a, b, w;
			cin >> a >> b >> w;

			edges.push_back({ a,b,w });
			total += w;
		}

		sort(edges.begin(), edges.end());

		for (int i = 0; i < edges.size(); i++)
		{
			int fa = find(edges[i].a);
			int fb = find(edges[i].b);

			if (fa != fb)
			{
				parent[fa] = fb;
				result += edges[i].w;
			}
		}

		// max - min
		cout << total - result << '\n';
	}
}