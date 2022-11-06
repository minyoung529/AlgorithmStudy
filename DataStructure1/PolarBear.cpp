#include<bits/stdc++.h>
using namespace std;

int main()
{
	stack<char> stack;
	string str;
	int result = 0;
	int len;
	cin >> len >> str;

	for (int i = 0; i < str.size(); i++)
	{
		// () => pop
		if (str[i] == '(' && !stack.empty() && stack.top() == ')')
		{
			stack.pop();
		}

		// ( => push
		else if (str[i] == '(')
		{
			stack.push(str[i]);
		}

		// )( => pop
		else if (str[i] == ')' && !stack.empty() && stack.top() == '(')
		{
			stack.pop();
		}
		
		// ) => push
		else if (str[i] == ')')
		{
			stack.push(str[i]);
		}

		result = max((int)stack.size(), result);
	}

	// 원하는 문자열을 만들지 못했다면 
	if (stack.size() > 0)
		cout << -1;
	else
		cout << result;
}
