#include<iostream>
#include<vector>
using namespace std;

vector<long long> vec;
long long error = 2000000001;
pair<long long, long long> ans;

int cmp(int idx, int cmp1, int cmp2)
{
	long long error1 = 2000000001, error2 = 2000000001;

	if (cmp1 < 0)
		return cmp2;
	if (cmp2 >= vec.size())
		return cmp1;

	error1 = abs(vec[idx] + vec[cmp1]);
	error2 = abs(vec[idx] + vec[cmp2]);

	if (error1 > error2)
		return cmp2;

	return cmp1;
}

int main()
{
	int n;
	cin >> n;
	vec.resize(n);

	for (int i = 0; i < n; i++)
		cin >> vec[i];

	for (int i = 0; i < n; i++)
	{
		int idx = lower_bound(vec.begin(), vec.end(), -vec[i]) - vec.begin();

		if (idx >= vec.size())--idx;

		if (idx == i)
			idx = cmp(i, idx - 1, idx + 1);
		
		else if (idx != 0 && idx - 1 != i)
			idx = cmp(i, idx - 1, idx);

		int curError = abs(vec[i] + vec[idx]);

		if (curError < error)
		{
			ans.first = vec[idx];
			ans.second = vec[i];
			error = curError;
		}
	}

	if (ans.first > ans.second)
		swap(ans.first, ans.second);

	cout << ans.first << ' ' << ans.second;
}