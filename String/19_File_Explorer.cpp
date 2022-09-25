#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<string> strs;

//str2가 커야 오름차순
bool cmp(string str1, string str2)
{
	int maxSize = max(str1.size(), str2.size());

	for (int i = 0; i < maxSize; i++)
	{
		if (i >= str1.size() || i >= str2.size()) break;

		// 그냥 문자
		if ((isalpha(str1[i]) || isalpha(str2[i])) && str1[i] != str2[i])
		{
			// 문자 < 숫자
			if (isdigit(str1[i]) || isdigit(str2[i]))
			{
				return isdigit(str1[i]);
			}

			char temp1 = (isupper(str1[i])) ? str1[i] - 'A' : str1[i] - 'a';
			char temp2 = (isupper(str2[i])) ? str2[i] - 'A' : str2[i] - 'a';

			if (temp1 == temp2)
			{
				return isupper(str1[i]);
			}

			// a to z 문자 정렬
			return temp1 < temp2;
		}

		// 숫자 비교
		else if (isdigit(str1[i]) && isdigit(str2[i]))
		{
			int zCnt1 = 0, zCnt2 = 0;
			int state = 0;

			while (str1[i] == '0')
			{
				str1.erase(str1.begin() + i);
				zCnt1++;
			}
			while (str2[i] == '0')
			{
				str2.erase(str2.begin() + i);
				zCnt2++;
			}

			while (isdigit(str1[i]) || isdigit(str2[i]))
			{
				// 숫자로 끝난다면 더 긴 숫자가 더 크게
				if ((i >= str1.size() || i >= str2.size()) && str1.size() != str2.size())
				{
					return (str1.size() < str2.size());
				}

				// 자릿수가 더 큰 쪽이 더 크도록
				if (isalpha(str1[i]) || isalpha(str2[i]))
				{
					return isdigit(str2[i]);
				}

				// 숫자가 큰 쪽
				if (state == 0 && str1[i] != str2[i])
				{
					state = 1 + (str1[i] < str2[i]);
				}

				i++;
			}

			// 자릿수가 같다면 숫자가 큰 쪽
			if (state)
				return (state - 1);

			// 숫자가 같다면 0의 숫자
			if (zCnt1 != zCnt2)
				return zCnt2 > zCnt1;

			i--;
		}
	}

	return str1.size() < str2.size();
}

int main()
{
	int len;

	cin >> len;
	strs.resize(len);

	for (int i = 0; i < len; i++)
	{
		cin >> strs[i];
	}

	sort(strs.begin(), strs.end(), cmp);

	for (string s : strs)
	{
		cout << s << '\n';
	}
}