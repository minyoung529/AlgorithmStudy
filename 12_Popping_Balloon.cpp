#include<iostream>
#include<deque>
using namespace std;

int main()
{
	int len;
	int arr[1000] = { 0, };
	deque<pair<int, int>> deque;

	cin >> len;

	for (int i = 0; i < len; i++)
	{
		int value;
		cin >> value;

		pair<int, int> p(i + 1,value);
		deque.push_back(p);
	}

	for (int i = 0; i < len; i++)
	{
		int count = deque.front().second;
		arr[i] = deque.front().first;
		deque.pop_front();

		if (deque.empty())break;

		int offset = count > 0 ? -1 : 0;

		for (int j = 0; j < abs(count) + offset; j++)
		{
			pair<int, int> value;

			if (count > 0)
			{
				value = deque.front();
				deque.pop_front();
				deque.push_back(value);
			}
			else
			{
				value = deque.back();
				deque.pop_back();
				deque.push_front(value);
			}
		}
	}

	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
}