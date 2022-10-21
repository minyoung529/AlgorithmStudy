#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

vector<pii> nodes[100001];
bool visited[100001];

int main()
{
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	int vCnt, lCnt;
	int temp = 0;
	long long int total = 0, mstSum = 0;
	priority_queue<pii, vector<pii>, greater<pii>> pQueue;
	cin >> vCnt >> lCnt;

	for (int i = 0; i < lCnt; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		nodes[a].push_back({ w,b });
		nodes[b].push_back({ w,a });

		total += w;
	}

	pQueue.push({ 0,1 });

	while (vCnt && !pQueue.empty())
	{
		int cost = pQueue.top().first;
		int node = pQueue.top().second;
		pQueue.pop();

		if (!visited[node])
		{
			mstSum += cost;
			vCnt--;
			visited[node] = true;

			for (int i = 0; i < nodes[node].size(); i++)
			{
				if (!visited[nodes[node][i].second])
				{
					pQueue.push({ nodes[node][i].first, nodes[node][i].second });
				}
			}
		}
	}

	if (vCnt > 0)
		cout << -1;
	else
		cout << total - mstSum;
}