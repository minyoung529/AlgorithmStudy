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

	// 센서 오름차순 정렬
	sort(sensors.begin(), sensors.end());

	// 센서보다 집중국의 개수가 더 많다면
	// 0으로 처리 (거리 차이가 나지 않게 되므로)
	if (count >= sensors.size())
	{
		cout << 0;
		return 0;
	}

	// 각 센서의 거리의 차와 인덱스를 넣어준다
	for (int i = 0; i < sensors.size() - 1; i++)
		diffs.push_back({ sensors[i + 1] - sensors[i], i });

	if (!diffs.empty())
	{
		// 차를 기준으로 오름차순 정렬
		sort(diffs.begin(), diffs.end(), [](auto a, auto b) {return a.diff > b.diff; });

		// (집중국 위치 - 1)개만 남기고 모두 지운다.
		diffs.erase(diffs.begin() + count - 1, diffs.end());

		// 인덱스 순으로 오름차순 정렬
		sort(diffs.begin(), diffs.end(), [](auto a, auto b) {return a.index < b.index; });
	}

	// 마지막 인덱스를 넣어 모든 센서가 수신 영역에 들어가게
	diffs.push_back({ 0, len - 1 });

	for (int i = 0; i < count; i++)
	{
		// 묶여진 거리의 합과 차를 구한다.
		int curIndex = diffs[i].index;
		answer += (long long int)sensors[curIndex] - sensors[start];
		start = curIndex + 1;
	}

	cout << answer;
}