#include <iostream>
#include <queue>
using namespace std;

// 요세푸스 문제
int main()
{
	int N, K;
	queue<int> queue;

	cin >> N >> K;
	cout << "<";

	for (int i = 1; i <= N; i++)
		queue.push(i);

	for (int i = 1; i <= N * K; i++)
	{
		if (i % K == 0)
		{
			if (i == N * K)
				cout << queue.front();
			else
				cout << queue.front() << ", ";

			queue.pop();
		}
		else
		{
			int value = queue.front();
			queue.pop();
			queue.push(value);
		}
	}

	cout << ">";
}