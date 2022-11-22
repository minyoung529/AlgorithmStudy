#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	int len, input;
	vector<int> vec;
	cin >> len;

	for (int i = 0; i < len; i++)
	{
		cin >> input;
		vec.push_back(input);
	}

	sort(vec.begin(), vec.end());
	cin >> len;

	for (int i = 0; i < len; i++)
	{
		cin >> input;
		cout << upper_bound(vec.begin(), vec.end(), input) - lower_bound(vec.begin(), vec.end(), input) << ' ';
	}
}