#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int parents[32001];
vector<int> childs[32001];
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
	int vCnt, lCnt, a, b;
	cin >> vCnt >> lCnt;

	for (int i = 0; i < lCnt; i++)
	{
		cin >> a >> b;
		parents[b]++;
		childs[a].push_back(b);
	}

	for (int i = 1; i <= vCnt; i++)
	{
		if (parents[i] == 0)
			pq.push(i);
	}

	while (!pq.empty())
	{
		int top = pq.top();
		pq.pop();

		for (int i : childs[top])
		{
			if (--parents[i] == 0)
			{
				pq.push(i);
			}
		}

		cout << top << ' ';
	}
}