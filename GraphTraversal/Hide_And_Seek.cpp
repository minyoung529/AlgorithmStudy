#include<iostream>
#include<queue>
using namespace std;

#define MAX 100000
bool visited[100001];
int start, endV, answer = 0;

void set(int f, int s, queue<pair<int, int>>& q)
{
	if (f < 0 || f > MAX || visited[f]) return;

	visited[f] = true;
	q.push({ f , s });
}

int main()
{
	cin >> start >> endV;

	queue<pair<int, int>> q;

	q.push({ start, 0 });

	if (start < endV)
	{
		while (!q.empty())
		{
			pair<int, int> top = q.front();
			
			// ã�Ҵٸ� ����  
			if (top.first == endV)break;
			q.pop();

			// 1�� �Ŀ� ��ǥ ���� 
			set(top.first + 1, top.second + 1, q);
			set(top.first - 1, top.second + 1, q);
			set(top.first * 2, top.second + 1, q);
		}
	}
	else
	{
		cout << start - endV;
		return 0;
	}

	cout << q.front().second;
}
