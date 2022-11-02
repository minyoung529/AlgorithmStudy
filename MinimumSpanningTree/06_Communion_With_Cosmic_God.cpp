#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ulli;

// ��ġ�� ���̵� ���� ����ü
struct Node
{
	pair<int, int> pos;
	int id;
};

// ���� ����ü
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

// ���� �� ������ �Ÿ� ���ϱ�
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

	// �� ����� ��ġ�� �Է� �޴´�
	for (int i = 1; i <= vCnt; i++)
	{
		cin >> x >> y;

		parents[i] = i;
		nodes.push_back(Node{ {x, y}, i });
	}

	// �̹� ������ ��θ� �Է� �޴´�
	for (int i = 0; i < lCnt; i++)
	{
		cin >> x >> y;
		uni(x, y);
	}

	// ���� �� �ִ� ��� ������ �����
	// Edge ���Ϳ� �ִ´�
	for (int i = 0; i < vCnt; i++)
	{
		for (int j = 0; j < vCnt; j++)
		{
			if (i == j) continue;

			double dist = GetDist(nodes[i].pos, nodes[j].pos);
			edges.push_back({ nodes[i].id, nodes[j].id, dist });
		}
	}

	// �������� ����
	// ũ�罺Į
	sort(edges.begin(), edges.end());

	// ����Ŭ�� ������ �ʰ� ����ġ�� ����
	for (int i = 0; i < edges.size(); i++)
	{
		if (uni(edges[i].a, edges[i].b))
		{
			result += edges[i].dist;
		}
	}

	// �Ҽ��� ��° �ڸ����� ���
	cout << fixed;
	cout.precision(2);
	cout << result;
}
