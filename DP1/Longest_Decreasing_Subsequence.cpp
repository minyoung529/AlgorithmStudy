#include<bits/stdc++.h>
using namespace std;

// first > value
// second > length
pair<int, int> arr[1000];

int main()
{
	int len, answer = 1, min = 1000;
	cin >> len;

	for (int i = 0; i < len; i++)
	{
		cin >> arr[i].first;
	}

	for (int i = 0; i < len; i++)
	{
		arr[i].second = 1;

		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[i])
			{
				// �� ������ ũ�ٸ�
				// �� ���̿� ���ؼ� �����ϰų� ���� ���� ������
				arr[i].second = max(arr[i].second, arr[j].second + 1);
				answer = max(answer, arr[i].second);
			}
		}
	}

	cout << answer;
}