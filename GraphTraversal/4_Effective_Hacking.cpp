#include<bits/stdc++.h>
using namespace std;

vector<int> maxes;
vector<int> m[10001];
bool visited[10001];

int DFS(int n)
{
	int count = 0;
	visited[n] = true;

	for (int i = 0; i < m[n].size(); i++)
	{
		int node = m[n][i];

		// ��ŷ���� ���� ���� �湮
		// ��ŷ�� ������ count�� �ø���
		if (!visited[node])
		{
			count += DFS(node);
			count++;
		}
	}

	// ���� ��ŷ Ƚ�� ��ȯ
	return count;
}

int main()
{
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	int cnt, len, maxValue = 0;
	cin >> cnt >> len;

	for (int i = 0; i < len; i++)
	{
		int a, b;
		cin >> a >> b;

		m[b].push_back(a);
	}

	for (int i = 1; i <= cnt; i++)
	{
		int temp = DFS(i);

		if (maxValue <= temp)
		{
			// �ִ� ���ϱ�
			if (maxValue < temp)
			{
				maxValue = temp;
				maxes.clear();
			}

			// �ִ� �迭�� �ִ´�
			maxes.push_back(i);
		}

		fill_n(visited, 10001, false);
	}

	for (int i : maxes)
		cout << i << ' ';
}