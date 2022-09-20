#include<iostream>
using namespace std;

int main()
{
	while (true)
	{
		string part, total;
		int checkIdx = 0;
		cin >> part >> total;

		if (cin.eof()) break;

		for (int i = 0; i < total.size(); i++)
		{
			// 부분 문자의 i번째와 같다면 다음 문자은 i+1번재를 검사
			if (total[i] == part[checkIdx])
			{
				checkIdx++;
			}
		}

		// 부분 문자를 모두 체크했다면 성공!
		(checkIdx == part.size()) ? cout << "Yes" << endl : cout << "No" << endl;
	}
}