#include<iostream>
#include<map>
using namespace std;

string iArr[100000];
map<string, int> sMap;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int len, answerLen;
	cin >> len >> answerLen;

	for (int i = 0; i < len; ++i)
	{
		string inputValue;
		cin >> inputValue;
		sMap.insert({ inputValue, i + 1 });
		iArr[i] = inputValue;
	}

	for (int i = 0; i < answerLen; ++i)
	{
		string inputValue;
		cin >> inputValue;

		if (isdigit(inputValue[0]))
		{
			cout << iArr[atoi(&inputValue[0]) - 1] << '\n';
		}
		else
		{
			cout << sMap[inputValue] << '\n';
		}
	}
}