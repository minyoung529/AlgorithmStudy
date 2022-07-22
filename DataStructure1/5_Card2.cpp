#include<iostream>
#include<queue>
using namespace std;

int main()
{
	queue<int> queue;
	bool isPop = true;
	int N;

	cin >> N;

	for (int i = 1; i <= N; i++)
		queue.push(i);

	while (queue.size() != 1)
	{
		if (isPop)
		{
			queue.pop();
		}
		else
		{
			int value = queue.front();
			queue.pop();
			queue.push(value);
		}

		isPop = !isPop;
	}

	cout << queue.front();
}