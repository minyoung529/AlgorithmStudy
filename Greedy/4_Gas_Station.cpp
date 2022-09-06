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

		// ���� �⸧�� ������ ���� �Ÿ����� ����
		while (curOil + buyCount < distances[i])
			buyCount++;

		// �⸧�� �־��ٸ�
		if (buyCount != 0)
		{
			for (int j = i + 1; j < len - 1; j++)
			{
				// ���� �ݾ��� ���� �����Ұ� ���� ������
				// Nkm ����
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