#include<iostream>
using namespace std;

bool is_prime(int);

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int len;
	int answer = 0;

	cin >> len;

	for (int i = 0; i < len; i++)
	{
		int input;
		cin >> input;

		if (is_prime(input))
			answer++;
	}

	cout << answer;
}

bool is_prime(int num)
{
	int count = 0;

	for (int i = 1; i <= num; i++)
	{
		if (count > 2) return false;
		if (num % i == 0) count++;
	}

	return (count == 2);
}
