#include<iostream>
using namespace std;

int main()
{
	int rock;
	bool isSk = false;
	cin >> rock;

	while (rock > 0)
	{
		// 마지막 돌이거나
		// 내가 3개를 가져갔을 때, 상대에게 기회가 오거나
		// 돌이 3개 이하일 때
		if (rock - 1 == 0 || rock - 4 == 0 || rock - 6 == 0 || rock < 3)
			rock -= 1;
		else
			rock -= 3;

		isSk = !isSk;
	}

	(isSk) ? cout << "SK" : cout << "CY";
}