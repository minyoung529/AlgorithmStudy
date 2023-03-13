#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

vector<int> childs[1001];
int parents[1001];
int res[1001];

int main()
{
	int vCnt, lCnt;
	cin >> vCnt >> lCnt;

	for (int i = 0; i < lCnt; i++)
	{
		int a, b;
		cin >> a >> b;

		parents[b]++;
		childs[a].push_back(b);
	}

	queue<pair<int, int>> q;

	for (int i = 1; i <= vCnt; i++)
	{
		if (parents[i] == 0)
			q.push({ i, 1 });
	}

	while (!q.empty())
	{
		int top = q.front().first;
		int level = res[top] = q.front().second;
		q.pop();

		for (int child : childs[top])
		{
			if (--parents[child] == 0)
			{
				q.push({ child, level + 1 });
			}
		}
	}

	for (int i = 1; i <= vCnt; i++)
	{
		cout << res[i] << ' ';
	}
}