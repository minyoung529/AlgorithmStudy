#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int n;
	priority_queue<int, vector<int>, greater<int>> pQueue;

	cin >> n;

	for (int i = 0; i < n * n; ++i)
	{
		int input;
		cin >> input;
		pQueue.push(input);

		if (pQueue.size() > n)
		{
			pQueue.pop();
		}
	}

	cout << pQueue.top();
}