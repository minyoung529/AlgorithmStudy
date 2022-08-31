#include<iostream>
#include<math.h>
using namespace std;

bool is_prime_number(long long);

int main()
{
	int len;
	cin >> len;

	for (int i = 0; i < len; i++)
	{
		long long input;
		cin >> input;

		while (!is_prime_number(input++)) {}

		cout << input - 1 << endl;
	}
}

bool is_prime_number(long long num)
{
	long long sqrtNum = sqrt(num);

	for (long long i = 2; i <= sqrtNum; i++)
	{
		if (num % i == 0)
			return false;
	}

	return (num > 1);
}