#include<iostream>
using namespace std;

int main()
{
	int len, answer = 0;
	int alphabets[26] = { 0, };
	cin >> len;
	answer = len;

	while (len--)
	{
		string input;
		cin >> input;

		// 초기화
		for (int i = 0; i < 26; i++)
			alphabets[i] = -1;

		for (int i = 0; i < input.size(); i++)
		{
			int alpha = input[i] - 'a';

			// 처음 나온 것이 아니고
			// 가장 최근에 있던 자리의 차가 1 이상이라면
			// 그룹이 아닌 것!
			if (alphabets[alpha] != -1 && i - alphabets[alpha] > 1)
			{
				answer--;
				break;
			}

			// 위치 저장
			alphabets[alpha] = i;
		}
	}

	cout << answer;
}