#include<bits/stdc++.h>
using namespace std;

struct Edge
{
	int a, b, w;
};

vector<Edge> vec;
int parent[1001];

int find(int v);
bool union_find(int a, int b);

int main()
{
	int vCnt, lCnt, tCnt;
	cin >> vCnt >> lCnt >> tCnt;

	// 간선 저장
	// 가중치는 1부터 lCnt까지
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

		// 크루스칼
		for (int i = 0; i < vec.size(); i++)
		{
			if (union_find(vec[i].a, vec[i].b))
			{
				cost += vec[i].w;
				count++;
			}
		}
		
		if (count == vCnt - 1)
			cout << cost << ' ';
		
		else // MST가 만들어지지 않았다면
		{
			// 남은 턴을 모두 0으로 만들고
			// 프로그램 종료
			for (int j = 0; j < tCnt - i; j++)
				cout << 0 << ' ';
			break;
		}
		
		vec.erase(vec.begin());
	}
}

int find(int v)
{
	vector<int> children;

	while (v != parent[v])
	{
		v = parent[v];
		children.push_back(v);
	}

	for (int i : children)
		parent[i] = v;

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