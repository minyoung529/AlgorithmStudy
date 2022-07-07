#include <iostream>
#include <stack>
using namespace std;

// 괄호 검사 구현하기
int main()
{
	stack<char> stack;
	int count = 0;
	cin >> count;

	for (int i = 0; i < count; i++)
	{
		bool isCorrect = true;
		string brackets;
		cin >> brackets;

		for (char c : brackets)
		{
			if (c == '(')
				stack.push(c);
			
			else
			{
				if (stack.empty())
				{
					isCorrect = false;
					break;
				}

				stack.pop();
			}
		}

		if (!stack.empty() || !isCorrect)
			cout << "NO" << endl;
		
		else
			cout << "YES" << endl;

		while (!stack.empty())
			stack.pop();
	}
}