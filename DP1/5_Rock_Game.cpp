#include<iostream>
using namespace std;

int main()
{
	int rock;
	bool isSk = false;
	cin >> rock;

	while (rock > 0)
	{
		// ������ ���̰ų�
		// ���� 3���� �������� ��, ��뿡�� ��ȸ�� ���ų�
		// ���� 3�� ������ ��
		if (rock - 1 == 0 || rock - 4 == 0 || rock - 6 == 0 || rock < 3)
			rock -= 1;
		else
			rock -= 3;

		isSk = !isSk;
	}

	(isSk) ? cout << "SK" : cout << "CY";
}