#include<iostream>
#include<set>
using namespace std;

int main()
{
	int len, input;
	set<int> s;
	cin >> len;

	for (int i = 0; i < len; i++)
	{
		cin >> input;
		s.insert(input);
	}

	set<int>::iterator iter = s.end();

	cout << *(--iter) - *s.begin();
}