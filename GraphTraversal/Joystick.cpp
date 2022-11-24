#include <vector>
#include <iostream>
#include <algorithm>
#define DIST(x)	getdist(x, index, name.size())
using namespace std;

int answer = 400;
string name;

// �ּ� �̵��Ÿ� ���ϱ�
int getdist(int from, int to, int max)
{
	return min(abs(from - to), max - abs(from - to));
}

// diff		> A�� �ƴ� ���ڵ��� �ε����� ��Ƴ��� �迭
// index	> ���� ��ġ
// sum		> �� �̵� Ƚ��
// difidx	> ���� ��ġ�� diff vector �ε��� ��
void func(vector<int> diff, int index = 0, int sum = 0, int difidx = 0)
{
	sum += getdist(0, name[index] - 'A', 26);	// ���ĺ� ��� ���ϱ�

	if (name[index] != 'A' && !diff.empty())	// A�� �ƴϰ� (diff�� �ְ�), ������� ���� ��
	{
		diff.erase(diff.begin() + difidx);
	}

	if (diff.empty())	// ��� ����
	{
		answer = min(answer, sum); return;
	}

	// ���� �Ÿ� ���(���ư��� X) �������� ����
	sort(diff.begin(), diff.end(), [index](int a, int b)
		{ return abs(index - a) < abs(index - b); });

	func(diff, diff.front(), sum + DIST(diff.front()));					// �ִܰ��
	func(diff, diff.back(),  sum + DIST(diff.back()), diff.size() - 1);	// ������ ( ���ư��� �ִܰŸ� )
}

int solution(string n)
{
	vector<int> diff;
	name = n;

	for (int i = 0; i < n.size(); i++)
	{
		if (name[i] != 'A')
		{
			diff.push_back(i);
		}
	}

	func(diff);

	return answer;
}