#include<bits/stdc++.h>
using namespace std;

bool arr[100001];

int main()
{
	queue<pair<int, int>> queue;
	int start, target, answer = 0;;
	cin >> start >> target;

	// first > 현재 값, second > 연산 횟수
	queue.push({ start, 0 });

	while (!queue.empty())
	{
		pair<int, int> pair = queue.front();

		arr[pair.first] = true;

		// 찾았다면 종료
		if (pair.first == target)
		{
			break;
		}

		queue.pop();

		// 큰 > 작은일 땐 실행 X
		if (pair.first <= target && !arr[pair.first + 1] && start < target)
		{
			queue.push({ pair.first + 1, pair.second + 1 });
		}

		if (pair.first - 1 >= 0 && !arr[pair.first - 1])
		{
			queue.push({ pair.first - 1, pair.second + 1 });
		}

		// 큰 > 작은일 땐 실행 X
		// +1 이유: -1을 할 수 있는 범위를 만드려고!!
		if (pair.first * 2 <= target + 1 && !arr[pair.first * 2] && start < target)
		{
			queue.push({ pair.first * 2, pair.second + 1 });
		}
	}

	cout << queue.front().second;
}