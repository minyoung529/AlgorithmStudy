#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	long long int a, b, v;
	cin >> a >> b >> v;

	int val = (v - a) / (a - b);
	int mod = (v - a) % (a - b);
	
	if (mod > 0)
	{
		val++;
	}

	cout << val + 1;
}