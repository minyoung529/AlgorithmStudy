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

	// ���� ������ ��(����ü)�� ��� �迭�� �־��ش�
	for (int i = 0; i < len - 1; i++)
		diff.push_back({ i, arr[i + 1] - arr[i] });

	if (!diff.empty())
	{
		// ���� ������������ �����Ѵ�
		sort(diff.begin(), diff.end(), [](auto a, auto b) {return (a.diff > b.diff); });

		// �� �κ� ���� ����
		if (len != group)
			diff.erase(diff.begin() + group - 1, diff.end());

		// ������ ���̸� �ε��� ������ �������� �����Ѵ�
		sort(diff.begin(), diff.end(), [](auto a, auto b) {return (a.index < b.index); });
	}

	// ������ �ε����� �־��ش�.
	// �ݺ��� ����� ����
	diff.push_back({ len - 1,0 });

	for (int i = 0; i < diff.size(); i++)
	{
		// 0���� a1, a1+1���� a2, a2+1���� a3...
		// �׷����� ���� �ִ񰪰� �ּڰ��� ���� �����Ѵ�.
		answer += (lli)arr[diff[i].index] - arr[startIdx];
		startIdx = diff[i].index + 1;
	}

	cout << answer;
}