#include<bits/stdc++.h>
using namespace std;

vector<int> vec;
string result;
int len, cnt;

bool binarysearch(int i);

int main()
{
	cin >> cnt;
	vec.resize(cnt);

	for (int i = 0; i < cnt; i++)
	{
		cin >> vec[i];
	}

	sort(vec.begin(), vec.end());
	
	cin >> len;

	for (int i = 0; i < len; i++)
	{
		int input;
		cin >> input;

		result.push_back(binarysearch(input) + '0');
	}

	for (char c : result)
		cout << c << '\n';
}

bool binarysearch(int target)
{
	int left = 0, right = cnt - 1;

	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (target < vec[mid])
		{
			right = mid - 1;
		}
		else if (target > vec[mid])
		{
			left = mid + 1;
		}
		else return true;
	}

	return false;
}