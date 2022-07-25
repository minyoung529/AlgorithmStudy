#include<iostream>
#include<string>
#include<vector>
using namespace std;

class PQueue
{
private:
	vector<int> heap;
public:
	void push(int value)
	{
		heap.push_back(value);
		int curIndex = static_cast<int>(heap.size()) - 1;

		while (curIndex >= 0)
		{
			int parent = (curIndex - 1) / 2;

			// �������
			if (heap[parent] < heap[curIndex])
			{
				swap(heap[parent], heap[curIndex]);
				curIndex = parent;
			}
			else break;
		}
	}

	int pop()
	{
		int value = heap[0];
		heap[0] = heap.back();
		heap.pop_back();

		int curIndex = 0;
		int next = 1;

		// top���� �����ؼ� ��������
		// => ������
		while (next <= static_cast<int>(heap.size()) - 1)
		{
			if (next < static_cast<int>(heap.size()) - 1)
			{
				// ����, ������ �ڽ� ��
				if (heap[next] < heap[next + 1])
					++next;
			}

			// ������ �� ũ�ٸ� ����
			if (heap[next] < heap[curIndex]) break;
			else swap(heap[next], heap[curIndex]);

			curIndex = next;
			next = next * 2 + 1;
		}

		return value;
	}

	bool empty()
	{
		return (heap.size() == 0);
	}
};

int main()
{
	int orderLen;
	string result = "";
	PQueue pQueue;
	cin >> orderLen;

	for (int i = 0; i < orderLen; i++)
	{
		int input;
		cin >> input;

		if (input != 0)
		{
			pQueue.push(input);
		}
		else
		{
			if (pQueue.empty())
			{
				result += "0\n";
			}
			else
			{
				result += to_string(pQueue.pop()) + '\n';
			}
		}
	}

	cout << result;
}