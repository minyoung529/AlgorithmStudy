#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int len, curOil = 0;
	signed long long cost = 0;
	vector<int> distances;
	vector<int> costs;

	distances.resize(100000);
	costs.resize(100000);

	cin >> len;

	for (int i = 0; i < len - 1; i++)
		cin >> distances[i];

	for (int i = 0; i < len; i++)
		cin >> costs[i];

	for (int i = 0; i < len - 1; i++)
	{
		int buyCount = 0;

		// 당장 기름이 없으면 다음 거리까지 충전
		while (curOil + buyCount < distances[i])
			buyCount++;

		// 기름이 있었다면
		if (buyCount != 0)
		{
			for (int j = i + 1; j < len - 1; j++)
			{
				// 가장 금액이 적은 주유소가 나올 때까지
				// Nkm 충전
				if (costs[i] <= costs[j])
					buyCount += distances[j];
				
				else
					break;
			}
		}

		cost += ((unsigned long long)costs[i] * buyCount);
		curOil += buyCount;
		curOil -= distances[i];
	}

	cout << cost;
}