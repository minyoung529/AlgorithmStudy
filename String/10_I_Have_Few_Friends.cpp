#include<iostream>
using namespace std;

int main()
{
	string str, target;
	int sameIndex = 0, sameCnt = 0;
	cin >> str >> target;

	for (int i = 0; i < str.size(); i++)
	{
		// ���ĺ��� �ƴϸ� ��� ����
		if (!isalpha(str[i]))
		{
			str.erase(str.begin() + i--);
		}
	}

	for (int i = 0; i < str.size(); i++)
	{
		for (int j = i; j < str.size(); j++)
		{
			// target�� 0���� �����ϱ� ������ idx => j - i
			if (str[j] == target[j - i])
			{
				// ���� ������ ������ target�� ���� �������
				// ����!
				if (++sameCnt == target.size())
				{
					break;
				}
			}
			else break;
		}

		if (sameCnt == target.size()) break;
	}

	cout << (sameCnt == target.size());
}