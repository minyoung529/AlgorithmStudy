#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

long long game, win, winPercent;
long long bsearch();

int main()
{
	cin >> game >> win;
	winPercent = ((win * 100 / game));

	if (winPercent >= 99)
		cout << -1;
	else
		cout << bsearch();
}

long long bsearch()
{
	long long left = 1;
	long long right = 1000000000;

	while (left <= right)
	{
		long long mid = (left + right) / 2;
		long long tempwin = (((win + mid) * 100 / (game + mid)));

		if (tempwin <= winPercent)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	if (left > game)
		return -1;

	return left;
}
