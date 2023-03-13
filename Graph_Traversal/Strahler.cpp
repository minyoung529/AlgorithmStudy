#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> childs[1001];

struct strahler
{
	int maxVal = 0, number = 0;

	void Add(int val)
	{
		if (maxVal < val)
		{
			number = 1;
			maxVal = val;
		}
		else if (maxVal == val)
		{
			number++;
		}
	}

	int GetLevel()
	{
		if (number == 1)
			return maxVal;
		else
			return maxVal + 1;
	}
};

int main()
{
	int tCnt, tNum, vCnt, lCnt;
	cin >> tCnt;

	while (tCnt--)
	{
		int res = 0;
		cin >> tNum >> vCnt >> lCnt;

		queue<pair<int, int>> q;
		int parents[1001] = { 0, };
		strahler strahlers[1001] = {};

		for (int i = 1; i <= 1000; i++)
			childs[i].clear();

		for (int i = 0; i < lCnt; i++)
		{
			int a, b;
			cin >> a >> b;

			childs[a].push_back(b);
			parents[b]++;
		}

		for (int i = 1; i <= vCnt; i++)
		{
			if (parents[i] == 0)
			{
				q.push({ i, 1 });
			}
		}

		while (!q.empty())
		{
			int top = q.front().first;
			int level = q.front().second;
			q.pop();

			for (int i : childs[top])
			{
				strahlers[i].Add(level);

				if (--parents[i] == 0)
				{
					q.push({ i, strahlers[i].GetLevel() });
				}
			}

			res = max(res, level);
		}

		cout << tNum << ' ' << res << '\n';
	}
}