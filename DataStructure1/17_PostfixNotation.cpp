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
		// 피연산자일 경우
		if (isalpha(input[i]))
			result.push_back(input[i]);

		// 연산자일 경우
		else
		{
			if (input[i] == '(' || stk.empty())
			{
				stk.push(input[i]);
			}

			else
			{
				// 스택이 빌 때까지
				while (!stk.empty())
				{
					// 현재 연산자 우선순위 > 스택 연산자 우선순위 => break
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