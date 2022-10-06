#include<bits/stdc++.h>
using namespace std;

bool arr[100001];

int main()
{
	queue<pair<int, int>> queue;
	int start, target, answer = 0;;
	cin >> start >> target;

	// first > ���� ��, second > ���� Ƚ��
	queue.push({ start, 0 });

	while (!queue.empty())
	{
		pair<int, int> pair = queue.front();

		arr[pair.first] = true;

		// ã�Ҵٸ� ����
		if (pair.first == target)
		{
			break;
		}

		queue.pop();

		// ū > ������ �� ���� X
		if (pair.first <= target && !arr[pair.first + 1] && start < target)
		{
			queue.push({ pair.first + 1, pair.second + 1 });
		}

		if (pair.first - 1 >= 0 && !arr[pair.first - 1])
		{
			queue.push({ pair.first - 1, pair.second + 1 });
		}

		// ū > ������ �� ���� X
		// +1 ����: -1�� �� �� �ִ� ������ �������!!
		if (pair.first * 2 <= target + 1 && !arr[pair.first * 2] && start < target)
		{
			queue.push({ pair.first * 2, pair.second + 1 });
		}
	}

	cout << queue.front().second;
}