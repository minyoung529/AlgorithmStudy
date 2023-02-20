#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct carrot
{
	unsigned long long w, p;

	bool operator < (const carrot& c) const
	{
		return p < c.p;
	}
};

vector<carrot> carrots;

int main()
{
	int len;
	long long int tCnt, res = 0;
	cin >> len >> tCnt;
	carrots.resize(len);

	for (int i = 0; i < len; i++)
	{
		cin >> carrots[i].w >> carrots[i].p;
	}

	sort(carrots.begin(), carrots.end());

	for (int i = 0; i < carrots.size(); i++)
	{
		res += carrots[i].w + carrots[i].p * (tCnt - len + i);
	}

	cout << res;
}