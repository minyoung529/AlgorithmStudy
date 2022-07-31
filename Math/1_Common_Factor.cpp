#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cout.tie(NULL);
	
	int n, a, b, c = 0;
	
	cin >> n;
	cin >> a >> b;
	if (n > 2) cin >> c;

	if (b > a) swap(a, b);
	if (c != 0 && b > c) swap(b, c);

	for (int i = 1; i <= b; i++)
	{
		if (a % i == 0 && b % i == 0 && ((c == 0 ) || (c % i == 0)))
		{
			cout << i << '\n';
		}
	}
}