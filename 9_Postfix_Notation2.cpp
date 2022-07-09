#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int len;
	double numbers[26] = { 0, };
	int result = 0;
	string input;
	stack<double> stack;

	cin >> len;
	cin >> input;

	for (int i = 0; i < len; ++i)
		cin >> numbers[i];

	for (int i = 0; i < input.size(); ++i)
	{
		if (isalpha(input[i]))
			stack.push(numbers[input[i] - 'A']);
		
		else
		{
			double val2 = stack.top();
			stack.pop();
			double val1 = stack.top();
			stack.pop();

			switch (input[i])
			{
			case '+':
				stack.push(val1 + val2);
				break;
			case '-':
				stack.push(val1 - val2);
				break;
			case '*':
				stack.push(val1 * val2);
				break;
			case '/':
				stack.push(val1 / (double)val2);
				break;
			}
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << (double)stack.top();
}