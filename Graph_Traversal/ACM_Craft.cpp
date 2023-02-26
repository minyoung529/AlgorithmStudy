#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int weight[100001];
int parents[100001];
long long minVals[100001];
vector<int> nodes[100001];
queue<pair<int, int>> q;

int main()
{
	int tCnt, vCnt, lCnt, a, b, n;
	cin >> tCnt;

	while (tCnt--)
	{
		fill_n(parents, 100001, 0);
		fill_n(minVals, 100001, 0);

		for (int i = 0; i < 100001; i++)
			nodes[i].clear();

		cin >> vCnt >> lCnt;

		for (int i = 1; i <= vCnt; i++)
			cin >> weight[i];

		// 정점 입력
		for (int i = 0; i < lCnt; i++)
		{
			cin >> a >> b;
			parents[b]++;			// 부모의 개수 갱신
			nodes[a].push_back(b);	// 자식 저장
		}

		cin >> n;

		// 진입이 0인 노드 추가
		for (int i = 1; i <= vCnt; i++)
		{
			if (parents[i] == 0)
			{
				q.push({ i, 0 });
				minVals[i] = weight[i];
			}
		}

		int v = 0, level = 0;

		while (!q.empty())
		{
			v = q.front().first;
			level = q.front().second;
			q.pop();

			for (int child : nodes[v])
			{
				if (--parents[child] == 0)
				{
					q.push({ child, level + 1 });
				}

				minVals[child] = max(minVals[v] + weight[child], minVals[child]);
			}
		}

		cout << minVals[n] << '\n';
	}
}