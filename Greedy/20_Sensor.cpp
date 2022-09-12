#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct diff
{
	int diff, index;
};

vector<int> sensors;
vector<struct diff> diffs;

int main()
{
	int len, count, start = 0;
	long long int answer = 0;
	cin >> len >> count;

	sensors.resize(len);

	for (int i = 0; i < len; i++)
		cin >> sensors[i];

	// ���� �������� ����
	sort(sensors.begin(), sensors.end());

	// �������� ���߱��� ������ �� ���ٸ�
	// 0���� ó�� (�Ÿ� ���̰� ���� �ʰ� �ǹǷ�)
	if (count >= sensors.size())
	{
		cout << 0;
		return 0;
	}

	// �� ������ �Ÿ��� ���� �ε����� �־��ش�
	for (int i = 0; i < sensors.size() - 1; i++)
		diffs.push_back({ sensors[i + 1] - sensors[i], i });

	if (!diffs.empty())
	{
		// ���� �������� �������� ����
		sort(diffs.begin(), diffs.end(), [](auto a, auto b) {return a.diff > b.diff; });

		// (���߱� ��ġ - 1)���� ����� ��� �����.
		diffs.erase(diffs.begin() + count - 1, diffs.end());

		// �ε��� ������ �������� ����
		sort(diffs.begin(), diffs.end(), [](auto a, auto b) {return a.index < b.index; });
	}

	// ������ �ε����� �־� ��� ������ ���� ������ ����
	diffs.push_back({ 0, len - 1 });

	for (int i = 0; i < count; i++)
	{
		// ������ �Ÿ��� �հ� ���� ���Ѵ�.
		int curIndex = diffs[i].index;
		answer += (long long int)sensors[curIndex] - sensors[start];
		start = curIndex + 1;
	}

	cout << answer;
}