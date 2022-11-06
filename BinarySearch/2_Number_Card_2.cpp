#include<bits/stdc++.h>
using namespace std;
int arr[20000001];

int main()
{
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	int cnt, input;
	cin >> cnt;

	while(cnt--)
	{
		cin >> input;
		arr[input + 10000000]++;
	}

	cin >> cnt;

	while (cnt--)
	{
		cin >> input;
		cout << arr[input + 10000000] << ' ';
	}
}