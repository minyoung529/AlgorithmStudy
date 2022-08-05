#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	string input;
	int offsetNum;
	int result = 0;

	cin >> input >> offsetNum;

	for (int i = 0; i < input.size(); i++)
	{
		int index = input.size() - i - 1;

		if (isalpha(input[index]))
		{
			result += (input[index] - 'A' + 10) * pow(offsetNum, i);
		}
		else
		{
			result += (input[index] - '0') * pow(offsetNum, i);
		}
	}

	cout << result;
}