#include<iostream>
using namespace std;

int main()
{
	string str[5];

	for (int i = 0; i < 5; i++)
	{
		cin >> str[i];
	}

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			// �迭�� J��°���� ū �ε����� ������� �ʴ´�.
			if (str[j].size() > i)
			{
				cout << str[j][i];
			}
		}
	}
}