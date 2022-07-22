#include<iostream>
#include<map>
using namespace std;

int main()
{
	int len, checkLen, result = 0;
	map<string, int> dict;

	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> len >> checkLen;

	for (int i = 0; i < len; ++i)
	{
		string input;
		cin >> input;
		dict.insert({ input,i });
	}

	for (int i = 0; i < checkLen; ++i)
	{
		string input;
		cin >> input;

		if (dict.find(input) != dict.end())
			result++;
	}

	cout << result;
}