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
		// 10이 넘으면 그 나머지로
		if (calc > 10)
			calc %= 10;

		calc += table[str[i] - 'A'];
	}

	// 짝수라면 패배
	if (calc % 2 == 0)
		cout << "You're the winner?";

	// 홀수라면 승리
	else
		cout << "I'm a winner!";
}