#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int count;
	int result = 0;
	vector<int> weights;

	cin >> count;

	for (int i = 0; i < count; i++)
	{
		int input;
		cin >> input;
		weights.push_back(input);
	}

	sort(weights.begin(), weights.end(), greater<int>());

	for (int i = 0; i < weights.size(); i++)
	{
		int value = weights[i] * (i + 1);

		if (value > result)
		{
			result = value;
		}
	}

	cout << result;
}