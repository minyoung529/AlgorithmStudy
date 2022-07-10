#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int PrinterQueue(int len, int target, vector<int> printer)
{
	queue<int> pq;

	for (int i : printer) pq.push(i);
	sort(printer.begin(), printer.end(), less<int>());

	while (!printer.empty())
	{
		if (pq.front() < printer.back())
		{
			pq.push(pq.front());
			pq.pop();

			if (target == 0)
				target = pq.size();
		}
		else
		{
			pq.pop();
			printer.pop_back();

			if (target == 0)
				return (len - pq.size());
		}

		target--;
	}

	return 0;
}

int main()
{
	int orderLen;
	int result[100];
	cin >> orderLen;

	for (int i = 0; i < orderLen; i++)
	{
		int len;
		int target;
		vector<int> printer;

		cin >> len >> target;

		for (int j = 0; j < len; j++)
		{
			int input;
			cin >> input;
			printer.push_back(input);
		}

		result[i] = PrinterQueue(len, target, printer);
	}

	for (int i = 0; i < orderLen; i++)
		printf("%d\n", result[i]);
}