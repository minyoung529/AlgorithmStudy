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
		// '<'라면 스택에 push
		if (input[i] == '<')
		{
			stk.push(input[i]);
		}

		// '>'라면 스택에 pop
		else if (input[i] == '>')
		{
			stk.pop();
		}

		// 괄호의 영향을 받지 않고, 공백이 아닐 때
		else if (stk.empty() && input[i] != ' ')
		{
			int start = i;

			// i를 공백까지 인덱스로
			while (i + 1 < input.size() && input[i + 1] != ' ' && input[i + 1] != '<') { ++i; }

			// i부터 start까지 역순 출력
			for (int j = i; j >= start; j--)
			{
				cout << input[j];
			}

			continue;
		}

		// 현재 문자 출력
		cout << input[i];
	}
}
