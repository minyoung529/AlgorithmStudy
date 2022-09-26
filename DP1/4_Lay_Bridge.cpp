#include<iostream>
using namespace std;

typedef unsigned long long int ulli;

ulli Fac(int n, int cnt)
{
	if (n <= 1 || cnt == 0) return 1;
	return n * Fac(n - 1, cnt - 1);
}

int main()
{
	int tCnt;
	cin >> tCnt;

	while (tCnt--)
	{
		int a, b;
		cin >> a >> b;

		if (b - a < a)
		{
			a = b - a;
		}

		cout << Fac(b, a) / Fac(a, a) << '\n';
	}
}