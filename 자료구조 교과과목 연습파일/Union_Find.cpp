#include<bits/stdc++.h>
using namespace std;

int parent[1001];

int Find(int a);
void Union(int a, int b);

int main()
{
	int n, m, a, b, fa, fb, j;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}

	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b;
		Union(a, b);
	}

	cin >> a >> b;

	fa = Find(a);
	fb = Find(b);

	if (fa == fb) cout << "YES";
	else cout << "NO";
}

int Find(int a)
{
	while (parent[a] != a)
	{
		a = parent[a];
	}

	return a;
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a != b) parent[a] = b;
}