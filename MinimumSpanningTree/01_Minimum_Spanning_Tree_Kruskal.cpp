#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int parents[1001];

// ���� 
struct Edge
{
	int a, b, w;

	bool operator < (const Edge& e) const
	{
		return w < e.w;
	}
};

//
int find(int v)
{
	vector<int> vec;

	// �ֻ��� �θ� ã�� 
	while (v != parents[v])
	{
		vec.push_back(v);
		v = parents[v];
	}

	// ���ƴ� �θ���� �θ�  �ֻ��� ���� 
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

	// parents �ʱ�ȭ 
	for (int i = 0; i <= vCnt; i++)
		parents[i] = i;

	for (int i = 0; i < lCnt; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;

		edges.push_back({ a,b,w });
	}

	// ����ġ�� �������� �������� ���� 
	sort(edges.begin(), edges.end());

	for (int i = 0; i < edges.size(); i++)
	{
		// fN => N�� �ֻ��� �θ� 
		int fa = find(edges[i].a), fb = find(edges[i].b);

		// ���� �θ� ���� �ʴٸ� 
		// = ����Ŭ�� ������ �ʴ´ٸ�  
		if (fa != fb)
		{
			// ����� ������Ű��
			// union
			result += edges[i].w;
			parents[fa] = fb;
		}
	}

	cout << result;
}
