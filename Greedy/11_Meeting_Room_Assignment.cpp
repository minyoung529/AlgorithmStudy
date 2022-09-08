#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef unsigned long long int ulli;

int main()
{
	int len, answer = 0;
	ulli endTime = 0;
	// first => end Time, second => start Time
	vector<pair<ulli, ulli>> times;

	cin >> len;

	for (int i = 0; i < len; i++)
	{
		ulli startTime, endTime;
		cin >> startTime;
		cin >> endTime;
		times.push_back({ endTime, startTime });
	}
	
	// endTime�� �������� ����
	sort(times.begin(), times.end());

	for (int i = 0; i < len; i++)
	{
		// ȸ�ǰ� ������ �ð����� ���ų� ���� ���� ȸ�Ǹ� ������ �� �ִ�
		if (endTime <= times[i].second)
		{
			// ������ �ð� ����
			endTime = times[i].first;
			answer++;
		}
	}

	cout << answer;
}