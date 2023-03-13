#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<set>
using namespace std;

map<string, vector<string>> childs;
map<string, int> parents;

int main()
{
	vector<string> roots;
	priority_queue<string, vector<string>, greater<string>> q;
	int len;
	cin >> len;

	for (int i = 0; i < len; i++)
	{
		string s;
		cin >> s;
		parents[s] = 0;
		q.push(s);
	}

	cin >> len;

	for (int i = 0; i < len; i++)
	{
		string x, y;
		cin >> x >> y;

		parents[x]++;
		childs[y].push_back(x);
	}

	for (auto pair : parents)
	{
		if (pair.second == 0)
			roots.push_back(pair.first);
	}

	cout << roots.size() << '\n';

	for (string s : roots)
		cout << s << ' ';

	cout << '\n';

	while (!q.empty())
	{
		set<string> vec;
		string top = q.top();
		q.pop();

		for (auto child : childs[top])
		{
			if (parents[child] == parents[top] + 1)
				vec.insert(child);
		}

		cout << top << ' ' << vec.size() << ' ';

		for (string s : vec)
			cout << s << ' ';

		cout << '\n';
	}
}