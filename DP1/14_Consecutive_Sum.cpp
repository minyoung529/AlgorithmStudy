#include<bits/stdc++.h>
using namespace std;
vector<int> vec;

int main()
{
	int len, answer = -1001;
	cin >> len;
	vec.resize(len);

	for (int i = 0; i < len; i++)
	{
		cin >> vec[i];
		answer = max(vec[i], answer);
	}

	// �ִ��� ����� ���� ���
	if (answer > 0)
	{
		for (int i = 1; i < len; i++)
		{
			int previous = vec[i - 1];

			// ������ �� �̵��̶�� ����
			if (previous + vec[i] > 0)
			{
				vec[i] += previous;
			}
			// �ƴ϶�� ���� ����
			else
			{
				vec[i] = 0;
			}

			answer = max(answer, vec[i]);
		}
	}

	cout << answer;
}