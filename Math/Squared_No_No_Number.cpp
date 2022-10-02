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

	// �����佺�׳׽��� ü
	// �Ҽ� ���ϱ�
	for (ll i = 2; i <= sqrt(max); i++)
	{
		if (!check[i])
		{
			// �Ҽ��� ������ �ִ´�
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
		// start�� ���� ������ v[i]�� ����� ������ ����
		ll start = min + v[i] - (min % v[i]);

		if (start - v[i] >= min)
			start -= v[i];

		// v[i]�� ����� ��� �ɷ���
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