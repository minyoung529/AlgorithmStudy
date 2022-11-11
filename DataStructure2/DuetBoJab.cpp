#include<set>
#include<unordered_set>
#include<iostream>
using namespace std;

int main()
{
	unordered_set<string> say;
	set<string> saysee;
	string str;

	int sayCnt, seeCnt;
	cin >> sayCnt >> seeCnt;

	for (int i = 0; i < sayCnt; i++)
	{
		cin >> str;
		say.insert(str);
	}

	for (int i = 0; i < sayCnt; i++)
	{
		cin >> str;

		if (say.find(str) != say.end())
		{
			saysee.insert(str);
		}
	}

	cout << saysee.size() << '\n';

	for (string s : saysee)
	{
		cout << s << '\n';
	}
}