#include<iostream>
using namespace std;

bool IsPalindrome(string str);
bool IsPseudoPalindrome(string str, int remove);

int main()
{
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	
	int testCnt;
	cin >> testCnt;

	while (testCnt--)
	{
		string input;
		int answer = 0;
		cin >> input;

		// �Ӹ���� ����� �ٷ� 0 ���
		if (IsPalindrome(input))
		{
			cout << 0 << endl;
			continue;
		}

		// �ƴ϶��...
		for (int i = 0; i < input.size() / 2 + 1; i++)
		{
			int ri = input.size() - i - 1;

			if (answer > 0)break;
			if (input[i] == input[ri])continue;

			// �ϳ��� ���� �� �� �������� ���� ���ٸ�
			if (input[i] == input[ri - 1] || input[ri] == input[i + 1])
			{
				// ���� �Ӹ�������� �˻��ϰ� �´ٸ� 1, �ƴ϶�� 2
				if (IsPseudoPalindrome(input, ri) || IsPseudoPalindrome(input, i))
				{
					answer = 1;
				}
				else
				{
					answer = 2;
				}
			}
			else
			{
				// �׳� �� �������� ���� �ƹ� ���� ���ٸ� 2
				answer = 2;
			}
		}

		cout << answer << endl;
	}
}

bool IsPalindrome(string str)
{
	for (int i = 0; i < str.size() / 2 + 1; i++)
	{
		int ri = str.size() - i - 1;

		if (str[i] != str[ri])
		{
			return false;
		}
	}

	return true;
}

bool IsPseudoPalindrome(string str, int remove)
{
	str.erase(str.begin() + remove);
	return (IsPalindrome(str));
}