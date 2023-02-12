#include<iostream>
#include<queue>
#include<string>
using namespace std;

struct node
{
	int f, s;
	string str;
};

#define MAX 100000
bool visited[100001];
int start, endV, answer = 0;

void set(int f, int s, queue<node>& q, string str = "")
{
	if (f < 0 || f > endV + 1 || visited[f]) return;

	visited[f] = true;
	str += (to_string(f)) + ' ';
	q.push({ f , s, str });
}

int main()
{
	cin >> start >> endV;

	queue<node> q;

	q.push({ start, 0, to_string(start) + ' ' });

	if (start < endV)
	{
		while (!q.empty())
		{
			node top = q.front();
			if (top.f == endV)break;
			q.pop();

			set(top.f + 1, top.s + 1, q, top.str);
			set(top.f - 1, top.s + 1, q, top.str);
			set(top.f * 2, top.s + 1, q, top.str);
		}
	}
	else
	{
		cout << start - endV << '\n';

		for (int i = start; i >= endV; i--)
			cout << i << ' ';
		return 0;
	}

	cout << q.front().s << '\n' << q.front().str;
}