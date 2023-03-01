#include<iostream>
#include<vector>
using namespace std;

bool check[100001];
int place[100001];
int nodes[100001];
int team = 0;

void DFS(int n, int count)
{
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	place[n] = count;
	check[n] = true;

	if (place[nodes[n]] != 0)
	{
		check[nodes[n]] = true;

		//cout << n << ' ' << nodes[n] << ' ' << count - place[nodes[n]] + 1 << endl;
		team += count - place[nodes[n]] + 1;
	}
	else
	{
		if (!check[nodes[n]])
		{
			DFS(nodes[n], count + 1);
		}
	}

	place[n] = 0;
}

int main()
{
	int tCnt;
	cin >> tCnt;

	while (tCnt--)
	{
		int len, input;
		cin >> len;

		// RESET
		team = 0;

		for (int i = 1; i <= len; i++)
		{
			check[i] = false;
		}

		for (int i = 1; i <= len; i++)
		{
			cin >> nodes[i];
		}

		for (int i = 1; i <= len; i++)
		{
			if (check[i])continue;
			DFS(i, 1);
		}

		cout << len - team << '\n';
	}
}