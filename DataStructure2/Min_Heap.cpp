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
			// ����ٸ� 0
			if (pQueue.empty())
			{
				cout << 0 << '\n';
			}
			else
			{
				// top(�ּڰ�) ����ϰ� pop
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