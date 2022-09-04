#include<iostream>
#include<math.h>
#include<string>
#include<string.h>
using namespace std;

#define LIMIT 1003002
bool check[LIMIT + 1];

bool IsPalindrome(int number);

int main()
{
	int number;
	cin >> number;

	memset(&check, true, sizeof(check));

	// 에라토스테네스의 체
	for (int i = 2; i <= sqrt(LIMIT); i++)
	{
		if (check[i])
		{
			for (int j = i * i; j <= LIMIT; j += i)
			{
				if (check[j])
				{
					check[j] = false;
				}
			}
		}
	}

	check[1] = false;

	while (true)
	{
		if (check[number] && IsPalindrome(number))
		{
			cout << number;
			return 0;
		}

		number++;
	}
}

bool IsPalindrome(int number)
{
	string str = to_string(number);

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] != str[str.size() - i - 1])
		{
			return false;
		}
	}

	return true;
}