#include <iostream>
using namespace std;

int main()
{
	string formula;
	int num = 0, answer = 0;
	bool isMinus = false;

	cin >> formula;

	for (int i = 0; i < formula.size(); i++)
	{
		if (isdigit(formula[i]))
		{
			num *= 10;
			num += formula[i] - '0';
		}
		else
		{
			// '-'�� �� ���� ���� �� ���ٸ� �׳� ���갪 ����
			if (!isMinus)
				answer += num;

			// ���� �� �ִٸ� ��ȣ�� ���̱� ������
			// �����̵��� ����
			else
				answer -= num;

			if (!isMinus && formula[i] == '-')
				isMinus = true;

			num = 0;
		}
	}

	if (isMinus) num *= -1;
	answer += num;

	cout << answer;
}