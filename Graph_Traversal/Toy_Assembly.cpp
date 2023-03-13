#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

vector<pair<int, int>> childs[101];
int store[101][101];
int parents[101];

int main()
{
	int vCnt, lCnt;
	cin >> vCnt >> lCnt;

	for (int i = 0; i < lCnt; i++)
	{
		int parent, child, amount;
		cin >> child >> parent >> amount;

		childs[parent].push_back({ child,amount });
		parents[child]++;
	}

	queue<int> q;

	for (int i = 1; i <= vCnt; i++)
	{
		if (parents[i] == 0)
		{
			q.push(i);
			parents[i] = -1;
		}
	}

	while (!q.empty())
	{
		int top = q.front();
		q.pop();

		for (pair<int, int> pair : childs[top])
		{
			if (--parents[pair.first] == 0)
			{
				q.push(pair.first);
			}

			if (parents[top] == -1)	// 기본 부품이면
			{
				store[pair.first][top] += pair.second;
			}
			else
			{
				// 아니면 누적시킴
				for (int i = 1; i <= 100; i++)
				{
					store[pair.first][i] += store[top][i] * pair.second;
				}
			}
		}
	}

	// 기본 부품만 출력
	for (int i = 1; i <= 100; i++)
	{
		if (parents[i] != -1) continue;
		cout << i << ' ' << store[vCnt][i] << '\n';
	}
}