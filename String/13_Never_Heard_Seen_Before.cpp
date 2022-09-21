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

	// 듣도 보도 못한 사람을 맵에 key로 넣어준다
	while (heardCnt--)
	{
		cin >> input;
		people.insert({ input, false });
	}

	while (seenCnt--)
	{
		cin >> input;

		// 듣도 보도 못한 사람이었으면
		if (people.find(input) != people.end())
		{
			// value값을 true로
			people[input] = true;
			answer++;
		}
	}

	// 듣보잡 수 출력
	cout << answer << '\n';

	for (auto pair : people)
	{
		// value값이 true인 요소들만 사전순으로 출력한다
		if (pair.second)
		{
			cout << pair.first << '\n';
		}
	}
}