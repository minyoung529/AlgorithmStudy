#include<bits/stdc++.h>
using namespace std;

struct Edge
{
	int a, b, w;
};

vector<Edge> vec;
int parent[1001];

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

int main()
{
	int vCnt, lCnt, tCnt;
	cin >> vCnt >> lCnt >> tCnt;

	for (int i = 0; i < lCnt; i++)
	{
		int a, b;
		cin >> a >> b;
		vec.push_back({ a, b, i + 1 });
	}

	for (int i = 0; i < tCnt; i++)
	{
		int count = 0;
		int cost = 0;

		for (int i = 0; i <= vCnt; i++)
			parent[i] = i;

		for (int i = 0; i < vec.size(); i++)
		{
			if (union_find(vec[i].a, vec[i].b))
			{
				cost += vec[i].w;
				count++;
			}
		}

		if (count == vCnt - 1)
		{
			cout << cost << ' ';
		}
		else
		{
			for (int j = 0; j < tCnt - i; j++)
				cout << 0 << ' ';
			break;
		}
		
		vec.erase(vec.begin());
	}
}