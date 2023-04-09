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
	int count = 0;
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