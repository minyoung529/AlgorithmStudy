#include<iostream>
using namespace std;
typedef unsigned long long ull;

ull numbers[10];

int main()
{
	string str;
	cin >> str;

	for (ull i = 0; i < static_cast<ull>(str.size()); i++)
	{
		numbers[str[i] - '0']++;
	}

	for (int i = 9; i >= 0; i--)
	{
		for (int j = 0; j < numbers[i]; j++)
		{
			cout << i;
		}
	}
}