#include <string>
#include <vector>

using namespace std;

string solution(string s)
{
	bool iscontinue = false;

	for (int i = 0; i < s.size(); i++)
	{
		if (!iscontinue)	// ���ĺ� ������ �ƴϸ�
		{
			s[i] = toupper(s[i]);	// �빮��
			iscontinue = true;		// ���� ó��
		}
		else
		{
			s[i] = tolower(s[i]);	// �����̸� �ҹ���
		}

		//	������ ������ ������ ������ 
		if (s[i] == ' ')
			iscontinue = false;
	}

	return s;
}