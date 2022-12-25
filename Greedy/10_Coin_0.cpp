#include <iostream>
using namespace std;

int main()
{
	int len, k, answer = 0, coins[10] = { 0, };
	cin >> len >> k;

	for (int i = 0; i < len; i++)
	{
		cin >> coins[i];
		if (coins[i] > k)len--;
	}

	for (int i = len - 1; i >= 0; i--)
	{
		if (k == 0) break;			// 목표 금액 달성했다면 그만!

		int div = k / coins[i];		// 목표 금액 / 현재 동전
		k -= div * coins[i];
		answer += div;
	}

	cout << answer;
}