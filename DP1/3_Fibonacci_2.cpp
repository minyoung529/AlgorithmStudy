#include<iostream>
using namespace std;

typedef unsigned long long int ulli;

int main()
{
	ulli len;
	ulli a = 0, b = 1;
	cin >> len;

	if (len < 1)
	{
		cout << len;
		return 0;
	}

	for (int i = 0; i < len - 1; i++)
	{
		ulli temp = b;
		b = a + b;
		a = temp;
	}

	cout << b;
}