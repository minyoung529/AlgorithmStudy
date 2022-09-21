#include<iostream>
#include<map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	int heardCnt, seenCnt, answer = 0;
	map<string, bool> people;
	string input;

	cin >> heardCnt >> seenCnt;

	// �赵 ���� ���� ����� �ʿ� key�� �־��ش�
	while (heardCnt--)
	{
		cin >> input;
		people.insert({ input, false });
	}

	while (seenCnt--)
	{
		cin >> input;

		// �赵 ���� ���� ����̾�����
		if (people.find(input) != people.end())
		{
			// value���� true��
			people[input] = true;
			answer++;
		}
	}

	// �躸�� �� ���
	cout << answer << '\n';

	for (auto pair : people)
	{
		// value���� true�� ��ҵ鸸 ���������� ����Ѵ�
		if (pair.second)
		{
			cout << pair.first << '\n';
		}
	}
}