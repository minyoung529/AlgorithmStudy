#include<iostream>
#include<queue>
using namespace std;

int main()
{
	int tCnt;
	cin >> tCnt;

	while (tCnt--)
	{
		string str;
		queue<int> alphabets[26];
		int result1 = 10001, result2 = -1, num;
		cin >> str >> num;

		for (int i = 0; i < str.size(); i++)
		{
			int idx = str[i] - 'a';

			alphabets[idx].push(i);

			if (alphabets[idx].size() == num)
			{
				int dist = i - alphabets[idx].front() + 1;

				result1 = min(dist, result1);
				result2 = max(dist, result2);

				alphabets[idx].pop();
			}
		}

		if (result2 < 0)
			cout << -1 << '\n';

		else
			cout << result1 << ' ' << result2 << '\n';
	}
}