#include<bits/stdc++.h>
using namespace std;

int parent[1001];

struct Edge
{
	int s, e, val;
	Edge(int a, int b, int c)
	{
		s = a;
		e = b;
		val = c;
	}

	bool operator < (const Edge& b) const
	{
		return val < b.val;
	}
};

int Find(int a);
bool Union(int a, int b);

int main()
{
	vector<Edge> Ed;
	int n, m, a, b, c, cnt = 0, res = 0;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}

	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b >> c;
		Ed.push_back(Edge(a, b, c));
	}

	sort(Ed.begin(), Ed.end());

	for (int i = 0; i < m; i++)
	{
		// 같은 집합이 아니라면
		if (Union(Ed[i].s, Ed[i].e))
		{
			res += Ed[i].val;
		}
	}

	cout << res;
}

int Find(int a)
{
	while (parent[a] != a)
	{
		a = parent[a];
	}

	return a;
}

bool Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a != b)
	{
		parent[a] = b;
		return true;
	}
	return false;
}