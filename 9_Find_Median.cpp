#include<iostream>
#include<set>
#include<string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	int testLen, len;
	multiset<int> numbers;
	string answer = "";

	cin >> testLen;

	for (int i = 0; i < testLen; ++i)
	{
		cin >> len;

		for (int j = 1; j <= len; ++j)
		{
			int input;
			cin >> input;
			numbers.insert(input);

			if (j % 2 == 1)
			{
				int median = numbers.size() / 2;
				answer += to_string(*next(numbers.begin(), median));
				answer.push_back(' ');
			}
		}

		if (len % 2 == 0)
			cout << len / 2 << '\n';
		else
			cout << len / 2 + 1 << '\n';


		for (int i = 0, cnt = 0; i < answer.length(); i++)
		{
			cout << answer[i];

			if (answer[i] == ' ') ++cnt;

			if (cnt != 0 && cnt % 10 == 0)
			{
				cnt = 0;
				cout << '\n';
			}
		}

		cout << '\n';

		answer.clear();
		numbers.clear();
	}
}