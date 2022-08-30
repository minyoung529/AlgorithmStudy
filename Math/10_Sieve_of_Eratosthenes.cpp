#include<iostream>
using namespace std;

int main()
{
	int n, k;

	cin >> n >> k;
	bool check[1001] = { false, };

	for (int i = 2; i <= n; i++)
	{
		if (check[i]) continue;

		int p = i;

		while (p <= n)
		{
			if (!check[p])
			{
				check[p] = true;

				if (--k == 0)
				{
					cout << p << endl;
					return 0;
				}
			}

			p += i;
		}
	}
}