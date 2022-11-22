#include<bits/stdc++.h>
using namespace std;
typedef long long  ull;

pair<ull, int> arr[500000];	// first > value, second > start
ull oarr[500000];			// ���� ������

int main()
{
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	int len, limit;
	ull result = 0;
	cin >> len >> limit;

	for (int i = 0; i < len; i++)
	{
		cin >> arr[i].first;
		oarr[i] = arr[i].first;

		// ���� ��ġ�� 0�� ����
		arr[i].second = 0;
	}

	for (int i = 1; i < len; i++)
	{
		ull previous = arr[i - 1].first;

		if (previous + arr[i].first > limit)	// ���̸� ������ �� �Ѱ谪�� ������
		{
			// �� ������ �� + ���� ���� �Ѱ谪�� ���� �ʰ�
			// ���� ��ġ���� ��� ���̸� �߶��ش�
			for (int j = arr[i - 1].second; j < i; j++)
			{
				previous -= oarr[j];
				arr[i].second = j + 1;

				if (previous + arr[i].first <= limit)	// ���� �ʰ� �Ǹ� break
				{
					break;
				}
			}

			// �׷����� �Ѱ谪 ������ continue
			if (previous + arr[i].first > limit)
				continue;
		}
		else
		{
			arr[i].second = arr[i - 1].second;	// ���� ��ġ�� �� ���� ��ġ�� �����Ѵ�. (����)
		}

		// ����
		arr[i].first += previous;
		result = max(result, arr[i].first);
	}

	cout << result;
}