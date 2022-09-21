#include<iostream>
using namespace std;

int main()
{
	int testCnt;
	cin >> testCnt;

	while (testCnt--)
	{
		string str;
		bool isFail = false;
		bool a = false, f = false, c = false;
		cin >> str;

		if (!(str.front() >= 'A' && str.front() <= 'F') || !(str.back() >= 'A' && str.back() <= 'F'))
		{
			isFail = true;
		}

		for (int i = 0; i < str.size(); i++)
		{
			if (isFail) break;

			// �� �� �ڸ��̰ų� A, F, C�� ��
			if (i == 0 || i == str.size() - 1 || str[i] == 'A' || str[i] == 'F' || str[i] == 'C')
			{
				if (str[i] == 'A' && !a)
				{
					a = (!f && !c);
					isFail = !a;
				}

				else if (str[i] == 'F' && !f)
				{
					f = (a && !c);
					isFail = !f;
				}

				else if (str[i] == 'C' && !c)
				{
					c = (a && f);
					isFail = !c;
				}
			}
			else
			{
				isFail = true;
			}
		}

		// a, f, c �� �ϳ��� ������ �ʾҴٸ�
		if (!a || !f || !c)
			isFail = true;

		if (isFail)
			cout << "Good" << '\n';
		else
			cout << "Infected!" << '\n';
	}
}