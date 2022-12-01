#include<iostream>
#include<queue>
using namespace std;
#define MAX 500000

int n, input, arr[MAX + 1];
bool grade[MAX + 1];
unsigned long long result = 0;

int main()
{
	queue<int> remain;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> input;
		arr[input]++;
	}

	for (int i = 1; i <= MAX; i++)
	{
		if (arr[i])	// ������ == ������
		{
			grade[i] = true;		// ��� �������� ǥ��
			if (i > n) arr[i]++;	// ������ > �ο������ ���� ���� ��� �迭�� N�� ����

			// �׷��� �ʴٸ� N-1 ����
			// -1? => �ϳ��� �̹� ����� ������
			while (--arr[i]) remain.push(i);	
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (!grade[i])	// ����� ���������� �ʴٸ�
		{
			// ������������ ��� ����
			result += abs(remain.front() - i);
			remain.pop();
		}
	}

	cout << result;
}