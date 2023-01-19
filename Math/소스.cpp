#include<iostream>
using namespace std;
unsigned long long int a, b, c;

int main()
{
	cin >> a >> b >> c;

	for (int i = 0; i < b; i++)
	{
		a = ((a % c) * (a % c)) % c;
	}

	cout << a;
}