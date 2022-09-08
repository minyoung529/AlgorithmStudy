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
		// ��ǥ �ݾ� �޼� �ߴٸ� �ݺ��� ������
		if (k == 0) break;

		// ������ ��ǥ ���� ��ǥ �ݾ׺��� ũ�ٸ� ���� ��������
		if (coins[i] > k) continue;

		int div = k / coins[i];

		// ������ �����̶�� ���� k�� �� ������ ��� ����ϰ�,
		// �׷��� �ʴٸ� �ִ��� ����� �� �ִ� �ٷ� �� �ܰ������
		int offset = (i == 0) ? 0 : -1;

		k -= (div + offset) * coins[i];
		answer += div + offset;

		for (int j = i - 1; j >= 0; j--)
		{
			if (j < 0) break;

			// ���� ����� �� �ִ� ��ŭ ����� ��
			// �Ŀ� ������ �ʰ� ����� �� ������
			if ((k - coins[i]) % coins[j] == 0)
			{
				// ������� ���� �ϳ��� ���ε� �ٲ��ش�
				k -= coins[i];
				answer++;
				break;
			}
		}
	}

	cout << answer;
}