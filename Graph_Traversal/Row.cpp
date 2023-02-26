#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int>  childs[32001];
int parents[32001] = { 0, };

queue<int> topology;

int main()
{
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	int vCnt, lCnt, a, b;
	cin >> vCnt >> lCnt;

	for (int i = 0; i < lCnt; i++)
	{
		cin >> a >> b;
		childs[a].push_back(b);
		parents[b]++;
	}

	// 진입이 0인 아이들 넣기
	for (int i = 1; i <= vCnt; i++)
	{
		if (parents[i] == 0)
			topology.push(i);
	}

	while (!topology.empty())
	{
		int top = topology.front();
		topology.pop();

		for (int i = 0; i < childs[top].size(); i++)
		{
			if (--parents[childs[top][i]] == 0)
			{
				topology.push(childs[top][i]);
			}
		}

		cout << top << ' ';
	}
}