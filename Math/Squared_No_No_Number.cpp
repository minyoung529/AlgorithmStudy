#include<bits/stdc++.h>
#define MAX 1000000
using namespace std;
typedef long long int ll;

vector<ll> v;
int check[MAX + 1];
bool answers[MAX + 1];

int main()
{
	int answer = 0;
	ll min, max;
	cin >> min >> max;

	// 에라토스테네스의 체
	// 소수 구하기
	for (ll i = 2; i <= sqrt(max); i++)
	{
		if (!check[i])
		{
			// 소수의 제곱만 넣는다
			v.push_back(i * i);

			for (ll j = (ll)i * i; j < sqrt(max); j += i)
			{
				check[j] = true;
			}
		}
	}

	answer = max - min + 1;

	for (int i = 0; i < v.size(); i++)
	{
		// start와 가장 가깝고 v[i]의 배수인 지점을 구함
		ll start = min + v[i] - (min % v[i]);

		if (start - v[i] >= min)
			start -= v[i];

		// v[i]의 배수를 모두 걸러줌
		for (ll j = start; j <= max; j += v[i])
		{
			if (!answers[j - min])
			{
				answer--;
				answers[j - min] = true;
			}
		}
	}

	cout << answer;
}