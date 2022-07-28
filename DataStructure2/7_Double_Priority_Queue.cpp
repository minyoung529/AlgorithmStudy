#include<iostream>
#include<set>
#include<string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	multiset<int> set;

	int dataCount;
	int orderCount;
	string answer;

	cin >> dataCount;

	for (int i = 0; i < dataCount; i++)
	{
		cin >> orderCount;

		for (int j = 0; j < orderCount; j++)
		{
			char order;
			int value;

			cin >> order >> value;

			// ����
			if (order == 'I')
				set.insert(value);
			
			else
			{
				if (set.empty()) continue;

				// ���� ū ���� ����
				if (value == 1)
					set.erase(--set.end());
			
				else
					set.erase(set.begin());
			}
		}

		if (set.empty())
		{
			answer += "EMPTY";
		}
		else
		{
			answer += to_string(*(--set.end())) + " " + to_string(*set.begin());
		}

		answer.push_back('\n');
		set.clear();
	}

	cout << answer;
}