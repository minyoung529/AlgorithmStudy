#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
	priority_queue<int, vector<int>, greater<int>> pQueue;
	int len;
	cin >> len;

	while (len--)
	{
		int x;
		cin >> x;

		if (x == 0)
		{
			// 비었다면 0
			if (pQueue.empty())
			{
				cout << 0 << '\n';
			}
			else
			{
				// top(최솟값) 출력하고 pop
				cout << pQueue.top() << '\n';
				pQueue.pop();
			}
		}
		else
		{
			pQueue.push(x);
		}
	}
}