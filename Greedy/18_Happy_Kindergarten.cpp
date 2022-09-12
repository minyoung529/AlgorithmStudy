#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct diff
{
	int index;
	int diff;
};

typedef long long int lli;

int arr[300000];
vector<struct diff> diff;

int main()
{
	int len, group, startIdx = 0;
	long long int answer = 0;
	cin >> len >> group;

	for (int i = 0; i < len; i++)
		cin >> arr[i];

	// 숫자 사이의 차(구조체)를 모두 배열에 넣어준다
	for (int i = 0; i < len - 1; i++)
		diff.push_back({ i, arr[i + 1] - arr[i] });

	if (!diff.empty())
	{
		// 차를 내림차순으로 정렬한다
		sort(diff.begin(), diff.end(), [](auto a, auto b) {return (a.diff > b.diff); });

		// 쓸 부분 말고 제거
		if (len != group)
			diff.erase(diff.begin() + group - 1, diff.end());

		// 정렬한 차이를 인덱스 순으로 오름차순 정렬한다
		sort(diff.begin(), diff.end(), [](auto a, auto b) {return (a.index < b.index); });
	}

	// 마지막 인덱스도 넣어준다.
	// 반복문 계산을 위해
	diff.push_back({ len - 1,0 });

	for (int i = 0; i < diff.size(); i++)
	{
		// 0부터 a1, a1+1부터 a2, a2+1부터 a3...
		// 그룹으로 묶어 최댓값과 최솟값의 합을 저장한다.
		answer += (lli)arr[diff[i].index] - arr[startIdx];
		startIdx = diff[i].index + 1;
	}

	cout << answer;
}