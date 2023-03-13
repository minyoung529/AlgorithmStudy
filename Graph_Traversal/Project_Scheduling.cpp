#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

int parents[260];
vector<int> child[260];
int minVals[260];
int weight[260];
int res = 0;

int main()
{
	while (true)
	{
		string str;
		getline(cin, str);

		if (cin.eof()) break;

		int character = str[0] - 'A';
		int w = 0, weightCnt = 0;

		for (int i = 2; i < str.size(); i++)
		{
			if (!isdigit(str[i]))break;
			w = w * 10 + (str[i] - '0');
			weightCnt++;
		}

		weight[character] = minVals[character] = w;

		for (int i = 3 + weightCnt; i < str.size(); i++)
		{
			if (isalpha(str[i]))
			{
				parents[character]++;
				child[str[i] - 'A'].push_back(character);
			}
		}
	}

	queue<int> q;

	for (int i = 0; i < 26; i++)
	{
		if (parents[i] == 0)
			q.push(i);
	}

	while (!q.empty())
	{
		int top = q.front();
		q.pop();

		for (int i : child[top])
		{
			if (--parents[i] == 0)
				q.push(i);

			minVals[i] = max(minVals[i], minVals[top] + weight[i]);
			res = max(minVals[i], res);
		}

		res = max(minVals[top], res);
	}

	cout << res;
}