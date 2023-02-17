#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<pair<unsigned int, unsigned int>> arr;

int main()
{
	int len, start = 0, end = 0, maxVal = 0;
	priority_queue<unsigned int, vector<unsigned int>, greater<unsigned int>> pQueue;
	cin >> len;

	for (int i = 0; i < len; i++)
	{
		int start, end;
		cin >> start >> end;
		arr.push_back({ start, end });
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < arr.size(); i++)
	{
		if (!pQueue.empty())
		{
			// ÀÛÀº °Ç »­
			while (!pQueue.empty() && pQueue.top() <= arr[i].first)
			{
				pQueue.pop();
			}

			if (pQueue.size() + 1 == maxVal && end == arr[i].first)
			{
				end = arr[i].second;
			}
		}

		if (pQueue.size() + 1 > maxVal)
		{
			start = arr[i].first;

			if (!pQueue.empty())
				end = min(pQueue.top(), arr[i].second);
			else
				end = arr[i].second;

			maxVal = pQueue.size() + 1;
		}
		

		pQueue.push(arr[i].second);
	}

	cout << maxVal << '\n' << start << ' ' << end;
}