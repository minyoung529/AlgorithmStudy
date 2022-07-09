#include<iostream>
#include<stack>
using namespace std;

int main()
{
	int len;
	stack<int> numbers;
	string result = "";
	int curNum = 1;

	cin >> len;

	for (int i = 0; i < len; ++i)
	{
		int value;
		cin >> value;

		while (curNum <= value)
		{
			numbers.push(curNum++);
			result.push_back('+');
		}

		if (value == numbers.top())
		{
			numbers.pop();
			result.push_back('-');
		}

		else
		{
			cout << "NO";
			return 0;
		}
	}
	
	for (char c : result) cout << c << '\n';
}