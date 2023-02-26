#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int>  childs[1001];
int parents[1001] = { 0, };
int res[1000];

queue<int> topology;

int main()
{
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int vCnt, tCnt, lCnt, input = 0, prevInput = -1;
	cin >> vCnt >> tCnt;

	for (int i = 0; i < tCnt; i++)
	{
		cin >> lCnt;
		prevInput = -1;

		while (lCnt--)
		{
			cin >> input;

			if (prevInput != -1)
			{
				childs[prevInput].push_back(input);
				parents[input]++;
			}

			prevInput = input;
		}
	}

	// 진입이 0인 아이들 넣기
	for (int i = 1; i <= vCnt; i++)
	{
		if (parents[i] == 0)
			topology.push(i);
	}

	for (int i = 0; i < vCnt; i++)
	{
		if (topology.empty())
		{
			cout << 0;
			return 0;
		}

		int top = topology.front();
		topology.pop();

		for (int j = 0; j < childs[top].size(); j++)
		{
			if (--parents[childs[top][j]] == 0)
			{
				topology.push(childs[top][j]);
			}
		}

		res[i] = top;
	}

	if (!topology.empty())
	{
		cout << 0;
	}
	else
	{
		for (int i = 0; i < vCnt; i++)
		{
			cout << res[i] << '\n';
		}
	}
}