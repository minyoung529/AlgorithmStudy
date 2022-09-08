#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<unsigned long long int> losings;
	int len;
	unsigned long long int answer = 0;

	cin >> len;

	for (int i = 0; i < len; i++)
	{
		unsigned long long int input;
		cin >> input;
		losings.push_back(input);
	}

	// �������� ����
	sort(losings.begin(), losings.end());

	// Ȧ���� ��� ���� ū ���� ��ġ�� �ʴ´�
	int offset = (losings.size() % 2 == 1) ? -2 : -1;

	for (int i = 0; i < len / 2; i++)
	{
		unsigned long long int loss = losings[i] + losings[losings.size() - i + offset];

		// �ִ����� ����
		if (answer < loss)
			answer = loss;
	}

	// ��� �� �ߴ� ���� ū ���� ��
	if (answer < losings.back())
	{
		answer = losings.back();
	}

	cout << answer;
}