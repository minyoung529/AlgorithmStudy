#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
	ll cnt, win;
	cin >> cnt >> win;

	ll rate = win * 100 / cnt;
	ll left = 1, right = cnt;

	if (rate >= 99)
	{
		cout << -1;
		return 0;
	}

	while (left <= right)
	{
		ll mid = (left + right) / 2;
		ll tmp = (win + mid) * 100 / (cnt + mid);

		if (tmp >= rate + 1)
			right = mid - 1;
		else
			left = mid + 1;
	}

	cout << left;
}