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

			// 가장 작은 것들부터 계산
			val1 = pQueue.top();
			pQueue.pop();
			val2 = pQueue.top();
			pQueue.pop();

			// 합치기 위해 다시 넣어주고
			// 비용으로 합치기
			pQueue.push(val1 + val2);
			answer += val1 + val2;
		}

		cout << answer << endl;
	}
}