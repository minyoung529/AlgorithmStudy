#include<iostream>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int len;
	vector<pair<int, int>> vec;

	cin >> len;
	vec.resize(len);

	for (int i = 0; i < len; i++)
	{
		cin >> vec[i].second;	// x
		cin >> vec[i].first;	// y
	}

	// pair�� �ڵ����� first > second ������ ����
	sort(vec.begin(), vec.end());

	for (int i = 0; i < len; i++)
	{
		cout << vec[i].second << ' ' << vec[i].first << '\n';
	}
}