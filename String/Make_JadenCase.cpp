#include <string>
#include <vector>

using namespace std;

string solution(string s)
{
	bool iscontinue = false;

	for (int i = 0; i < s.size(); i++)
	{
		if (!iscontinue)	// 알파벳 연속이 아니면
		{
			s[i] = toupper(s[i]);	// 대문자
			iscontinue = true;		// 연속 처리
		}
		else
		{
			s[i] = tolower(s[i]);	// 연속이면 소문자
		}

		//	공백을 만나면 연속이 끊어짐 
		if (s[i] == ' ')
			iscontinue = false;
	}

	return s;
}