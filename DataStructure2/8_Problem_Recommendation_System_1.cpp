#include<iostream>
#include<map>
#include<set>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	set<pair<int, int>> set;
	map<int, pair<int, int>> map;
	int orderCount;
	int problem, difficulty;

	cin >> orderCount;

	for (int i = 0; i < orderCount; i++)
	{
		cin >> problem >> difficulty;
		set.insert({ difficulty, problem });
		map.insert({ problem, { difficulty, problem } });
	}

	cin >> orderCount;

	for (int i = 0; i < orderCount; i++)
	{
		string order;

		cin >> order >> problem;

		if (order[0] == 'a')
		{
			cin >> difficulty;
			set.insert({ difficulty, problem });
			map.insert({ problem, { difficulty, problem } });
		}

		else if (order[0] == 'r')
		{
			if (problem == 1)
				cout << (*--set.end()).second << '\n';

			else
				cout << (*set.begin()).second << '\n';
		}

		else if (order[0] == 's')
			set.erase(map[problem]);
	}
}