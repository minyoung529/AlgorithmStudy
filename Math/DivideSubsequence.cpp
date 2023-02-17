#include<iostream>
using namespace std;

int arr[50001];
unsigned long long sums[50001];
unsigned long long divi[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int tCnt;
	cin >> tCnt;

	while (tCnt--)
	{
		long long  d, len, sum = 0, res = 0;
		cin >> d >> len;

		for (int i = 0; i < 1000000; i++)
			divi[i] = 0;

		// Prefix Sum
		for (int i = 0; i < len; i++)
		{
			cin >> arr[i];
			sum += arr[i];
			sums[i] = (sum % d);
			divi[sums[i]]++;
		}

		res += divi[0];

		for (int i = 0; i < d; i++)
		{
			res += divi[i] * (divi[i] - 1) / 2;
		}

		cout << res << '\n';
	}
}