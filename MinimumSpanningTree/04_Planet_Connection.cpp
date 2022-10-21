#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

// 가중치를 저장하는 2차원 배열
vector<int> weights[1000];
// 선택했는지 체크하는 배열
bool visited[1000];
long long int result = 0;

int main()
{
	int vCnt;
	cin >> vCnt;

	for (int i = 0; i < vCnt; i++)
	{
		weights[i].resize(vCnt);

		for (int j = 0; j < vCnt; j++)
		{
			cin >> weights[i][j];
		}
	}

	priority_queue<pii, vector<pii>, greater<pii>> pQueue;
	pQueue.push({ 0, 0 });

	// 프림 알고리즘
	while (vCnt)
	{
		int cost = pQueue.top().first;
		int node = pQueue.top().second;
		pQueue.pop();

		// 연결되지 않은 노드들만
		if (!visited[node])
		{
			visited[node] = true;
			result += cost;
			vCnt--;

			for (int i = 0; i < weights[node].size(); i++)
			{
				if (!visited[i])
				{
					pQueue.push({ weights[node][i], i });
				}
			}
		}
	}

	cout << result;
}