#include<iostream>
using namespace std;

int arr[500000];

int main()
{
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	int len, x, coprimeCount = 0;
	long long sum = 0;

	cin >> len;

	for (int i = 0; i < len; i++)
		cin >> arr[i];

	cin >> x;

	for (int i = 0; i < len; i++)
	{
		int a = arr[i];
		int b = x;

		if (a > b) swap(a, b);

		// �ִ������� ��Ŭ���� ȣ�������� ����
		while (b != 0)
		{
			int temp = a % b;
			a = b;
			b = temp;
		}

		// �� ���� �ִ� ������� 1�̶��
		if (a == 1)
		{
			coprimeCount++;
			sum += arr[i];
		}
	}

	// ��� ���
	cout << sum / (double)coprimeCount;
}