#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int main()
{
	ull target;
	cin >> target;

	ull left = 1;
	ull right = target;
	ull mid = 0;

	while (pow(left, 2) <= pow(right, 2))
	{
		mid = (left + right) / 2;

		if ((pow(mid, 2) > target))
		{
			right = mid - 1;
		}
		else if (pow(mid, 2) < target)
		{
			left = mid + 1;
		}
		else break;
	}

	while (pow(mid, 2) < target)
		mid++;

	cout << mid;
}
