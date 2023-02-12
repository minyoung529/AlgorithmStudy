#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

#define MAX 100000
int visited[100001];
int start, endV, answer = 0;
int minVal = 0, result = 0;

void set(int o, int f, int s, queue<pair<int, int>>& q)
{
	if (f < 0 || f > MAX) return;
	if (visited[f]) return;

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

			q.pop();
			visited[top.first]++;

			if (minVal == 0 && top.first == endV)
			{
				minVal = top.second;
			}

			if (minVal && minVal == top.second && top.first == endV)
				result++;

			//if (minVal && minVal < top.second)break;

			set(top.first, top.first + 1, top.second + 1, q);
			set(top.first, top.first - 1, top.second + 1, q);
			set(top.first, top.first * 2, top.second + 1, q);
		}
	}
	else
	{
		cout << start - endV << "\n1";
		return 0;
	}

	cout << minVal << '\n' << result;
}

// 4 9
// 2 1