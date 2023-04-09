#include<iostream>
#include<vector>
#include<math.h>
#include<string>
#include<algorithm>
#include<map>
using namespace std;

vector<int> arr;
map<int, int> m;
int maxCount = 0;

int main()
{
	long long len, sum = 0;
	cin >> len;
	arr.resize(len);

	for (int i = 0; i < len; i++)
	{
		cin >> arr[i];
		sum += arr[i];

		if (maxCount < ++m[arr[i]])
		{
			maxCount = m[arr[i]];
		}
	}

	vector<int> counts;
	for (auto& pair : m)
	{
		if (pair.second == maxCount)
			counts.push_back(pair.first);
	}

	sort(arr.begin(), arr.end());
	sort(counts.begin(), counts.end());

	cout << llround(sum / (float)len) << endl;
	cout << arr[len / 2] << endl;

	if (counts.size() >= 2)
	{
		cout << counts[1] << endl;
	}
	else
	{
		cout << counts[0] << endl;
	}

	cout << arr[len - 1] - arr[0];
}