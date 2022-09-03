#include<iostream>
#include<set>
#include<math.h>
#include<string.h>
using namespace std;

#define LIMIT 1000000

bool check[LIMIT + 1];
set<int> v;

void CalculateLCM(long long lcm, int index = 1);

int main()
{
	int len;

	cin >> len;

	memset(&check, true, sizeof(check));

	// 에라토스테네스의 체
	for (int i = 2; i <= sqrt(LIMIT); i++)
	{
		if (check[i])
		{
			for (int j = i * i; j <= LIMIT; j += i)
			{
				if (check[j])
				{
					check[j] = false;
				}
			}
		}
	}

	for (int i = 0; i < len; i++)
	{
		int input;
		cin >> input;

		// 소수만 배열에 넣음
		if (check[input])
		{
			v.insert(input);
		}
	}

	if (v.empty())
	{
		cout << -1;
	}
	else
	{
		CalculateLCM(*v.begin());
	}
}

void CalculateLCM(long long lcm, int index)
{
	if (index >= v.size() || v.size() == 1)
	{
		cout << lcm;
		return;
	}

	// GCD
	long long a = lcm;
	long long b = *next(v.begin(), index);

	if (a > b) swap(a, b);

	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}

	// LCM
	lcm = (*next(v.begin(), index) * lcm / a);
	CalculateLCM(lcm, ++index);
}