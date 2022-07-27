#include<iostream>
#include<string>
#include<map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	string input;
	int count = 0;
	map<string, int> trees;

	while (getline(cin, input))
	{
		if (input == "end")break;
		if (trees.find(input) != trees.end())
		{
			trees[input]++;
		}
		else
		{
			trees[input] = 1;
		}

		count++;
	}

	cout << fixed;
	cout.precision(4);

	for (auto it = trees.begin(); it != trees.end(); it++)
	{
		cout << it->first << " " << (it->second / (float)count) * 100 << '\n';
	}
}