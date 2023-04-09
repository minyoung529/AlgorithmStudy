#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Edge
{
	int a, b, w;

	bool operator< (const Edge& e) const
	{
		return w < e.w;
	}
};

int parents[51];
vector<Edge> edges;
int len;

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
	int count = 0;
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
			count++;
		}
	}

	if (count == len - 1)
	{
		return res;
	}
	return -1;
}

int main()
{
	int sum = 0;
	cin >> len;

	for (int i = 0; i < len; i++)
		parents[i] = i;

	for (int i = 0; i < len; i++)
	{
		string str;
		cin >> str;

		for (int j = 0; j < str.size(); j++)
		{
			if (isalpha(str[j]))
			{
				if (isupper(str[j]))
				{
					edges.push_back({ i, j, str[j] - 'A' + 27 });
					sum += str[j] - 'A' + 27;
				}
				else
				{
					edges.push_back({ i, j, str[j] - 'a' + 1 });
					sum += str[j] - 'a' + 1;
				}
			}
		}
	}

	sort(edges.begin(), edges.end());
	int res = MST();

	if (res >= 0)
	{
		cout << sum - res;
	}
	else
	{
		cout << res;
	}
}