#include<iostream>
#include<stack>
using namespace std;

int main()
{
	string input;
	int count = 0;
	int result = 0;

	cin >> input;

	for (int i = 0; i < input.size(); ++i)
	{
		if (input[i] == '(')
		{
			++count;
		}
		else
		{
			--count;

			if (i > 0 && input[i - 1] == '(')
			{
				result += count;
			}
			else
			{
				++result;
			}
		}
	}

	cout << result;
}