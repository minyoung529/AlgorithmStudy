#include<iostream>
using namespace std;

int main()
{
	int n, k;

	cin >> n >> k;
	bool check[1001] = { false, };

	for (int i = 2; i <= n; i++)
	{
		// �̹� üũ�� ���ڸ� continue
		if (check[i]) continue;

		int p = i;

		while (p <= n)
		{
			// �̹� üũ�� ���ڸ� üũ���� �ʴ´�
			if (!check[p])
			{
				check[p] = true;

				// K��° ���� ���� ��
				if (--k == 0)
				{
					cout << p << endl;
					return 0;
				}
			}

			// p�� ����� ������� (ex) 3, 6, 9...)
			p += i;
		}
	}
}