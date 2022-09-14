#include<iostream>
#include<queue>
using namespace std;

typedef unsigned long long int ulli;

int main()
{
	int testCnt;
	cin >> testCnt;

	while (testCnt-- > 0)
	{
		int len, input;
		ulli answer = 0;
		priority_queue<ulli, vector<ulli>, greater<ulli>> pQueue;
		cin >> len;

		for (int i = 0; i < len; i++)
		{
			cin >> input;
			pQueue.push(input);
		}

		while (pQueue.size() > 1)
		{
			ulli val1, val2;

			// ���� ���� �͵���� ���
			val1 = pQueue.top();
			pQueue.pop();
			val2 = pQueue.top();
			pQueue.pop();

			// ��ġ�� ���� �ٽ� �־��ְ�
			// ������� ��ġ��
			pQueue.push(val1 + val2);
			answer += val1 + val2;
		}

		cout << answer << endl;
	}
}