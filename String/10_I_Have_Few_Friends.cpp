#include<iostream>
using namespace std;

int main()
{
	string str, target;
	int sameIndex = 0, sameCnt = 0;
	cin >> str >> target;

	for (int i = 0; i < str.size(); i++)
	{
		// 알파벳이 아니면 모두 제거
		if (!isalpha(str[i]))
		{
			str.erase(str.begin() + i--);
		}
	}

	for (int i = 0; i < str.size(); i++)
	{
		for (int j = i; j < str.size(); j++)
		{
			// target은 0부터 시작하기 때문에 idx => j - i
			if (str[j] == target[j - i])
			{
				// 같은 문자의 개수가 target의 문자 개수라면
				// 성공!
				if (++sameCnt == target.size())
				{
					break;
				}
			}
			else break;
		}

		if (sameCnt == target.size()) break;
	}

	cout << (sameCnt == target.size());
}