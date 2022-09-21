#include<iostream>
#include<map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	int heardCnt, seenCnt, answer = 0;
	map<string, bool> people;
	string input;

	cin >> heardCnt >> seenCnt;

	while (heardCnt--)
	{
		cin >> input;
		people.insert({ input, false });
	}

	while (seenCnt--)
	{
		cin >> input;

		if (people.find(input) != people.end())
		{
			people[input] = true;
			answer++;
		}
	}

	cout << answer << '\n';	

	for (auto pair : people)
	{
		if (pair.second)
		{
			cout << pair.first << '\n';
		}
	}
}