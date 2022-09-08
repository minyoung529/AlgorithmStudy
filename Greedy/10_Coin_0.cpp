#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int len, k, answer = 0;
	int coins[10];

	cin >> len >> k;

	for (int i = 0; i < len; i++)
		cin >> coins[i];

	for (int i = len - 1; i >= 0; i--)
	{
		// 목표 금액 달성 했다면 반복문 나가기
		if (k == 0) break;

		// 동전이 목표 남은 목표 금액보다 크다면 다음 동전으로
		if (coins[i] > k) continue;

		int div = k / coins[i];

		// 마지막 동전이라면 합이 k가 될 때까지 모두 사용하고,
		// 그렇지 않다면 최대한 사용할 수 있는 바로 전 단계까지만
		int offset = (i == 0) ? 0 : -1;

		k -= (div + offset) * coins[i];
		answer += div + offset;

		for (int j = i - 1; j >= 0; j--)
		{
			if (j < 0) break;

			// 만약 사용할 수 있는 만큼 사용할 때
			// 후에 남기지 않고 사용할 수 있으면
			if ((k - coins[i]) % coins[j] == 0)
			{
				// 사용하지 않은 하나의 코인도 바꿔준다
				k -= coins[i];
				answer++;
				break;
			}
		}
	}

	cout << answer;
}