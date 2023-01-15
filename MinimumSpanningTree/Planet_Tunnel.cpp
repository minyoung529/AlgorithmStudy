#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

struct pos
{
	int num, x, y, z;

	bool operator < (const pos& e) const
	{
		return x < e.x;
	}
};
struct edge
{
	int a, b, w;

	bool operator < (const edge& e) const
	{
		return w < e.w;
	}
};
int parent[100000];
map<pair<int, int>, bool> selected;

int find(int v);
bool union_find(int a, int b);

int main()
{
	vector<pos> poses;
	vector<edge> edges;

	int len, cost = 0, i, x, y, z;
	cin >> len;

	for (i = 0; i < len; i++)
	{
		cin >> x >> y >> z;
		poses.push_back({ i, x, y, z });
		parent[i] = i;
	}

	sort(poses.begin(), poses.end(), [](pos p1, pos p2) {return p1.x < p2.x; });

	for (i = 0; i < len - 1; i++)
	{
		edges.push_back({ i, i + 1, abs(poses[i].x - poses[i + 1].x) });
	}

	sort(poses.begin(), poses.end(), [](pos p1, pos p2) {return p1.y < p2.y; });

	for (i = 0; i < len - 1; i++)
	{
		edges.push_back({ i, i + 1, abs(poses[i].y - poses[i + 1].y) });
	}

	sort(poses.begin(), poses.end(), [](pos p1, pos p2) {return p1.z < p2.z; });

	for (i = 0; i < len - 1; i++)
	{
		edges.push_back({ i, i + 1, abs(poses[i].z - poses[i + 1].z) });
	}

	sort(edges.begin(), edges.end());

	for (i = 0; i < edges.size(); i++)
	{
		if (union_find(edges[i].a, edges[i].b))
		{
			if (selected[{edges[i].a, edges[i].b}] || selected[{edges[i].b, edges[i].a}])continue;
			selected[{edges[i].a, edges[i].b}] = selected[{edges[i].b, edges[i].a}] = true;
			cost += edges[i].w;
		}
	}

	cout << cost;
}

int find(int v)
{
	while (v != parent[v])
		v = parent[v];

	return v;
}

bool union_find(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a != b)
	{
		parent[a] = b;
		return true;
	}

	return false;
}