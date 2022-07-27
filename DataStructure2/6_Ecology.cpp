#include<iostream>
#include<string>
#include<map>
using namespace std;

int main()
{
	int count = 0;

	ios_base::sync_with_stdio(false); 
	cout.tie(NULL); cin.tie(NULL);

	cout << fixed;
	cout.precision(4);

	string input;
	map<string, int> trees;

	while (getline(cin, input))
	{
		if (trees.find(input) != trees.end())
		{
			trees[input]++;
		}
		else
		{
			trees.insert(make_pair(input, 1));
		}

		count++;
	}


	for (pair<string, int> p : trees)
	{
		cout << p.first << " " << (p.second / (float)count) * 100 << '\n';
	}
}