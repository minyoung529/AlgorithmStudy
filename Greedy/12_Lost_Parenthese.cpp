#include <iostream>
using namespace std;

int main()
{
	string formula;
	int num = 0, answer = 0;
	bool isMinus = false;

	cin >> formula;

	for (int i = 0; i < formula.size(); i++)
	{
		if (isdigit(formula[i]))
		{
			num *= 10;
			num += formula[i] - '0';
		}
		else
		{
			// '-'가 한 번도 나온 적 없다면 그냥 연산값 더함
			if (!isMinus)
				answer += num;

			// 나온 적 있다면 괄호로 묶이기 때문에
			// 무엇이든지 빼줌
			else
				answer -= num;

			if (!isMinus && formula[i] == '-')
				isMinus = true;

			num = 0;
		}
	}

	if (isMinus) num *= -1;
	answer += num;

	cout << answer;
}