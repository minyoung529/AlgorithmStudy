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
		if (k == 0) break;			// ��ǥ �ݾ� �޼��ߴٸ� �׸�!

		int div = k / coins[i];		// ��ǥ �ݾ� / ���� ����
		k -= div * coins[i];
		answer += div;
	}

	cout << answer;
}