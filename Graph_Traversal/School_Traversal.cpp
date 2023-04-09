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

int MST()
{
	int res = 0;

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

	// parents �ʱ�ȭ 
	for (int i = 0; i <= vCnt; i++)
		parents[i] = i;

	for (int i = 0; i < lCnt + 1; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		edges.push_back({ a,b,1-w });
	}

	// ����ġ�� �������� �������� ���� 
	sort(edges.begin(), edges.end());
	min = MST();


	for (int i = 0; i <= vCnt; i++)
		parents[i] = i;

	sort(edges.begin(), edges.end(), greater<Edge>());
	max = MST();

	//cout << max << ' ' << min;
	cout << max * max - min * min;
}
