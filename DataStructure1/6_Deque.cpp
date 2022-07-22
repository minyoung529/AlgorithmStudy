#include <iostream>
using namespace std;
int deque[10000] = { -1, };

int main()
{
	int orderLen;
	int* pivot = &deque[5000];

	int rear = 0;
	int front = 0;

	cin >> orderLen;

	for (int i = 0; i < orderLen; ++i)
	{
		string order;
		cin >> order;

		if (order == "push_front")
		{
			int value;
			cin >> value;

			*(pivot + front--) = value;
		}

		else if (order == "push_back")
		{
			int value;
			cin >> value;

			*(pivot + ++rear) = value;
		}

		else if (order == "pop_front" || order == "front")
		{
			if (rear == front)
				cout << -1 << endl;
			else
			{
				cout << *(pivot + front + 1) << endl;

				if (order == "pop_front")
					++front;
			}
		}

		else if (order == "pop_back" || order == "back")
		{
			if (rear == front)
				cout << -1 << endl;
			else
			{
				cout << *(pivot + rear) << endl;

				if (order == "pop_back")
					--rear;
			}
		}

		else if (order == "size")
			cout << (rear - front) << endl;

		else if (order == "empty")
			cout << (int)(rear == front) << endl;
	}
}