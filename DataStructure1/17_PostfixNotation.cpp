#include<iostream>
#include<stack>
using namespace std;

int main()
{
	string input;
	string result;
	stack<char> stk;

	cin >> input;

	for (int i = 0; i < input.size(); i++)
	{
		// �ǿ������� ���
		if (isalpha(input[i]))
			result.push_back(input[i]);

		// �������� ���
		else
		{
			if (input[i] == '(' || stk.empty())
			{
				stk.push(input[i]);
			}

			else
			{
				// ������ �� ������
				while (!stk.empty())
				{
					// ���� ������ �켱���� > ���� ������ �켱���� => break
					if ((stk.top() == '(' && input[i] != ')') || (input[i] == '*' || input[i] == '/') && (stk.top() == '+' || stk.top() == '-')) break;

					if (!(stk.top() == '(' || stk.top() == ')'))
					{
						result.push_back(stk.top());
					}

					if (input[i] == ')' && stk.top() == '(')
					{
						stk.pop();
						break;
					}

					stk.pop();
				}

				stk.push(input[i]);
			}
		}
	}

	while (!stk.empty())
	{
		if (!(stk.top() == '(' || stk.top() == ')'))
		{
			result.push_back(stk.top());
		}

		stk.pop();
	}

	cout << result;
}

//  ((A+B)*C)/D
//  AB+C*D/


// (A+B*C*D*E+F)
// ABC*D*E*+F+

// A*B+(C+D*E+F)+G