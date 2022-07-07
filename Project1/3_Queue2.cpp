#include <iostream>
using namespace std;

// Queue 구현하기
int main()
{
	int orderLen = 0;
	int front = -1, rear = -1;
	int* qPtr = new int[2000000];

	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	cin >> orderLen;

	for (int i = 0; i < orderLen; i++)
	{
		string order;
		cin >> order;

		if (order == "push")
		{
			int value = 0;
			cin >> value;
			*(qPtr + ++rear) = value;
		}

		else if (order == "front" || order == "pop")
		{
			if (front == rear)
				cout << -1 << "\n";
			else
			{
				cout << *(qPtr + front + 1) << "\n";

				if (order == "pop")
					front++;
			}
		}

		else if (order == "back")
		{
			if (front == rear)
				cout << -1 << "\n";
			else
				cout << *(qPtr + rear) << "\n";
		}

		else if (order == "size")
			cout << rear - front << "\n";

		else if (order == "empty")
			cout << (int)(front == rear) << "\n";
	}
}