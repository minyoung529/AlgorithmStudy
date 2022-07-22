#include<iostream>
#include<stack>
using namespace std;

int main()
{
	string input;
	stack<char> stack;
	int result = 0;
	int factor = 1;

	cin >> input;

	for (int i = 0; i < input.size(); ++i)
	{
		if (input[i] == '(' || input[i] == '[')
		{
			stack.push(input[i]);

			if (input[i] == '(')
				factor *= 2;

			else
				factor *= 3;
		}
		else
		{
			if (stack.empty() || (input[i] == ')' && stack.top() == '[') || (input[i] == ']' && stack.top() == '('))
			{
				cout << 0;
				return 0;
			}

			if (input[i] == ')')
			{
				if (input[i - 1] == '(')
					result += factor;

				factor /= 2;
			}
			else if (input[i] == ']')
			{
				if (input[i - 1] == '[')
					result += factor;

				factor /= 3;
			}

			stack.pop();
		}
	}

	if (!stack.empty())
		cout << 0;
	else
		cout << result;
}

// ()()()
// 6

// ((()))
// 8

// (()[[]])([])
// 2 * (2 + 3*3)
// 2*2 + 2*3*3
// 28