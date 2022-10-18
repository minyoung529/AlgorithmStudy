#include<iostream>
#include<queue>
#include<vector>
using namespace std;

// �湮�ߴ��� üũ 
bool check[10001];
// ���鿡 �� ����� ���, ����ġ�� ���� 
vector<pair<int, int>> nodes[10001];
// �����ߴ� ���, ����ġ�� ���� 
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main()
{
	int vCnt, lCnt, result = 0;
	cin >> vCnt >> lCnt;

	for (int i = 0; i < lCnt; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;

		// a, b�� ����� ������ ���� �������ش�  
		nodes[a].push_back({ w,b });
		nodes[b].push_back({ w,a });
	}

	// ������ ������ 
	// pq.top().first => ����ġ
	// pq.top().second => ��� 
	pq.push({ 0,1 });

	while (vCnt)
	{
		int cost = pq.top().first;
		int n = pq.top().second;
		pq.pop();

		// �湮���� ���� ����̸� 
		if (!check[n])
		{
			// �湮�ϰ� cost�� �÷��ش� 
			check[n] = true;
			result += cost;
			--vCnt;

			for (int i = 0; i < nodes[n].size(); i++)
			{
				// �湮���� ���� ������ 
				if (!check[nodes[n][i].second])
				{
					// ����ġ�� first�� �켱���� ť�� �־��ش� 
					pq.push({ nodes[n][i].first, nodes[n][i].second });
				}
			}
		}
	}

	cout << result;
}
