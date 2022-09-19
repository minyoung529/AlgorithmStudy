#include<iostream>
using namespace std;

int main()
{
	int len;
	string str;
	int sum = 0;

	cin >> len >> str;

	for (char c : str)
	{
		// char to int
		sum += c - '0';
	}

	cout << sum;
}
