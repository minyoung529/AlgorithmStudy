#include<iostream>
#include<map>
#include<set>
using namespace std;

int main()
{
	string s;
	map<int, set<int>> m;
	int maxVal = 0;
	cin >> s;

	for (int i = 0; i < 9; i++)
	{
		int cnt = count(s.begin(), s.end(), '0' + i);
		maxVal = max(maxVal, cnt);
		m[cnt].insert(i);
	}

	set<int>::iterator iter = m[maxVal].end();
	cout << *(--iter);
}