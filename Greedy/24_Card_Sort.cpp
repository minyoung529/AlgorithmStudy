#include<iostream>
#include<queue>
using namespace std;

int main()
{
	int len;
	long long int answer = 0;
	priority_queue<int, vector<int>, greater<int>> pQueue;
	cin >> len;

	for (int i = 0; i < len; i++)
	{
		int input;
		cin >> input;
		pQueue.push(input);
	}

	while (pQueue.size() > 1)
	{
		int val1, val2;

		val1 = pQueue.top();
		pQueue.pop();

		val2 = pQueue.top();
		pQueue.pop();

		answer += (long long int)val1 + val2;
		pQueue.push(val1 + val2);
	}

	cout << answer;
}