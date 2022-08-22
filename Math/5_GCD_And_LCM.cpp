#include<iostream>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	int gcf = 1, lcm = a*b;

	if (b > a) swap(a, b);

	for (int i = 2; i <= b; i++)
	{
		if (a % i == 0 && b % i == 0)
		{
			gcf = i;
		}
	}

	for (int i = a; i <= a * b; i++)
	{
		if (i % a == 0 && i % b == 0)
		{
			lcm = i;
			break;
		}
	}

	cout << gcf << '\n' << lcm;
}