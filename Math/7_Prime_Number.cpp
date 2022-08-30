#include<iostream>
using namespace std;

int main()
{
	int m, n;
	int min = 0, sum = 0;

	cin >> m >> n;

	for (int i = m; i <= n; i++)
	{
		int count = 0;

		for (int j = 1; j <= i; j++)
		{
			if (count > 2) break;
			if (i % j == 0) ++count;
		}

		if (count == 2)
		{
			if (sum == 0) min = i;
			sum += i;
		}
	}

	if (sum == 0)
		cout << -1;

	else
		cout << sum << endl << min;
}
