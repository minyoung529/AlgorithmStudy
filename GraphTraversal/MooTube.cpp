#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;

struct node
{
	int a; ull w;
};

// index�� ����� ��带 ��Ƴ��� ����
vector<node> arr[5001];

int main()
{
	int vCnt, lCnt;
	cin >> vCnt >> lCnt;

	for (int i = 0; i < vCnt - 1; i++)
	{
		int a, b;
		ull w;
		cin >> a >> b >> w;

		// ����� ����
		arr[a].push_back({ b,w });
		arr[b].push_back({ a,w });
	}

	for (int i = 0; i < lCnt; i++)
	{
		// BFS
		bool visited[5001];
		fill_n(visited, 5001, false);

		queue<int> q;
		int target, count = 0;
		ull usado;

		// ó�� Ž���� ��带 queue�� �ִ´�
		cin >> usado >> target;
		q.push(target);

		// queue�� �� ������
		while (!q.empty())
		{
			int node = q.front();
			q.pop();

			// Ž������ ���� ���̶�� => Ž��
			if (!visited[node])
			{
				visited[node] = true; // �湮������ üũ

				// ������ ������ ��� Ž��
				for (int j = 0; j < arr[node].size(); j++)
				{
					if (arr[node][j].w >= usado)
					{
						int n = arr[node][j].a;

						// �湮���� �ʾҴٸ� enque & count++
						if (!visited[n])
						{
							q.push(n);
							count++;
						}
					}
				}
			}
		}

		cout << count << endl;
	}
}