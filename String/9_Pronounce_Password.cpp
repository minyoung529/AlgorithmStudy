#include<iostream>
#include<set>
using namespace std;

int main()
{
	while (true)
	{
		string s;
		int alphabets[26], consonant = 0, vowel = 0;
		bool fail = false, hasVowel = false;
		cin >> s;

		if (s == "end") break;

		// 초기화
		for (int i = 0; i < 26; i++)
			alphabets[i] = -1;

		for (int i = 0; i < s.size(); i++)
		{
			int idx = s[i] - 'a';

			// 연속되는 게 있고 e나 o가 아니라면
			if (alphabets[idx] != -1 && i - alphabets[idx] == 1)
			{
				if (!(s[i] == 'e' || s[i] == 'o'))
				{
					fail = true;
				}
			}

			// 모음이라면
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
			{
				consonant++;
				vowel = 0;
				hasVowel = true;
			}
			else
			{
				vowel++;
				consonant = 0;
			}

			if (vowel >= 3 || consonant >= 3)
			{
				fail = true;
			}

			alphabets[idx] = i;
		}

		// 미리 실패이거나 모음이 하나라도 없다면
		if (fail || !hasVowel)
		{
			cout << "<" << s << "> is not acceptable." << endl;
		}
		else
		{
			cout << "<" << s << "> is acceptable." << endl;
		}
	}
}