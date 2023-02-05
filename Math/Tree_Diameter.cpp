#include<iostream>
#include<vector>
using namespace std;

vector<pair<int, int>> nodes[100001];
bool visited[100001];
long long root, maxVal;
void DFS(int v, int length = 0);

int main()
{
	int len, result = 0;
	cin >> len;

	for (int i = 0; i < len; i++)
	{
		int v;
		cin >> v;

		while (true)
		{
			int connected, length;

			cin >> connected;
			if (connected == -1)break;
			cin >> length;

			nodes[v].push_back({ connected, length });
		}
	}

	for (int i = 1; i <= len; i++) visited[i] = false;
	DFS(1);

	for (int i = 1; i <= len; i++) visited[i] = false;
	DFS(root);

	cout << maxVal;
}

void DFS(int v, int length)
{
	if (visited[v])return;

	if (length > maxVal)
	{
		root = v;
		maxVal = length;
	}

	visited[v] = true;

	for (pair<int, int> p : nodes[v])
	{
		if (visited[p.first])continue;

		length += p.second;

		DFS(p.first, length);
		length -= p.second;
	}
}
