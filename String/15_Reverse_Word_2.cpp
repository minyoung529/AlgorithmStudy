#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main()
{
	string input;
	stack<char> stk;
	getline(cin, input);

	for (int i = 0; i < input.size(); i++)
	{
		// '<'��� ���ÿ� push
		if (input[i] == '<')
		{
			stk.push(input[i]);
		}

		// '>'��� ���ÿ� pop
		else if (input[i] == '>')
		{
			stk.pop();
		}

		// ��ȣ�� ������ ���� �ʰ�, ������ �ƴ� ��
		else if (stk.empty() && input[i] != ' ')
		{
			int start = i;

			// i�� ������� �ε�����
			while (i + 1 < input.size() && input[i + 1] != ' ' && input[i + 1] != '<') { ++i; }

			// i���� start���� ���� ���
			for (int j = i; j >= start; j--)
			{
				cout << input[j];
			}

			continue;
		}

		// ���� ���� ���
		cout << input[i];
	}
}
