#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<string> strs;

//str2가 커야 오름차순
bool cmp(string str1, string str2)
{
	bool isGreater = true;

	for (int i = 0; i < str2.size(); i++)
	{
		if (i >= str1.size()) break;

		char temp1 = tolower(str1[i]);
		char temp2 = tolower(str2[i]);

		if (str1[i] != str2[i] && temp1 == temp2)
		{
			return isupper(str1[i]);
		}

		else if (!(isdigit(str1[i]) && isdigit(str2[i])) && str1[i] != str2[i])
		{
			if(isdigit(str1[i]) || isdigit(str2[i]))
				return isdigit(str1[i]);

			return str1[i] < str2[i];
		}
	}

	return isGreater;
}

int main()
{
	int len;

	cin >> len;
	strs.resize(len);

	for (int i = 0; i < len; i++)
	{
		cin >> strs[i];
	}

	sort(strs.begin(), strs.end(), cmp);

	cout << "- - - - - - - - - - - - - " << endl;

	for (string s : strs)
	{
		cout << s << '\n';
	}
}