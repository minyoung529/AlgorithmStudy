#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	getline(cin, s);

	for (int i = 0; i < s.size(); i++)
	{
		s.push_back(s.front());
		s.erase(s.begin());

		cout << s << endl;
	}
}