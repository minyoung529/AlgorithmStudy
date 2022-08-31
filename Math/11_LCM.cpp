#include<iostream>
using namespace std;

long long get_gcd(int, int);
long long get_lcm(int, int);

int main()
{
	int len;
	cin >> len;

	for (int i = 0; i < len; i++)
	{
		int a, b;
		cin >> a >> b;

		if (a > b) swap(a, b);
		cout << get_lcm(a, b) << '\n';
	}
}

long long get_lcm(int a, int b)
{
	return ((long long)a * b / get_gcd(a, b));
}

long long get_gcd(int a, int b)
{
	while (b != 0)
	{
		long long r = a % b;
		a = b;
		b = r;
	}

	return a;
}