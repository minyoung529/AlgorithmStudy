#include<iostream>
using namespace std;

int main()
{
	int num, answer = 0;
	cin >> num;

	// 5�� �������� ������ 3�� ����
	while (num % 5 && num > 0)
	{
		num -= 3;
		answer++;
	}

	// 5�� ���������ٸ� ���� ���
	if (num % 5 == 0)
		cout << answer + num / 5;
	else
		cout << -1;
}