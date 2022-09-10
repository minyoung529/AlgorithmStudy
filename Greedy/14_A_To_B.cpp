#include<iostream>
#include<queue>
using namespace std;

#define LIMIT	500000000
int a, b;
bool check[LIMIT];
queue<pair<long long int, int>> numbers;

bool Correct(long long int value, int count);

int main()
{
	cin >> a >> b;

	numbers.push({ a, 1 });

	while (!numbers.empty())
	{
		if (numbers.empty()) break;

		pair<long long int, int> val = numbers.front();
		int level = val.second + 1;

		// queue�� ������ �ϴ� ����
		// �̹� �־��� �� �ƴϰ�, b���� ũ�� ���� �� ����
		// b�� ���� �� Ƚ�� ��ȯ�ؼ� �ݺ��� ����
		if (Correct(val.first * 10 + 1, level) || Correct(val.first * 2, level))
		{
			cout << level;
			return 0;
		}

		numbers.pop();
	}

	cout << -1;
}

bool Correct(long long int value, int level)
{
	// value�� b�� ���ٸ� true ��ȯ
	if (value == b)
		return true;

	// ũ�ٸ� queue�� ���� ����
	if (value > b)
		return false;

	// Ž������ ���� value�̸� queue�� ����
	if (value >= LIMIT || check[value] != true)
		numbers.push({ value, level });

	// Ž�� �Ϸ�
	if (value < LIMIT)
		check[value] = true;

	return false;
}