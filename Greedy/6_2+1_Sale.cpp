#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cout.tie(NULL);  cin.tie(NULL);

	vector<int> prices;
	int len, i;
	long long int myCost = 0;

	cin >> len;
	prices.resize(100000);

	// 모든 가격을 더해준다.
	for (int i = 0; i < len; i++)
	{
		cin >> prices[i];
		myCost += prices[i];
	}

	// 내림차순으로 정렬
	sort(prices.begin(), prices.end(), greater<int>());

	if (len / 3 > 0)
	{
		// 세 개로 묶어 세번째 것만 빼준다.
		for (int i = 2; i < len; i += 3)
		{
			myCost -= prices[i];
		}
	}

	cout << myCost;
}