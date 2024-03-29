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
	int len, input;
	cin >> len;

	for (int i = 1; i <= len; i++)
	{
		cin >> weight[i];

		while (true)
		{
			cin >> input;
			if (input == -1) break;

			nodes[input].push_back(i);
			parents[i]++;
		}
	}

	for (int i = 1; i <= len; i++)
	{
		if (parents[i] == 0)
		{
			q.push({ i, 0 });
			minVals[i] = weight[i];
		}
	}

	while (!q.empty())
	{
		int top = q.front().first;
		int level = q.front().second;
		q.pop();

		for (int i : nodes[top])
		{
			if (--parents[i] == 0)
			{
				q.push({ i, level + 1 });
			}

			minVals[i] = max(minVals[top] + weight[i], minVals[i]);
		}
	}

	for (int i = 1; i <= len; i++)
	{
		cout << minVals[i] << '\n';
	}
}