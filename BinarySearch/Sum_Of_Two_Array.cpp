#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int aarr[1001], barr[1001];
long long int asum[1001], bsum[1001];
vector<long long> bsumAll, asumAll;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	long long int t;
	long long int alen, blen, ans = 0;
	cin >> t >> alen;

	for (long long i = 1; i <= alen; i++)
	{
		cin >> aarr[i];
		asum[i] = asum[i - 1] + aarr[i];
	}

	cin >> blen;

	for (long long i = 1; i <= blen; i++)
	{
		cin >> barr[i];
		bsum[i] = bsum[i - 1] + barr[i];

		for (long long j = 1; j <= i; j++)
		{
			bsumAll.push_back(bsum[i] - bsum[j - 1]);
		}
	}

	sort(bsumAll.begin(), bsumAll.end());

	for (long long i = 1; i <= alen; i++)
	{
		for (long long j = 1; j <= i; j++)
		{
			long long target = t - (asum[i] - asum[j - 1]);	// j~i

			long long idx = lower_bound(bsumAll.begin(), bsumAll.end(), target) - bsumAll.begin();
			long long upidx = upper_bound(bsumAll.begin(), bsumAll.end(), target) - bsumAll.begin();

			if (idx >= bsumAll.size()) continue;

			ans += upidx - idx;
		}
	}

	cout << ans;
}