#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

stack<pair<int, int>> stk;

int main()
{
	int len;
	int max = 0;
	cin >> len;

	for (int i = 0; i < len; ++i)
	{
		int value;
		scanf("%d", &value);

		if (value > max)
		{
			printf("0 ");
			max = value;
		}
		else
		{
			while (!stk.empty() && stk.top().second < value)
			{
				stk.pop();
			}

			printf("%d ", stk.top().first);
		}

		stk.push(make_pair(i + 1, value));
	}
}