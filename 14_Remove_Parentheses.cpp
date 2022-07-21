#include<iostream>
#include<algorithm>
#include<set>
#include<stack>
using namespace std;

set<string> results;
int startPos[10];
int endPos[10];
int pCount;

void GetParenthese(string input, int index, bool isRemove)
{
	if (index >= pCount)
	{
		input.erase(remove(input.begin(), input.end(), ' '), input.end());
		results.insert(input);
	}

	else
	{
		if (isRemove)
		{
			input.replace(startPos[index], 1, " ");
			input.replace(endPos[index], 1, " ");
		}

		GetParenthese(input, index + 1, true);
		GetParenthese(input, index + 1, false);
	}
}

int main()
{
	string input;
	cin >> input;
	pCount = count(input.begin(), input.end(), '(');

	stack<int> stack;

	for (int i = 0, count = 0; i < input.size(); ++i)
	{
		if (input[i] == '(')
		{
			startPos[count] = i;
			stack.push(count++);
		}

		else if (input[i] == ')')
		{
			endPos[stack.top()] = i;
			stack.pop();
		}
	}

	GetParenthese(input, 0, true);
	GetParenthese(input, 0, false);

	for (string str : results)
	{
		if (str == input)continue;
		printf("%s\n", str.c_str());
	}
}

// ((((a+b)))/(d))