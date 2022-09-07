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

	// 내림차순 정렬  
	sort(weights.begin(), weights.end(), greater<int>());

	for (int i = 0; i < weights.size(); i++)
	{
		// 버티는 최대 무게는 (무게/개수) =>
		// (i+1)개를 드는 것이므로
		// 버틸 수 있는 최대 무게 = (최대무게*(i+1)) 
		int value = weights[i] * (i + 1);

		if (value > result)
		{
			result = value;
		}
	}

	cout << result;
}
