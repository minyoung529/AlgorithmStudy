#include<iostream>
#include<vector>
using namespace std;

vector<pair<int, int>> nodes[10001];
bool visited[10001];
bool parent[10001];
long long root, maxVal;
void DFS(int v, int length = 0);

int main()
{
	int len;
	cin >> len;

	for (int i = 0; i < len - 1; i++)
	{
		int par, chi, w;
		cin >> par >> chi >> w;

		nodes[par].push_back({ chi, w });
		nodes[chi].push_back({ par, w });
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

		DFS(p.first, length + p.second);
	}
}
