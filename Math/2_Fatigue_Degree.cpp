#include<iostream>
using namespace std;

int main()
{
	int fatigue;
	int work;
	int reduce;
	int burnout;

	int result = 0;
	int curFatigue = 0;

	cin >> fatigue >> work >> reduce >> burnout;

	for (int i = 0; i < 24; i++)
	{
		if (curFatigue + fatigue <= burnout)
		{
			// ���ϱ�
			curFatigue += fatigue;
			result += work;

		}
		else
		{
			// ����
			curFatigue -= reduce;
			if (curFatigue < 0)
				curFatigue = 0;
		}
	}

	cout << result;
}