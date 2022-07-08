#include <iostream>
using namespace std;

// 스택 구현하기
int main()
{
	int orderLen = 0;
	int* stack;
	int top = -1;
	int size = 0;

	cin >> orderLen;
	stack = new int[100000];

	for (int i = 0; i < orderLen; i++)
	{
		string order;
		cin >> order;

		if (order == "push")
		{
			int value = 0;
			cin >> value;
			*(stack + ++top) = value;
		}

		else if (order == "top" || order == "pop")
		{
			if (top < 0)
				cout << -1 << endl;
			else
			{
				cout << *(stack + top) << endl;
				if (order == "pop") --top;
			}
		}

		else if (order == "size")
		{
			cout << top + 1 << endl;
		}

		else if (order == "empty")
		{
			cout << (int)(top < 0) << endl;
		}
	}
}