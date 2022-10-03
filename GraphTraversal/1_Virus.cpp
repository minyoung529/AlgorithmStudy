#include <bits/stdc++.h>
using namespace std;

bool arr[101][101];
bool visited[101];
int cnt, len, answer;

void DFS(int n);

int main()
{
	cin >> cnt >> len;

	while (len--)
	{
		int num1, num2;
		cin >> num1 >> num2;

		arr[num1][num2] = arr[num2][num1] = true;
	}

	DFS(1);
	cout << answer;
}

// DFS
void DFS(int n)
{
	visited[n] = true;

	for (int i = 2; i <= cnt; i++)
	{
		// �湮���� �ʾҰ� ����� ��Ҹ�
		if (arr[n][i] && !visited[i])
		{
			DFS(i);
			answer++;
		}
	}
}