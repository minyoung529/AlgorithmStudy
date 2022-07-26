#include<iostream>
#include<queue>
#include<string>

using namespace std;

int main()
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pQueue;
	int orderLen;
	string result = "";
	cin >> orderLen;

	for (int i = 0; i < orderLen; i++)
	{
		int input;
		cin >> input;

		if (input != 0)
		{
			pQueue.push(make_pair(abs(input), input));
		}
		else
		{
			if (pQueue.empty())
			{
				result += "0\n";
			}
			else
			{
				result += to_string(pQueue.top().second) + '\n';
				pQueue.pop();
			}
		}
	}

	cout << result;
}