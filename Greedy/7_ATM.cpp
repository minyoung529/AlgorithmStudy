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

	for (int i = 0; i < len; i++)
	{
		cin >> prices[i];
		myCost += prices[i];
	}

	sort(prices.begin(), prices.end(), greater<int>());

	if (len / 3 > 0)
	{
		for (int i = 2; i < len; i += 3)
		{
			myCost -= prices[i];
		}
	}

	cout << myCost;
}