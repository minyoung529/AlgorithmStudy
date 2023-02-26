#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
#define MAX 4000000

bool isNormalNum[MAX + 1];
vector<int> primeNum;
vector<long long int> sums;

int main()
{
	int n, res = 0;
	cin >> n;

	// 에라토스테네스
	for (int i = 2; i <= sqrt(MAX); i++)
	{
		if (isNormalNum[i])continue;

		for (int j = i * 2; j <= MAX; j += i)
		{
			isNormalNum[j] = true;
		}
	}
	long long int sum = 0;

	// 누적합 구하기
	sums.push_back(0);
	for (int i = 2; i <= MAX; i++)
	{
		if (!isNormalNum[i])
		{
			primeNum.push_back(i);
			sum += i;
			sums.push_back(sum);
		}
	}

	for (int i = 0; i < sums.size(); i++)
	{
		if (sums[i] < n) continue;

		for (int j = i; j > 0; j--)
		{
			if (sums[i] - sums[j - 1] > n)break;

			if (sums[i] - sums[j - 1] == n)
			{
				res++;
				break;
			}
		}
	}

	cout << res;
}