#include<iostream>
using namespace std;

int arr[500000];

int main()
{
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	int len, x, coprimeCount = 0;
	long long sum = 0;

	cin >> len;

	for (int i = 0; i < len; i++)
		cin >> arr[i];

	cin >> x;

	for (int i = 0; i < len; i++)
	{
		int a = arr[i];
		int b = x;

		if (a > b) swap(a, b);

		// 최대공약수를 유클리드 호제법으로 구함
		while (b != 0)
		{
			int temp = a % b;
			a = b;
			b = temp;
		}

		// 두 수의 최대 공약수가 1이라면
		if (a == 1)
		{
			coprimeCount++;
			sum += arr[i];
		}
	}

	// 평균 출력
	cout << sum / (double)coprimeCount;
}