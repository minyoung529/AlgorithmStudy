#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

int vCnt, len, parents[501] = { 0, };
int score[501];
int score_map[501];
unordered_map<int, bool> childs[501];
vector<int> results;

int main()
{
	int tCnt;
	cin >> tCnt;

	while (tCnt--)
	{
		results.clear();
		cin >> vCnt;

		for (int i = 0; i < vCnt; i++)
		{
			parents[i+1] = 0;
			childs[i+1].clear();
			cin >> score[i];
			score_map[score[i]] = i;
		}

		cin >> len;

		for (int i = 0; i < len; i++)
		{
			int a, b;
			cin >> a >> b;

			// A가 더 낮았다면 A가 높아질 차례
			if (score_map[a] > score_map[b])
			{
				parents[b]++;
				childs[a][b] = true;
			}
			else
			{
				parents[a]++;
				childs[b][a] = true;
			}
		}

		for (int i = 0; i < vCnt; i++)
		{
			for (int j = i + 1; j < vCnt; j++)
			{
				if (childs[score[j]].find(score[i]) == childs[score[j]].end())	// 만약 순위가 안 바뀌었다면 (찾을 수 없다면)
				{
					childs[score[i]][score[j]] = true;	// 여전히 더 큰 것
					parents[score[j]]++;
				}
			}
		}

		queue<int> q;

		for (int i = 1; i <= vCnt; i++)
		{
			if (parents[i] == 0)
				q.push(i);
		}

		while (!q.empty())
		{
			int top = q.front();
			results.push_back(top);
			q.pop();

			for (auto p : childs[top])
			{
				if (--parents[p.first] == 0)
				{
					q.push(p.first);
				}
			}
		}

		if (results.size() == vCnt)
		{
			for (int i : results)
				cout << i << ' ';
		}
		else
		{
			cout << "IMPOSSIBLE";
		}

		cout << '\n';
	}
}