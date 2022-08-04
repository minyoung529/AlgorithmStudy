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
		// 일했을 때 피로도가 번아웃 지수보다 같거나 작다면
		if (curFatigue + fatigue <= burnout)
		{
			// 일한다
			curFatigue += fatigue;
			result += work;

		}
		else
		{
			// 휴식한다
			curFatigue -= reduce;
			if (curFatigue < 0) curFatigue = 0;
		}
	}

	cout << result;
}
