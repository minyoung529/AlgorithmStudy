#include<iostream>
using namespace std;

int main()
{
	int len, cnt = 0;
	string s;

	cin >> len;
	s.resize(len);
	cnt = len;

	for (int i = 0; i < len; i++)
	{
		cin >> s[i];
	}

	int start = 0;
	int end = len - 1;
	int charCnt = 0;

	while (cnt--)
	{
		bool isStart = true;
		int tempStart = start, tempEnd = end;

		while (tempStart < tempEnd && s[tempStart] == s[tempEnd])
		{
			tempStart++;
			tempEnd--;
		}

		if (tempStart <= tempEnd && tempStart < len && tempEnd >0)
		{
			isStart = (s[tempStart] < s[tempEnd]);
		}

		if (isStart)
			cout << s[start++];
		else
			cout << s[end--];

		if (++charCnt % 80 == 0)
		{
			charCnt = 0;
			cout << '\n';
		}
	}
}