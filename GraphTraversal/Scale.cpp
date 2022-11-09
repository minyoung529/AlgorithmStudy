#include<iostream>
#include<vector>
using namespace std;

bool arr[2001][2001];
bool visited[2001];
void DFS(int v, bool fromTo);
int vCnt, lCnt, answer = 0;

int main()
{
	cin >> vCnt >> lCnt;

	for (int i = 0; i < lCnt; i++)
	{
		int from, to;
		cin >> from >> to;

		arr[from][to] = true;
	}

	for (int i = 1; i <= vCnt; i++)
	{
		// ������, ������ ȭ��ǥ�� ��� ���
		DFS(i, true); DFS(i, false);

		cout << vCnt - answer + 1 << '\n';

		fill_n(visited, vCnt + 1, false);
		answer = 0;
	}
}

// v => �湮�� ����
// fromTo => ������ ȭ��ǥ���� ������ ȭ��ǥ����
void DFS(int v, bool fromTo)
{
	visited[v] = true;
	answer++;

	for (int i = 1; i <= vCnt; i++)
	{
		// �������� ���������θ�, �������� ���������θ�
		// �湮���� ���� ���� ����
		if (!visited[i] && ((fromTo && arr[v][i]) || !fromTo && arr[i][v]))
		{
			DFS(i, fromTo);
		}
	}
}