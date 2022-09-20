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

		// �ʱ�ȭ
		for (int i = 0; i < 26; i++)
			alphabets[i] = -1;

		for (int i = 0; i < s.size(); i++)
		{
			int idx = s[i] - 'a';

			// ���ӵǴ� �� �ְ� e�� o�� �ƴ϶��
			if (alphabets[idx] != -1 && i - alphabets[idx] == 1)
			{
				if (!(s[i] == 'e' || s[i] == 'o'))
				{
					fail = true;
				}
			}

			// �����̶��
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

		// �̸� �����̰ų� ������ �ϳ��� ���ٸ�
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