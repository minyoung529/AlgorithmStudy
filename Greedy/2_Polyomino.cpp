#include<iostream>
using namespace std;

int main()
{
	string result;
	string input;
	int count = 0;

	cin >> input;

	for (int i = 0; i < input.size(); ++i)
	{
		if (input[i] == 'X') count++;

		if (count == 2 && ((i == input.size() - 1) || (i + 1 < input.size() && input[i + 1] == '.')))
		{
			result += "BB";
			count = 0;
		}
		else if (count == 4)
		{
			result += "AAAA";
			count = 0;
		}

		if (input[i] == '.')
		{
			if (count != 0)
			{
				cout << -1;
				return 0;
			}
			else
			{
				result.push_back('.');
			}
		}
	}

	if (count == 0)
		cout << result;
	else
		cout << -1;
}