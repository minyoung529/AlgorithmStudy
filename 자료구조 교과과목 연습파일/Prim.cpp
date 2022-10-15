#include<bits/stdc++.h>
using namespace std;

bool check[30];

struct Edge
{
	int n, val;

	Edge(int a, int b)
	{
		n = a;
		val = b;
	}

	// 
	bool operator<(const Edge& b) const
	{
		return (val > b.val);
	}
};

int main()
{
	priority_queue<Edge> q;
	vector<pair<int, int>> node[30];

	int n, m, input1, input2, val, answer = 0;

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> input1 >> input2 >> val;
		node[input1].push_back({ input2, val });
		node[input2].push_back({ input1, val });
	}

	q.push(Edge(1, 0));

	while (!q.empty())
	{
		Edge temp = q.top();
		q.pop();

		int n = temp.n;
		int cost = temp.val;

		if (!check[n])
		{
			check[n] = true;
			answer += cost;

			for (int i = 0; i < node[n].size(); i++)
			{
				if (!check[node[n][i].first])
				{
					q.push({ node[n][i].first, node[n][i].second });
				}
			}
		}
	}

	cout << answer;
}