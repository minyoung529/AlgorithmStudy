#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

vector<int> sNumbers;
int target;
int answer = 4;

void DFS(int curNum = 0, int count = 4)
{
	if (curNum == target)
	{
		answer = min(answer, 4 - count);
		return;
	}

	if (count == 0) return;

	for (int i = sNumbers.size() - 1; i >= 0; i--)
	{
		// ������ �� Ÿ���� ũ�⸦ �Ѱų�
		// count��ŭ ���� ���� ���ĵ� target�� ���� ���� ����
		// ��͸� ������ �ʴ´�!
		if (curNum + sNumbers[i] > target || curNum + sNumbers[i] * count < target)
		{
			continue;
		}

		DFS(curNum + sNumbers[i], count - 1);
	}
}

int main()
{
	cin >> target;

	// ������ ����ֱ�
	for (int i = 1; i <= sqrt(50000); i++)
	{
		if (i * i > target) break;
		sNumbers.push_back(i * i);
	}

	DFS();

	cout << answer;
}