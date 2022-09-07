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

		// X가 2개이고
		// 마지막 반복이거나
		// 다음 문자가 '.'일 때 BB
		if (count == 2 && ((i == input.size() - 1) || (i + 1 < input.size() && input[i + 1] == '.')))
		{
			result += "BB";
			count = 0;
		}
		// 그렇지 않고 X의 개수가 4일 때 
		else if (count == 4)
		{
			result += "AAAA";
			count = 0;
		}

		if (input[i] == '.')
		{
			// 바뀌지 못한 X가 있 으므로 실패 
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
		
	// 바뀌지 못한 X가 있으므로  실패 
	else
		cout << -1;
}
