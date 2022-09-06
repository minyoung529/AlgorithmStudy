#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cout.tie(NULL);  cin.tie(NULL);

	vector<int> tips;
	int len;
	long long int kanghoTip = 0;

	tips.resize(100000);
	cin >> len;

	for (int i = 0; i < len; i++)
	{
		cin >> tips[i];
	}

	sort(tips.begin(), tips.end(), greater<int>());

	for (int i = 0; i < len; i++)
	{
		int tip = tips[i] - i;

		if (tip < 0) tip = 0;
		kanghoTip += tip;
	}

	cout << kanghoTip;
}