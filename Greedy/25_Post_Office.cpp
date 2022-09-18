#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long int lli;

int main()
{
	int len;
	lli peopleSum = 0, answer = 0;
	vector<pair<lli, lli>> dists;
	cin >> len;

	for (int i = 0; i < len; i++)
	{
		lli dist, people;
		cin >> dist >> people;

		peopleSum += people;
		dists.push_back({ dist, people });
	}

	sort(dists.begin(), dists.end());

	lli temp = 0;

	for (int i = 0; i < dists.size(); i++)
	{
		if ((temp > peopleSum / 2) || (peopleSum%2==0 && temp >= peopleSum / 2)) break;

		temp += dists[i].second;
		answer = dists[i].first;
	}

	cout << answer;
}