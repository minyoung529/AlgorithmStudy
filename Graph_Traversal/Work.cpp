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
	queue<long long> q;
	long long n, count, input, res = 0;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> weight[i] >> count;

		for (int j = 0; j < count; j++)
		{
			cin >> input;

			nodes[input].push_back(i);
			parents[i]++;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (parents[i] == 0)
		{
			minVals[i] = weight[i];
			q.push(i);
		}
	}

	while (!q.empty())
	{
		int top = q.front();
		q.pop();

		for (int i : nodes[top])
		{
			if (--parents[i] == 0)
			{
				q.push(i);
			}

			minVals[i] = max(minVals[top] + weight[i], minVals[i]);
			res = max(minVals[i], res);
		}

		res = max(minVals[top], res);
	}

	cout << res;
}