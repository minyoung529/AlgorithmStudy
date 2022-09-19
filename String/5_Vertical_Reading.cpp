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
			// 배열의 J번째보다 큰 인덱스는 출력하지 않는다.
			if (str[j].size() > i)
			{
				cout << str[j][i];
			}
		}
	}
}