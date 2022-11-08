#include<bits/stdc++.h>
using namespace std;

int main()
{
	int len, answer = 0;
	string str;
	cin >> len;

	answer = len;

	for (int i = 0; i < len; i++)
	{
		unordered_map<char, int> m;
		cin >> str;

		for (int j = 0; j < str.size(); j++)
		{
			if (m.find(str[j]) != m.end() && j - m[str[j]] > 1)
			{
				answer--;
				break;
			}

			m[str[j]] = j;
		}
	}

	cout << answer;
}