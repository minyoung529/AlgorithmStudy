#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

vector<int> cranes;
vector<int> boxes;

int main()
{
	int craneCount, boxCount, time = 0;

	cin >> craneCount;
	cranes.resize(craneCount);
	for (int i = 0; i < craneCount; i++) cin >> cranes[i];

	cin >> boxCount;
	boxes.resize(boxCount);
	for (int i = 0; i < boxCount; i++) cin >> boxes[i];

	sort(cranes.begin(), cranes.end());
	sort(boxes.begin(), boxes.end());

	cranes.erase(remove_if(cranes.begin(), cranes.end(), [](int x) {return x < boxes.front(); }), cranes.end());

	if (boxes.back() > cranes.back())
	{
		cout << -1;
		return 0;
	}

	while (!boxes.empty())
	{
		// 1�� ����
		time++;

		// ũ������ ���� �� �� �ִ� �ڽ��� ���.
		for (int i = 0; i < cranes.size(); i++)
		{
			if (boxes.empty()) break;

			int diff = cranes[i] - boxes.front();
			int index = 0;

			for (int j = 1; j < boxes.size(); j++)
			{
				// �ڽ����� ���� ���� ���� ������ ���
				if (diff > cranes[i] - boxes[j] && cranes[i] - boxes[j] >= 0)
				{
					diff = cranes[i] - boxes[j];
					index = j;
				}
			}

			if (diff >= 0)
			{
				boxes.erase(boxes.begin() + index);
			}
		}
	}

	cout << time;
}