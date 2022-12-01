#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
	unordered_map<string, int> map;
	int len;
	string str;

	cin >> len;

	for (int i = 0; i < len; i++)
	{
		cin >> str;
		map[str]++;
	}

	for (int i = 0; i < len - 1; i++)
	{
		cin >> str;
		map[str]--;

		if (map[str] == 0)
		{
			map.erase(str);
		}
	}

	cout << (*map.begin()).first;
}