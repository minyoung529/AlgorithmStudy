#include<iostream>
#include<deque>
#include<queue>
#include<algorithm>
using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pQueue;

int main()
{
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	int len, l, input, prev = 1000000005, cnt = 0;

	cin >> len >> l;

	for (int i = 0; i < len; i++)
	{
		cin >> input;
		pQueue.push({ input, (len - i) });

		if (cnt < l)
		{
			cout << min(prev, input) << ' ';

			if (input <= prev)	// °»½Å
			{
				prev = input;
				cnt = 0;
			}
		}
		else
		{
			while (!pQueue.empty())
			{
				if ((len - pQueue.top().second) + l > i)
					break;

				pQueue.pop();
			}

			prev = pQueue.top().first;
			cnt = i - (len - pQueue.top().second);

			cout << prev << ' ';
		}

		cnt++;
	}
}