#include<iostream>
using namespace std;

int table[26] = { 3, 2, 1, 2, 3, 3,	3, 3, 1, 1, 3, 1, 3, 3 ,1, 2, 2, 2, 1, 2, 1, 1, 2, 2, 2, 1 };

int main()
{
	string str;
	int calc = 0;
	cin >> str;

	for (int i = 0; i < str.size(); i++)
	{
		// 10�� ������ �� ��������
		if (calc > 10)
			calc %= 10;

		calc += table[str[i] - 'A'];
	}

	// ¦����� �й�
	if (calc % 2 == 0)
		cout << "You're the winner?";

	// Ȧ����� �¸�
	else
		cout << "I'm a winner!";
}