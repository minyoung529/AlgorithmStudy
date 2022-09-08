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

	// 오름차순 정렬
	sort(losings.begin(), losings.end());

	// 홀수인 경우 가장 큰 수는 합치지 않는다
	int offset = (losings.size() % 2 == 1) ? -2 : -1;

	for (int i = 0; i < len / 2; i++)
	{
		unsigned long long int loss = losings[i] + losings[losings.size() - i + offset];

		// 최댓값으로 갱신
		if (answer < loss)
			answer = loss;
	}

	// 계산 안 했던 가장 큰 수와 비교
	if (answer < losings.back())
	{
		answer = losings.back();
	}

	cout << answer;
}